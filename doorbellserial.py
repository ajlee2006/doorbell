import serial, os, random

ser = serial.Serial('/dev/ttyUSB0',9600)
ser.flushInput()

ringtones = os.listdir('ringtones')

while True:
    msg = ser.read(ser.inWaiting()).decode()
    if msg != '':
        print("Ding dong")
        os.system("aplay ringtones/" + random.choice(ringtones))
