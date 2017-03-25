import serial
import time

s = None

def setup():
  global s
  s = serial.Serial("/dev/ttyS0", 57600)

def loop():
  s.write("1")
  print("on")
  time.sleep(1)
  s.write("0")
  print("off")
  time.sleep(1)

if __name__ == '__main__':
  setup()
  while True:
    loop()
