import pickle
import socket
import struct
import sys
from time import sleep

import cv2

try:
    HOST = sys.argv[1]
except IndexError:
    HOST = input("IPv4: ") # 192.168.1.13

try: 
    PORT = int(sys.argv[2])
except IndexError:
    PORT = int(input("PORT: "))

try: 
    cam_index = int(sys.argv[3])
except IndexError:
    cam_index = int(input("Camera index: "))

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as conn:
    conn.connect((HOST, PORT))
    print(f"Connected to {HOST} on port {PORT}...")
    vid = cv2.VideoCapture(cam_index)
    vid.set(3, 320)
    vid.set(4, 240)
    while vid.isOpened():
        img, frame = vid.read()
        #frame = imutils.resize(frame, width=320)
        a = pickle.dumps(frame)
        message = struct.pack("Q", len(a)) + a
        conn.sendall(message)
        
