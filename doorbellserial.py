import serial, os, random, time, sys

ser = serial.Serial('/dev/ttyUSB0',9600)
ser.flushInput()

#ringtones = os.listdir('ringtones')

while True:
    time.sleep(0.05)
    try:
        msgStr = ser.read(ser.inWaiting()).strip()
        # print(msgStr, type(msgStr)) -> bytes
        if len(msgStr) > 0:
            msg = int(msgStr)
            # print(msg)
        else:
            msg = -1
        if msg > 0 :
            print( "Ding dong", msg )
            #os.system("aplay ringtones/" + random.choice(ringtones))
            os.system(random.choice(["aplay ringtones/doorbell-four.wav","aplay ringtones/doorbell-six.wav"]))
            print('completed')
    except BaseException as err:
        print("Error...", type(err))
    sys.stdout.flush()
