from curses import baudrate
import serial
import pandas as pd
import matplotlib.pyplot as plt
import csv
import numpy as np
import time 
from curses import baudrate
ser = serial.Serial("COM3", 115200, timeout=5) # changed to 115200

while 1:
    arduinoData=ser.readline().decode('ascii')
    print(arduinoData)

#ser.flushInput()

# https://makersportal.com/blog/2018/2/25/python-datalogger-reading-the-serial-output-from-arduino-to-analyze-data-using-pyserial

# ser.readline()


# while True:
#     try:
#         ser_bytes = ser.readline()
#         decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
#         print(decoded_bytes)
#         with open("test_data.csv","a") as f:
#             writer = csv.writer(f,delimiter=",")
#             writer.writerow([time.time(),decoded_bytes])
#     except:
#         print("Keyboard Interrupt")
#         break