#include <SoftwareSerial.h>
#include <stdlib.h>

#define RS485Rx 14
#define RS485Tx 16
#define RS485CtrlPin 15

#define LED 13

SoftwareSerial RS485Serial(RS485Rx, RS485Tx);

void setup() {
    
    RS485Serial.begin(9600); // RS485 serial
    Serial.begin(9600); // debug serial
    Serial1.begin(57600); // serial communication to MPU
    
    pinMode(RS485CtrlPin, OUTPUT);
    pinMode(LED, OUTPUT);
    
    digitalWrite(LED, LOW);
}

void loop() {

    while (Serial1.available() > 0) {
        digitalWrite(LED, HIGH);

        char c = Serial1.read();
        if (c > 0) {
            Serial.print(c);
            Serial.print("(");
            Serial.print(c, HEX);
            Serial.print(") ");
        } else {
            Serial.println();
            test();
        }

        digitalWrite(LED, LOW);
    }
}

int test() {
        // set target device.
        int AC_no = 2;

        // read temp from device.
        int data[12];
        int retval = read_holding_registers(AC_no, 0x00, 1, data, 10);
        for (int i = 0; i < 12; i++) {
            Serial.print("0x");
            Serial.print(data[i], HEX);
            Serial.print(" ");
        }
        Serial.println();
        
        int temp = (unsigned int) (256 * (data[0] >> 8) + (data[0] & 0x00ff));
        RS485Serial.flush();
    
        Serial.println(temp);
        Serial1.println(temp);
}

