#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <locale>
#include <sstream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <url> <html|png>" << endl;
        return 1;
    }

    string url = argv[1];
    string fileType = argv[2];
    string get_http;

    if (fileType == "html") {
        get_http = "GET / HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";
    } else if (fileType == "png") {
        get_http = "GET /images/output.png HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";
    } else {
        cout << "Invalid file type. Use 'html' or 'png'." << endl;
        return 1;
    }

    WSADATA wsaData;
    SOCKET Socket;
    SOCKADDR_IN SockAddr;
    struct hostent* host;
    char buffer[10000];
    int nDataLength;
    string receivedData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup failed.\n";
        system("pause");
        return 1;
    }

    Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    host = gethostbyname(url.c_str());

    SockAddr.sin_port = htons(80);
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

    if (connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr)) != 0) {
        cout << "Could not connect";
        system("pause");
        return 1;
    }

    // send GET request
    send(Socket, get_http.c_str(), strlen(get_http.c_str()), 0);

    // receive data
    while ((nDataLength = recv(Socket, buffer, 10000, 0)) > 0) {
        receivedData.append(buffer, nDataLength);
    }

    closesocket(Socket);
    WSACleanup();

    if (fileType == "html") {
        // Process HTML content
        string headerEndMarker = "\r\n\r\n";
        size_t headerEndPos = receivedData.find(headerEndMarker);
        if (headerEndPos != string::npos) {
            string website_HTML = receivedData.substr(headerEndPos + headerEndMarker.length());
            // Display HTML source
            cout << website_HTML;
        }
    } else if (fileType == "png") {
        // Extract the last 40 bytes of the PNG data
        size_t dataSize = receivedData.size();
        string last40Bytes;
        if (dataSize > 40) {
            last40Bytes = receivedData.substr(dataSize - 40, 40);
        } else {
            last40Bytes = receivedData;
        }

        // Convert the last 40 bytes to a string and output it
        cout << last40Bytes << endl;
    }

    return 0;
}