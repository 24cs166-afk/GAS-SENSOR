const int gasSensor = A0;
const int buzzer = 8;
const int led = 7;

int gasValue = 0;
int threshold = 400;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  gasValue = analogRead(gasSensor);

  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    Serial.println("WARNING: Gas Level High!");
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    Serial.println("Gas Level Normal");
  }

  delay(500);
}
