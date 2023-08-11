# echo-client.py

import os
import socket

import src.GPIO_driver


def readConfig() -> dict[str, str]:
    '''returns a dict with all of the data in the config file'''
    
    # gets the file path of the python file
    __location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))
    
    # opens the config file by looking in the same directory as this file
    with open(os.path.join(__location__, 'config')) as config:
        
        # splits file by line
        L = config.read().split('\n')
        
        # remove white space, and format as a dictionary
        return {i.split(':')[0].strip(): i.split(':')[1].strip() for i in L if ':' in i}


def main():
    params = readConfig()
    
    # sets variables to their values in the config file
    TESTMODE = (params['testmode'] == 'True')
    HOST = params['laptop_ip']
    PORT = int(params['port'])
    
    # makes the server run on localhost if in testmode so it can be tested with a single machine
    if TESTMODE:
        print("\x1b[91m" + "WARNING: TESTMODE is curently active. This can be disabled in the config file" + "\x1b[0m")
        HOST = '127.0.0.1'
    
    # opens a socket which is used to communicate over the ethernet cable
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        
        # trys to connect to the server using its ip and port number.
        s.connect((HOST, PORT))
        print(f"Connected to {HOST} on port {PORT}...")
        
        # repeatedly checks for incoming data
        while True:
            try:
                data = s.recv(1024) # 1024 refers to the buffersize of the incoming data
            except:
                GPIO_driver.disable()
                s.close()
                exit()
            # if empty data packet is recieved then break while loop (end connection)
            if not data: 
                break
            
            GPIO_driver.handleInput(data.decode('UTF-8'))
            #print(f"Received message: '{data.decode('UTF-8')}'")     
            
            # decodes binary data into string using UTF-8 encoding

if __name__ == '__main__':
    main()
