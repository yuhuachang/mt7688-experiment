#include <SoftwareSerial.h>
#include <stdlib.h>

#define RS485Rx 14
#define RS485Tx 16
#define TIME_REQUEST 7
#define RS485CtrlPin 15

String inString = "";    // string to hold input
unsigned long interframe_delay = 2;  /* Modbus t3.5 = 2 ms */
int AC_no;
int temp;
int data[12];
int state = 0;
int retval;

SoftwareSerial SSerial3(RS485Rx, RS485Tx);

void setup() {
    const int baudrate = 9600;
    if (baudrate <= 19200) {
        interframe_delay = (unsigned long) (3.5 * 11 / baudrate);  /* Modbus t3.5 */
    }
    SSerial3.begin(baudrate);   /* format 8N1, DOES NOT comply with Modbus spec. */
    Serial.begin(baudrate);
    pinMode(RS485CtrlPin, OUTPUT);
}

void loop() {
    // set target device.
    AC_no = 2;

    // read temp from device.
    retval = read_holding_registers(AC_no, 0x00, 1, data, 10);
    temp = (unsigned int) (256 * (data[0] >> 8) + (data[0] & 0x00ff));
    SSerial3.flush();

    Serial.println(temp);

    delay(5000);
}

