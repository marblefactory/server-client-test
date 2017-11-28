import socket

def client():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(('127.0.0.1', 1024))

    sock.sendall("Hello".encode())
    sock.sendall("Another message".encode())

    sock.close()

client()
