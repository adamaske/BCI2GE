
class Decoder():
    def __init__(self):
        print("Hei")
    def decode(self, data):
        print(data)
        #bytes_object = bytes.fromhex(data)
        #ascii_string = bytes_object.decode("ASCII")
        #print(ascii_string)



if __name__=='__main__':
    decoder = Decoder()
    message = "#bundle\x00\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00\x18/com/neutral\x00\x00\x00\x00,f\x00\x00\x00\x00\x00\x00"
    decoder.decode(message)