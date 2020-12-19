import os
import sys
import threading
from socket import socket, AF_INET, SOCK_STREAM, error


def new_server_proxy_thread(client_connection, client_address):
    
    # Get request from browser
    request = client_connection.recv(65536)

    # Parse and Display request from browser
    request_line1 = request.decode("utf8","ignore").split("\n")[0]
    url = request_line1.split(" ")[1]
    print("Request\t\t", client_address[0], "\t", request_line1)
    
    # Find websever and port and find url
    http_part = url.find("://")
    if http_part == -1:
        temp = url
    else:
        temp = url[(http_part + 3) :]
    
    # Find port if it exists
    port_part = temp.find(":")
    
    # Fing end of webserver info
    webserver_part = temp.find("/")
    if webserver_part == -1:
        webserver_part = len(temp)
    webserver = ""
    port = -1    
    # If port is defalut port 8080
    if port_part == -1 or webserver_part < port_part:
        port = 80
        webserver = temp[:webserver_part]        
    # If port is enetered as input argument   
    else:
        port = int((temp[(port_part + 1) :])[: webserver_part - port_part - 1])
        webserver = temp[:port_part]    
    
    try:
        # Create socket to connect to webserver
        webserver_socket = socket(AF_INET, SOCK_STREAM)
        webserver_socket.connect((webserver, port))
        
        # Send same request to webserver
        webserver_socket.send(request)
        
        while 1:
            # Recieve reaponse data from browser
            response = webserver_socket.recv(65536)
            
            # Parse and Display response from browser
            response_line1 = response.decode("utf8","ignore").partition("\n")[0]
            print("Response\t", client_address[0], "\t", response_line1)
            
            # Send data to response until no new ones are available
            if len(response) > 0:
                client_connection.send(response)
            else:
                break

        # CLose webserver socket and client connection thread                
        webserver_socket.close()
        client_connection.close()
        
    # Exit from program if socket connection is not established        
    except error:
        if webserver_socket:
            webserver_socket.close()
        if client_connection:
            client_connection.close()
        print("Peer reset\t", client_address[0], "\t", request_line1)
        sys.exit(1)


# Main Driver
if __name__ == "__main__":
    
    # If port number is not mentioned as arugument, display 8080 as default port
    if len(sys.argv) < 2:
        print("\nUsing Default port 8080")
        port = 8080
    
    # Initialize port number from input argument    
    else:    
        port = int(sys.argv[1])
    
    # Display Port number on which Proxy Server is running on
    print("\nProxy server Running on :", port)
    
    # Create Proxy server socket to recieve a maximum of 50 HTTP Requests
    try:
        proxy_server_socket = socket(AF_INET, SOCK_STREAM)
        proxy_server_socket.bind(("", port))
        proxy_server_socket.listen(50)
    
    # Exit from program if socket connection is not established    
    except error:
        if proxy_server_socket:
            proxy_server_socket.close()
        print("\nCould not open socket\n")
        sys.exit(1)
    
    # Keep proxy server code running until mannual disconnection is triggered   
    while 1:
        print()
        # Enable proxy server socket to accept new connections
        client_connection, client_address = proxy_server_socket.accept()
        # Start new threads with new accepted connection, for proxy server 
        # to send requests & recieve responses
        threading._start_new_thread(new_server_proxy_thread, \
        (client_connection, client_address))
    
    # Close the proxy server socket
    proxy_server_socket.close()
    