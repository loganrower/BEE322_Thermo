## This script will aid in the data aqusition and transfer

import serial
import pandas as pd
## got the port for the arduino device:
uno_port = "COM3"

## the baud rate for the arduino sketch was...
baud = 115200

## file name
fileName="Voltage_Temp.csv"

## The number of samples that we will take in one trial..
samples = 1
print_labels = False # this will make sure that the line ids are not printed 

ser = serial.Serial(uno_port, baud)
print("Successfully Connected to Arduino Uno through:"+uno_port)

file=open(fileName,"a")
print("Created file")

ser_bytes()
line = 0
while line <= samples:
    if print_labels:
        if line==0:
            print("Printing Column Headers")

        else:
            print("Line"+str(line)+"writing...")
    getData=str(ser.readline())
    data=getData[0:][:-2]
    print(data)


