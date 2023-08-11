from time import sleep

import busio
from adafruit_pca9685 import PCA9685
from board import SCL, SDA

while True:
    try:
        i2c_bus = busio.I2C(SCL, SDA)
        pca = PCA9685(i2c_bus)
        break
    except Exception as e:
        print("failed to start i2c_bus")
        print(e)
        sleep(1)

pca.frequency = 1000

THRESHHOLD = 0.2


pca.channels[4].duty_cycle = 6560
pca.channels[6].duty_cycle = 6560
pca.channels[12].duty_cycle = 65534 #enable pin

def map(value, istart, istop, ostart, ostop):
    return int(ostart + (ostop - ostart) * ((value - istart) / (istop - istart)))

def handleInput(input:str):
    L = input.split() #splits string input into [axis changed or not changed], [which button was changed], [the value it was changed to]
    if L[0] == 'AXIS_CHANGED:':
        try:
            val = float(L[2])
        except:
            return
        if L[1] == 'LY':
            if val > THRESHHOLD:
                Right_duty_cycle = map(val,0,1,6560,58980)
                pca.channels[5].duty_cycle = 0
                pca.channels[4].duty_cycle = Right_duty_cycle
            elif val < -THRESHHOLD:
                Right_duty_cycle = map(val,0,-1,6560,58980)
                pca.channels[5].duty_cycle = 65534
                pca.channels[4].duty_cycle = Right_duty_cycle
            else:
                pca.channels[5].duty_cycle = 65534
                pca.channels[4].duty_cycle = 6560

        elif L[1] == 'RY':
            if val > THRESHHOLD:
                Left_duty_cycle = map(val,0,1,6560,58980)
                pca.channels[7].duty_cycle = 65534
                pca.channels[6].duty_cycle = Left_duty_cycle
            elif val < -THRESHHOLD:
                Left_duty_cycle = map(val,0,-1,6560,58980)
                pca.channels[7].duty_cycle = 0
                pca.channels[6].duty_cycle = Left_duty_cycle
            else:
                pca.channels[7].duty_cycle = 0
                pca.channels[6].duty_cycle = 6560

def disable():
    pca.channels[12].duty_cycle = 0
