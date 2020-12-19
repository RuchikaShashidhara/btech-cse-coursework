from socket import *

# Listening Port for socket connection
serverPort = 12000

# Create Server Socket Object
# AF_INET is Internet address family for IPv4
# SOCK_STREAM is the socket type for TCP type transport of message
serverSocket = socket(AF_INET, SOCK_STREAM)

# Bind the Server Socket to all available interfaces('') and Port ServerPort
serverSocket.bind(('',  serverPort))

# Enable server to listen with backlog parameter as 1 which is the
# number of unaccepted connections that the server will allow 
# before refusing new connections
serverSocket.listen(1)

# Display that the server is ready to recieve
print("\nThe TCP Server is ready to receive\n")

# Keep server code running until mannual disconnection is triggered
while(1):
        
        # Accept a connection with new connected socket object connectionObject
        # with address connectionAddress
        connectionSocket, connectionAddr = serverSocket.accept()
        
        # Display acknowledgement of connection
        print("Connected with address", connectionAddr[0])
        
        # Recieve bytes type data from the socket
        message = connectionSocket.recv(1024)
        
        # Display acknowledgement of data recieved
        print("Recieved data from socket connection")

        # Convert only lowercase characters into uppercase characters
        # and leave other characters unmodified
        modifiedMessage = message.upper()
        
        # Send converted sentence as data to the socket back to client
        connectionSocket.send(modifiedMessage)
        
        # Display acknowledgement of data sent
        print("Sent data to socket connection\n")
        
        # Mark the Connection Socket Object as closed
        connectionSocket.close()        