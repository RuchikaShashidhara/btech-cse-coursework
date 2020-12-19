from socket import *

# Listening Port for socket connection
serverPort = 12000

# Create Server Socket Object
# AF_INET is Internet address family for IPv4
# SOCK_DGRAM is the socket type for UDP type transport of message
serverSocket = socket(AF_INET, SOCK_DGRAM)

# Bind the Server Socket to all available interfaces('') and Port ServerPort
serverSocket.bind(('',  serverPort))

# Display that the server is ready to recieve
print("\nThe UDP Server is ready to receive\n")

# Keep server code running until mannual disconnection is triggered
while(1):
        
        # Receive message sentence data and its Client Adress from the socket
        message, clientAddr = serverSocket.recvfrom(1024)
        
        # Display acknowledgement of data recieved
        print("Recieved data from socket connection with address",clientAddr[0])

        # Convert only lowercase characters into uppercase characters
        # and leave other characters unmodified
        modifiedMessage = message.upper()
        
        # Send converted sentence as data to the socket back to client
        serverSocket.sendto(modifiedMessage, clientAddr)
        
        # Display acknowledgement of data sent
        print("Sent data to socket connection\n")