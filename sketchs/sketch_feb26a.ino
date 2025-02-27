void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
	  int valor_recebido = Serial.read();

      if (valor_recebido == 'A') {
        digitalWrite(2, HIGH);
      }
    
      else if (valor_recebido == 'a') {
        digitalWrite(2, LOW);
      }
    
      else if (valor_recebido == 'B') {
        for (int numero_de_vezes = 2; numero_de_vezes < 10; numero_de_vezes++){
          digitalWrite(2, HIGH);
          delay(1000);
          digitalWrite(2, LOW);
          delay(1000);
      }
    }
  }
}