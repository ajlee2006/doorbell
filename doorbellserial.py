import serial, os, random

ser = serial.Serial('/dev/ttyUSB0',9600)
ser.flushInput()

ringtones = ['doorbell-twice.wav','eine-kleine.wav']

while True:
    msg = ser.read(ser.inWaiting()).decode()
    if msg != '':
        print("Ding dong")
        os.system("aplay " + random.choice(ringtones))
