const int LED_PIN = 16;
const int POWER_PIN = 5;
unsigned long timing[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 43992};

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(POWER_PIN);
  if(buttonState == LOW){
    Serial.println("button pressed");
    sendIRSignal();
  }
  delay(100);
}

void sendIRSignal() {
  for (int i = 0; i < 68; i += 2) {
    // ON with 38kHz modulation
    enableIROut(timing[i]);

    // OFF
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(timing[i + 1]);
  }
}

void enableIROut(unsigned int timeMicros) {
  unsigned long start = micros();
  while (micros() - start < timeMicros) {
    digitalWrite(LED_PIN, HIGH);
    delayMicroseconds(13);   // ~26µs total ON+OFF gives ~38kHz
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(13);
  }
}
