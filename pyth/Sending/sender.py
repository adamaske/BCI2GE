import socket
class Sender():
    def __init__(self, IP, PORT):
        self.mIP = IP
        self.mPORT = PORT
        #Socket for sending,  AF_INET for Ipv4, SOCK_DGRAM for UDP
        self.send_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    def send(self, data):
        print("Sender is sending data ", data, " to ", self.mIP, " , " , self.mPORT)
        self.send_socket.sendto(data, (self.mIP, self.mPORT))