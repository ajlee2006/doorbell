import serial, sys, time, os

ser = serial.Serial('/dev/ttyUSB0',9600)
ser.flushInput()

while True:
    msg = ser.read(ser.inWaiting()).decode()
    if msg != '':
        print("Ding dong")
        os.system("aplay doorbell-1.wav")
