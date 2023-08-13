from time import sleep

import RPi.GPIO as GPIO

from .sabertooth_serial import SabertoothSerial

is_driving = True

THRESHHOLD = 0.2

HIGH=100
HALF=50
LOW=0

SOFT_HIGH = 94
SOFT_LOW = 6

LEFT_PUL = 33
LEFT_DIR = 38
RIGHT_PUL = 12
RIGHT_DIR = 40

DRIVE_ENABLE = 36

sabertooth = SabertoothSerial(port='/dev/ttyS0',baudrate=9600)

GPIO.setwarnings(False)			#disable warnings
GPIO.setmode(GPIO.BOARD)

GPIO.setup(LEFT_PUL,GPIO.OUT)
GPIO.setup(RIGHT_PUL, GPIO.OUT)

left_pwm = GPIO.PWM(LEFT_PUL,1000)	
right_pwm = GPIO.PWM(RIGHT_PUL, 1000)

left_pwm.start(SOFT_LOW)
right_pwm.start(SOFT_HIGH)

pca.channels[DRIVE_ENABLE].duty_cycle = SOFT_HIGH #enable pin

# Helper Function
def lerp(value, istart, istop, ostart, ostop):
    return int(ostart + (ostop - ostart) * ((value - istart) / (istop - istart)))

def handle_arm_input(L):
    if L[0] == 'AXIS_CHANGED:':
        try:
            val = float(L[2])
        except:
            return
        if L[1] == 'LY':
            sabertooth.motorA(int(val*90))
                
        if L[1] == 'RY':
            sabertooth.motorB(int(val*90))

def handle_drive_input(L):
    if L[0] == 'AXIS_CHANGED:':
        try:
            val = float(L[2])
        except:
            return
        if L[1] == 'RY':
            if val > THRESHHOLD:
                Right_duty_cycle = lerp(val,0,1,SOFT_LOW,SOFT_HIGH)
                pca.channels[RIGHT_WHEEL_DIR].duty_cycle = SOFT_LOW
                right_pwm.ChangeDutyCycle(Right_duty_cycle)
            elif val < -THRESHHOLD:
                Right_duty_cycle = lerp(val,0,-1,SOFT_LOW,SOFT_HIGH)
                pca.channels[RIGHT_WHEEL_DIR].duty_cycle = SOFT_HIGH
                right_pwm.ChangeDutyCycle(Right_duty_cycle)
            else:
                pca.channels[RIGHT_WHEEL_DIR].duty_cycle = SOFT_HIGH
                right_pwm.ChangeDutyCycle(SOFT_LOW)

        elif L[1] == 'LY':
            if val > THRESHHOLD:
                Left_duty_cycle = lerp(val,0,1,SOFT_LOW,SOFT_HIGH)
                pca.channels[LEFT_WHEEL_DIR].duty_cycle = SOFT_HIGH
                left_pwm.ChangeDutyCycle(Left_duty_cycle)
            elif val < -THRESHHOLD:
                Left_duty_cycle = lerp(val,0,-1,SOFT_LOW,SOFT_HIGH)
                pca.channels[LEFT_WHEEL_DIR].duty_cycle = SOFT_LOW
                left_pwm.ChangeDutyCycle(Left_duty_cycle)
            else:
                pca.channels[LEFT_WHEEL_DIR].duty_cycle = SOFT_LOW
                left_pwm.ChangeDutyCycle(SOFT_LOW)
                


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
        handle_arm_input(L)
        
            
def disable():
    pca.channels[DRIVE_ENABLE].duty_cycle = LOW
