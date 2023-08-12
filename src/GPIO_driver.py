from time import sleep

import busio
from adafruit_pca9685 import PCA9685
from board import SCL, SDA

is_driving = True

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
        print("I2C DEVICE CONNECTED SUCCESFULLY")
        break
    except Exception as e:
        print("failed to start i2c_bus")
        print(e)
        sleep(5)

pca.frequency = 1000

pca.channels[ARM_SHOULDER].duty_cycle = HALF # elbow
pca.channels[ARM_ELBOW].duty_cycle = HALF # shoulder

pca.channels[4].duty_cycle = 6560
pca.channels[6].duty_cycle = 6560
pca.channels[DRIVE_ENABLE].duty_cycle = HIGH #enable pin

# Helper Function
def map(value, istart, istop, ostart, ostop):
    return int(ostart + (ostop - ostart) * ((value - istart) / (istop - istart)))

def handle_arm_input(L):
    if L[0] == 'AXIS_CHANGED:':
        try:
            val = float(L[2])
        except:
            return
        
        
        if L[1] == 'LY':
            if val > THRESHHOLD:
                pca.channels[ARM_SHOULDER].duty_cycle = HIGH
            elif val < -THRESHHOLD:
                pca.channels[ARM_SHOULDER].duty_cycle = LOW
            else:
                pca.channels[ARM_SHOULDER].duty_cycle = HALF
        
        if L[1] == 'LX':
            if val > THRESHHOLD:
                pca.channels[WRIST_DIR].duty_cycle = HIGH
                pca.channels[WRIST_PUL].duty_cycle = HIGH
            elif val < -THRESHHOLD:
                pca.channels[WRIST_DIR].duty_cycle = LOW
                pca.channels[WRIST_PUL].duty_cycle = HIGH
            else:
                pca.channels[WRIST_PUL].duty_cycle = LOW
                
        if L[1] == 'RY':
            if val > THRESHHOLD:
                pca.channels[ARM_ELBOW].duty_cycle = HIGH
            elif val < -THRESHHOLD:
                pca.channels[ARM_ELBOW].duty_cycle = LOW
            else:
                pca.channels[ARM_ELBOW].duty_cycle = HALF
        
        if L[1] == 'RX':
            if val > THRESHHOLD:
                pca.channels[WRIST_ROTATE_DIR].duty_cycle = HIGH
                pca.channels[WRIST_ROTATE_PUL].duty_cycle = HIGH
            elif val < -THRESHHOLD:
                pca.channels[WRIST_ROTATE_DIR].duty_cycle = LOW
                pca.channels[WRIST_ROTATE_PUL].duty_cycle = HIGH
            else:
                pca.channels[WRIST_ROTATE_PUL].duty_cycle = LOW
        # LX Wrist up/down
        # LY shoulder
        
        # RX wrist rotate
        # RY elbow up/down
        
        # LB/RB Lazy Suzan
        
    if L[0] == 'PRESSED':
        if L[1] == 'A':
            pca.channels[ARM_SHOULDER].duty_cycle = HIGH
        if L[1] == 'X':
            pca.channels[ARM_SHOULDER].duty_cycle = LOW
        if L[1] == 'Y':
            pca.channels[ARM_ELBOW].duty_cycle = HIGH
        if L[1] == 'B':
            pca.channels[ARM_ELBOW].duty_cycle = LOW
        if L[1] == 'LB':
            pca.channels[LAZY_SUZAN_DIR] = HIGH
            pca.channels[LAZY_SUZAN_PUL] = HALF
        if L[1] == 'RB':
            pca.channels[LAZY_SUZAN_DIR] = LOW
            pca.channels[LAZY_SUZAN_PUL] = HIGH
    
    if L[0] == 'RELEASED':
        if L[1] in ('A', 'X'):
            pca.channels[ARM_SHOULDER].duty_cycle = HALF
            
        if L[1] in ('Y', 'B'):
            pca.channels[ARM_ELBOW].duty_cycle = HALF
            
        if L[1] in ('LB', 'RB'):
            pca.channels[LAZY_SUZAN_PUL] = LOW

def handle_drive_input(L):
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


def handleInput(input:str):
    global is_driving
    L = input.split() #splits string input into [axis changed or not changed], [which button was changed], [the value it was changed to]
    print(L)
    
    if L[0] == 'PRESSED' and L[1] == 'STA':
        is_driving = not is_driving
        print("\x1b[1;34m" + "Drive mode: " + ("DRIVE" if is_driving else "ARM") + "\x1b[0m")
    
    if is_driving:
        handle_drive_input(L)
    else:
        handle_drive_input(L)
        
            
def disable():
    pca.channels[DRIVE_ENABLE].duty_cycle = LOW
