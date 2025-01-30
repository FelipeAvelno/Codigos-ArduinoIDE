
#include "WiFi.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1115200);
  Serial.println("Iniciando Scanner...");
  WiFi.mode(WIFI_STA);
  Serial.println("Configuração concluida");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Procurando...");

  int qnt_DeRedes = WiFi.scanNetworks();  
  Serial.println("Vericação concluida");

  if (qnt_DeRedes == 0) {
    Serial.println("0 redes econtradas");
  } else {
    Serial.print("Quantidade de redes encontradas: ");
      Serial.println(qnt_DeRedes);

    for (int i = 0; i < qnt_DeRedes; i++) { // Loop for com incrementação
      Serial.print(i + 1);
      Serial.print(": ");

      Serial.print(WiFi.RSSI(i));
      Serial.print(") Possui senha?");

      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Não" : "Sim"); // Verificando se a rede possui senha ou não
      delay(10);
    }

    delay(5000);
  }
}
