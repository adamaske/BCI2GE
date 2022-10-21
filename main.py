#python lib for networking?
import socket

#This the first time working with udp, 
#ill make it better and with a sender and reciever class later

#While we're waiting for the software, this will act as the bci software
fake_send_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#send to unreal
def fake_setup_sending():
    print("Setup send")


#Port and ip which is set in the bci-osc software
BCI_PORT = 5000
BCI_IP = "127.0.0.1"
recieve_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
recieve_socket.bind((BCI_IP, BCI_PORT))
#to recive data from the bci-osc
def setup_reciving():
    print("Setup recieve")

#Socket for sending,  AF_INET for Ipv4, SOCK_DGRAM for UDP
UE_PORT = 5000
UE_IP = "127.0.0.1"
send_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#send to unreal
def setup_sending():
    print("Setup send")

#Size of messages recieved, standard
BUFFERSIZE = 1024

if __name__=='__main__':
    setup_reciving()
    setup_sending()

    #First i send som data
    send_socket.sendto(b"Fun", (UE_IP, UE_PORT))
    while True:
        #Here the fake bci sends to the bci port
        fake_send_socket.sendto(b"Fake data", (BCI_IP, BCI_PORT))
        #Recieve
        data, adr = recieve_socket.recvfrom(BUFFERSIZE)
        #print recived 
        print("recived message: %s" % data)
        #Handle the data recieved, unpacking the OSCBundle

        #The data is handled, so we can send it to unreal now
        send_socket.sendto(b"UE message" ,(UE_IP,UE_PORT))