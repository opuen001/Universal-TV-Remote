const int LED_PIN = 3;    //Rx pin
const int POWER_PIN = 16; //D0 pin
const int ONE_PIN = 5;    //D1 pin
const int FOUR_PIN = 4;   //D2 pin
const int TWO_PIN = 0;    //D3 pin
const int P2_PIN = 2;     //D4 pin
const int FIVE_PIN = 14;  //D5 pin
const int THREE_PIN = 12; //D6 pin
const int VUP_PIN = 13;   //D7 pin
const int VDWN_PIN = 15;  //D8 pin

unsigned long powerTiming[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 43992};
unsigned long zeroTiming[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 43992};
unsigned long oneTiming[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 43992};
unsigned long twoTiming[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 43992};
unsigned long threeTiming[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 43992};
unsigned long fourTiming[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 43992};
unsigned long fiveTiming[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 43992};
unsigned long vUp[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 43992};
unsigned long vDwn[68] = {9024, 4512, 564, 564, 564, 564, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 1692, 564, 43992};

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, INPUT); //Since D0 does not have a pullup resistor
  pinMode(P2_PIN, INPUT_PULLUP);
  pinMode(ONE_PIN, INPUT_PULLUP);
  pinMode(TWO_PIN, INPUT_PULLUP);
  pinMode(THREE_PIN, INPUT_PULLUP);
  pinMode(FOUR_PIN, INPUT_PULLUP);
  pinMode(FIVE_PIN, INPUT_PULLUP);
  pinMode(VUP_PIN, INPUT_PULLUP);
  pinMode(VDWN_PIN, INPUT); // D8 must be LOW for the ESP8266 to start normally.
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if(digitalRead(POWER_PIN) == LOW){
    Serial.println("power button pressed");
    sendIR(powerTiming);
  }

  if(digitalRead(P2_PIN) == LOW){
    Serial.println("power button pressed");
    sendIR(powerTiming);
  }

  else if(digitalRead(ONE_PIN) == LOW){
    Serial.println("one button pressed");
    sendIR(oneTiming);
    delay(100);
    sendIR(zeroTiming);
    delay(3000);
  }

  else if(digitalRead(TWO_PIN) == LOW){
    Serial.println("two button pressed");
    sendIR(oneTiming);
    delay(100);
    sendIR(twoTiming);
    delay(3000);
  }

  else if(digitalRead(THREE_PIN) == LOW){
    Serial.println("three button pressed");
    sendIR(oneTiming);
    delay(100);
    sendIR(threeTiming);
    delay(3000);
  }

  else if(digitalRead(FOUR_PIN) == LOW){
    Serial.println("four button pressed");
    sendIR(oneTiming);
    delay(100);
    sendIR(fourTiming);
    delay(3000);
  }

  else if(digitalRead(FIVE_PIN) == LOW){
    Serial.println("five button pressed");
    sendIR(oneTiming);
    delay(100);
    sendIR(fiveTiming);
    delay(3000);
  }

  else if(digitalRead(VUP_PIN) == LOW){
    Serial.println("V+ button pressed");
    sendIR(vUp);
  }

  else if(digitalRead(VDWN_PIN) == HIGH){
    Serial.println("V- button pressed");
    sendIR(vDwn);
  }
  delay(100);
}

void sendIR(unsigned long timing[]) {
  for (int i = 0; i < 68; i += 2) {
    // ON with 38kHz modulation
    modulate38kHz(timing[i]);

    // OFF
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(timing[i + 1]);
  }
}

void modulate38kHz(unsigned int timeMicros) {
  unsigned long start = micros();
  while (micros() - start < timeMicros) {
    digitalWrite(LED_PIN, HIGH);
    delayMicroseconds(13);   // ~26µs total ON+OFF gives ~38kHz
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(13);
  }
}