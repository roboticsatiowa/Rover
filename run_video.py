import base64
import pickle
import socket
import struct
from time import sleep

import cv2
import imutils
import pyperclip

HOST = "192.168.1.13"  # The server's hostname or IP address
PORT = 55555  # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as conn:
    conn.connect((HOST, PORT))
    print(f"Connected to {HOST} on port {PORT}...")
    vid = cv2.VideoCapture(0)
    while vid.isOpened():
        img, frame = vid.read()
        frame = imutils.resize(frame, width=320)
        a = pickle.dumps(frame)
        message = struct.pack("Q", len(a)) + a
        conn.sendall(message)
