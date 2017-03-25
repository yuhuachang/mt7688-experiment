// Test default pin 13 and target pin.
// Check GPIO pin from D0 to D43 on the board.
// When testing, the LED should wired with a resister to prevent burn out.

#define PIN 18

void setup() {
  pinMode(13, OUTPUT);
  pinMode(PIN, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  digitalWrite(PIN, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  digitalWrite(PIN, LOW);
  delay(500);
}
