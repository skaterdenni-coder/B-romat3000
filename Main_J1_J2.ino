const int STEP_PIN = 2;
const int DIR_PIN  = 5;
const int ENA_PIN  = 8;

void setup() {
  Serial.begin(115200);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);
  digitalWrite(ENA_PIN, HIGH); // In Ruhe spannungsfrei
}

void loop() {
  // Prüfen, ob ein Befehl vom PC kommt
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') { // Wenn '1' gesendet wird -> Motor drehen
      digitalWrite(ENA_PIN, LOW);
      delay(50);
      digitalWrite(DIR_PIN, LOW);

      for (int i = 0; i < 1800; i++) {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(4000);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(4000);
      }

      digitalWrite(ENA_PIN, HIGH); // Wieder stromlos schalten
    }
  }
}