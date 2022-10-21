import socket
class Reciever():
    def __init__(self, IP, PORT, BUFFERSIZE):
        #Port and ip which is set in the bci-osc software
        self.mIP = IP
        self.mPORT = PORT
        self.recieve_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.recieve_socket.bind((self.mIP, self.mPORT))
        self.mBUFFERSIZE = BUFFERSIZE

    def receieve(self):
        return self.recieve_socket.recvfrom(2*1024*1024)