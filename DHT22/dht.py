import serial
import time

s = None

def setup():
  global s
  s = serial.Serial("/dev/ttyS0", 57600)

def loop():
  line = s.readline()
  print(line)

if __name__ == '__main__':
  setup()
  while True:
    loop()
