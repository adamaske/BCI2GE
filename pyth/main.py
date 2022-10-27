#python lib for sockets
import socket
import _thread

from Recieving import reciever
from Sending import sender

BCI_PORT = 5700
BCI_IP = "127.0.0.1"
UE_PORT = 5800
UE_IP = "127.0.0.1"
BUFFERSIZE = 1024

class BCI2GE():
    def __init__(self):
        self.setup_sending()
        self.setup_reciving()
    #Creates a sender called ue_sender with ip and ports which correspons to urneal
    def setup_sending(self):
        self.ue_sender = sender.Sender(UE_IP, 5700)
      
    #Receiver which listens to the BCI ip and port, see osc app for what these should be
    def setup_reciving(self):
        self.bci_reciever = reciever.Reciever(BCI_IP, BCI_PORT, BUFFERSIZE)
       
    def loop(self):
        data, adr = self.bci_reciever.receieve()
        print("BCI_Receiver got data ", data, " from ", adr)
        #send it to unreal
        self.ue_sender.send(data);
        #the data that was sent to unreal
        #self.ue_sender.Send(data)


if __name__=='__main__':
    app = BCI2GE()
    #This is a replecement for the osc software and sends data to the receiever
    send = sender.Sender(BCI_IP, BCI_PORT)
    
    while True:
        #Sends hei 
        #print("The fake bci sender sending now:")
        #send.send(b"Hei")
        #print("The fake is done sending!")
        #lopp for recieveing
        app.loop()
        