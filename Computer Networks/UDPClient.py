from socket import *

# Input UDP Server IP Address and Port
serverName = input("\nEnter Server Name: ")
serverPort = int(input("Enter Server Port: "))

# Create Clinet Socket Object
# AF_INET is Internet address family for IPv4
# SOCK_DGRAM is the socket type for UDP type transport of message
clientSocket = socket(AF_INET, SOCK_DGRAM)

# Input the message sentence string and convert it to bytes
message = input("\nEnter a sentence: ").encode()

# Send the message as the data to the socket to a listening UDP server 
# with IP Address of serverName on Port serverPort
clientSocket.sendto(message, (serverName, serverPort))

# Receive message sentence data and its Server Adress from the socket
modifiedMessage, serverAddress = clientSocket.recvfrom(2048)

# Display the output from the modified sentence from server 
# after converting it from bytes to string
print("Modified Sentence from Server: ", modifiedMessage.decode(), end = "\n\n")

# Mark the Client Socket Object as closed
clientSocket.close()