void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();

    switch (inByte) {
      case 'a':
        digitalWrite(2, LOW);
        break;

      case 'A':
        digitalWrite(2, HIGH);
        break;

      case 'B':
        for (int i = 0; i < 10; i++){
          digitalWrite(2, HIGH);
          delay(1500);
          digitalWrite(2, LOW);
          delay(1000);
        }

      default:
        digitalWrite(2, LOW);
        break;
    }
  }
}
