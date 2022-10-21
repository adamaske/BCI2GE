#include <iostream>

//Base class for any data recieved
class Packet{
    public:
    Packet();
};
//Bytes is the data recieved from the python program
Packet UnpackPacket(uint8_t bytes[]){
    //A function which translates the packet into OSC format

    //Returns a packet which is unpacked
    return Packet();
};

class Reciever{
    private:
    //Each receiver has a ip and a port which it listends to
    const char* mIp;
    int mPort;
    public:
    void StartReciever(){
        //Like in the python script
        //Create an adress from the ip and port
        //There is ue sepcific code for this
        //Creating a server/reciever in pure c++ seems unnecesary and quite alot more work,
        //Considering i also have to code alot for 

    };

};
void Recieve(){
    uint8_t bytes[1024]; //= server.recieved();
    Packet p = UnpackPacket(bytes);
}
int main(){


    return 0;
}
