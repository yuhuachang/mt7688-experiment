// The same blink test with serial communication to linux

#define PIN 18

void setup() {
  Serial.begin(115200);
  Serial1.begin(57600);
  pinMode(13, OUTPUT);
  pinMode(PIN, OUTPUT);
}

void loop() {
  int c = Serial1.read();
  if (c != -1) {
    switch(c) {
      case '0':
        digitalWrite(13, LOW);
        digitalWrite(PIN, LOW);
        break;
      case '1':
        digitalWrite(13, HIGH);
        digitalWrite(PIN, HIGH);
        break;
    }
  }
}
