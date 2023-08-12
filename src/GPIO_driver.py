from time import sleep

import busio
from adafruit_pca9685 import PCA9685
from board import SCL, SDA

THRESHHOLD = 0.2

HIGH=65535
HALF=32767
LOW=0

WRIST_ROTATE_PUL=0
WRIST_ROTATE_DIR=1
WRIST_PUL=2
WRIST_DIR=3
RIGHT_WHEEL_PUL=4
RIGHT_WHEEL_DIR=5
LEFT_WHEEL_PUL=6
LEFT_WHEEL_DIR=7
LAZY_SUZAN_PUL=8
LAZY_SUZAN_DIR=9
HAND_PUL=10
HAND_DIR=11
DRIVE_ENABLE=12
ARM_SHOULDER=14
ARM_ELBOW=15

while True:
    try:
        i2c_bus = busio.I2C(SCL, SDA)
        pca = PCA9685(i2c_bus)
        break
    except Exception as e:
        print("failed to start i2c_bus")
        print(e)
        sleep()

pca.frequency = 1000

pca.channels[14].duty_cycle = HALF # elbow
pca.channels[15].duty_cycle = HALF # shoulder

pca.channels[4].duty_cycle = 6560
pca.channels[6].duty_cycle = 6560
pca.channels[DRIVE_ENABLE].duty_cycle = HIGH #enable pin

def map(value, istart, istop, ostart, ostop):
    return int(ostart + (ostop - ostart) * ((value - istart) / (istop - istart)))

def handleInput(input:str):
    L = input.split() #splits string input into [axis changed or not changed], [which button was changed], [the value it was changed to]
    print(L)
    if L[0] == 'AXIS_CHANGED:':
        try:
            val = float(L[2])
        except:
            return
        if L[1] == 'LY':
            if val > THRESHHOLD:
                Right_duty_cycle = map(val,0,1,6560,58980)
                pca.channels[5].duty_cycle = LOW
                pca.channels[4].duty_cycle = Right_duty_cycle
            elif val < -THRESHHOLD:
                Right_duty_cycle = map(val,0,-1,6560,58980)
                pca.channels[5].duty_cycle = HIGH
                pca.channels[4].duty_cycle = Right_duty_cycle
            else:
                pca.channels[5].duty_cycle = HIGH
                pca.channels[4].duty_cycle = 6560

        elif L[1] == 'RY':
            if val > THRESHHOLD:
                Left_duty_cycle = map(val,0,1,6560,58980)
                pca.channels[7].duty_cycle = HIGH
                pca.channels[6].duty_cycle = Left_duty_cycle
            elif val < -THRESHHOLD:
                Left_duty_cycle = map(val,0,-1,6560,58980)
                pca.channels[7].duty_cycle = LOW
                pca.channels[6].duty_cycle = Left_duty_cycle
            else:
                pca.channels[7].duty_cycle = 0
                pca.channels[6].duty_cycle = 6560

    if L[0] == 'PRESSED':
        if L[1] == 'A':
            pca.channels[14].duty_cycle = 65534
        if L[1] == 'X':
            pca.channels[14].duty_cycle = 0
        if L[1] == 'Y':
            pca.channels[15].duty_cycle = 65534
        if L[1] == 'B':
            pca.channels[15].duty_cycle = 0
    
    if L[0] == 'RELEASED':
        if L[1] == 'A':
            pca.channels[14].duty_cycle = 32767
        if L[1] == 'X':
            pca.channels[14].duty_cycle = 32767
        if L[1] == 'Y':
            pca.channels[15].duty_cycle = 33167
        if L[1] == 'B':
            pca.channels[15].duty_cycle = 32767
            
def disable():
    pca.channels[12].duty_cycle = 0
