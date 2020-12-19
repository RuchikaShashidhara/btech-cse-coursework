from socket import *

# Input TCP Server IP Address and Port
serverName = input("\nEnter Server Name: ")
serverPort = int(input("Enter Server Port: "))

# Create Clinet Socket Object
# AF_INET is Internet address family for IPv4
# SOCK_STREAM is the socket type for TCP type transport of message
clientSocket = socket(AF_INET, SOCK_STREAM)

# Connect Client socket to a listening TCP server 
# with IP Address of serverName on Port serverPort
clientSocket.connect((serverName, serverPort))

# Input the message sentence string and convert it to bytes
message = input("\nEnter a sentence: ").encode()

# Send the message as the data to the socket
clientSocket.send(message)

# Recieve bytes type data from the socket
modifiedMessage = clientSocket.recv(1024)

# Display the output from the modified sentence from server 
# after converting it from bytes to string
print("Modified Sentence from Server: ", modifiedMessage.decode(), end = "\n\n")

# Mark the Client Socket Object as closed
clientSocket.close()