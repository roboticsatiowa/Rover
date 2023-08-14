# echo-client.py

import os
import socket
import sys

from src import GPIO_driver


def main():
    
    # sets variables to their values in the config file
    try:
        HOST = sys.argv[1]
    except IndexError:
        HOST = input("IPv4: ") # 192.168.1.13

    try: 
        PORT = int(sys.argv[2])
    except IndexError:
        PORT = int(input("PORT: "))
    
    print(f"attempting to connect to {HOST} on port {PORT}...")
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
                continue
            
            GPIO_driver.handleInput(data.decode('UTF-8'))

if __name__ == '__main__':
    main()