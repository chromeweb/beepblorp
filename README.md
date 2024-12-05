# BeepBlorp

**BeepBlorp** is a simple C++ program that retrieves either the HTML content or a PNG image from a specified URL. The program can display the HTML content directly in the console or extract and display the last 40 bytes of a PNG image as a string.

## Features
- Retrieve and display HTML content from a specified URL.
- Retrieve a PNG image from a specified URL and display the last 40 bytes of the image data as a string.

## Usage
To use the program, compile it using a C++14 compatible compiler and run it with the following command-line arguments:  
 `beepblorp.exe <url> <html|png>`

## Examples
- Retrieve and display HTML content:  
 `beepblorp.exe example.com html`

- Retrieve a PNG image and display the last 40 bytes of its data:  
 `beepblorp.exe example.com png`

# Code Overview

The program performs the following steps:

1. **Command Line Argument Parsing**:  
   Checks if the correct number of arguments are provided and assigns the URL and file type.

2. **HTTP GET Request Construction**:  
   Constructs the appropriate HTTP GET request based on the file type (`html` or `png`).

3. **Socket Initialization**:  
   Initializes Winsock and creates a socket for communication.

4. **Server Connection**:  
   Connects to the server specified by the URL.

5. **Data Transmission**:  
   Sends the HTTP GET request to the server.

6. **Data Reception**:  
   Receives the response data from the server.

7. **Data Processing**:  
   - **For HTML**: Extracts and displays the HTML content.  
   - **For PNG**: Extracts the last 40 bytes of the image data and displays it as a string.

8. **Cleanup**:  
   Closes the socket and cleans up Winsock resources.


# Legal Disclaimer

This code is provided for **educational and informational purposes only**. The author(s) make no representation, guarantee, or warranty of any kind regarding the code's accuracy, reliability, or suitability for any particular purpose. By using this code, you agree to the following:

1. **Authorized Use**: This code is intended solely for lawful, ethical, and authorized uses. Any use of this code for malicious purposes, including but not limited to unauthorized data access, exploitation, or violation of applicable laws, is strictly prohibited.

2. **No Liability**: The author(s) of this code shall not be held liable for any direct, indirect, incidental, or consequential damages arising out of its use, misuse, or inability to use the code.

3. **Responsibility of the User**: The user assumes all responsibility for ensuring that their use of this code complies with all applicable laws and regulations in their jurisdiction.

4. **No Guarantee of Security**: The author(s) do not guarantee that this code is free of vulnerabilities, bugs, or defects. Use of the code is at your own risk.

By downloading, using, or modifying this code, you acknowledge that you have read, understood, and agreed to this disclaimer. If you do not agree to these terms, you are prohibited from using this code in any capacity.
