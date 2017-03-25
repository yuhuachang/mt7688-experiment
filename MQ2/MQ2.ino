#define GASPIN 18

void setup() {
  Serial1.begin(57600);
}

void loop() {
  float sensorValue = analogRead(GASPIN);
  float sensorVolt = sensorValue / 1024 * 5.0;

  Serial1.print("volt: ");
  Serial1.println(sensorVolt);
  delay(1000);
}
