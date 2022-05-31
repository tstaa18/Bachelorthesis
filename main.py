
import numpy as np
import serial #for communication between Py and Arduino
import time
import sys
import cv2

from deepface import DeepFace

arduino = serial.Serial('COM3', 115200, timeout=.1)
time.sleep(1) #give the connection a second to settle

video = cv2.VideoCapture(1)

if (video.isOpened()==False):
    print("Can't access the webcam")
img_counter = 0

while(video.isOpened()):
    check, frame = video.read()
    #frame = cv2.resize(frame, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_AREA)
    cv2.imshow('input', frame)

    key = cv2.waitKey(1)
    if key == 27: #ESC key pressed and program terminates
        break
    elif key == 32: #space-bar takes a photo
        face_img = "face_to_detect{}.png".format(img_counter)
        cv2.imwrite(face_img, frame)
        print("{} written!".format(face_img))
        img_counter += 1

        #Analyse the screenshot
        analysis = DeepFace.analyze(face_img,
                                     actions=['emotion'])
        print(analysis)
        dominant_emotion_to_pass = (analysis['dominant_emotion'])
        print("Dominant emotion:")
        print( dominant_emotion_to_pass)

        thisdict = {
                    "neutral": 'n',
                    "happy": 'h',
	                "sad": 's',
	                "fear": 'f',
	                "angry": 'a',

                    }

        arduino.write(thisdict[dominant_emotion_to_pass].encode())
        data = arduino.readline()
        if data:
        	print(data)

video.release()

cv2.destroyAllWindows()


