import socket

# Create an INET, STREAMing socket
listen_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Bind the socket to a public host, and a well-known port
listen_socket.bind(('127.0.0.1', 1024))
# Become a server socket, with a backlog queue of 5 connections.
listen_socket.listen(5)

print ('Waiting for clients')

while 1:
    # Accept connections from outside. This is a blocking call.
    (client_socket, address) = listen_socket.accept()
    print ('Connected to client at' + str(address))
    print ('Sent "Hello"')
    client_socket.send('Hello'.encode())
