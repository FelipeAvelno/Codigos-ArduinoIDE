int valorLdr;
int valorPotenciometro;
int intensidade;
float ldr = A0;
const int potenciometro = A1;
const int ledVermelho = 12;
const int ledVerde = 13;

void setup(){
  Serial.begin(9600);
  pinMode(potenciometro, INPUT);
  pinMode(ldr, INPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  valorPotenciometro = analogRead(potenciometro);
  valorLdr = analogRead(ldr);
  intensidade = map(valorLdr, 0, 1023, 1, 100);
  
  if (valorPotenciometro < 512) {
    digitalWrite(ledVerde, HIGH);
    Serial.print("potenciometro: ");
    Serial.print(valorPotenciometro);
    Serial.println(" e led branco aceso");
    
  } else {
    digitalWrite(ledVerde, LOW);
    Serial.print("potenciometro: ");
    Serial.print(valorPotenciometro);
    Serial.println(" e led branco apagado");
  }

  if (valorLdr >= 300) {
    digitalWrite(ledVermelho, HIGH);
    Serial.print("luminosidade: ");
    Serial.print(intensidade);
    Serial.println(" e led vermelho: aceso");
  } else {
    digitalWrite(ledVermelho, LOW);
    Serial.print("luminosidade: ");
    Serial.print(intensidade);
    Serial.println(" e led vermelhpo apagado");
  }

  delay(500);
}
