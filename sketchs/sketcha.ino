#include "WiFi.h"

String wifiConnected = "";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  Serial.println("Iniciando wifi");
  Serial.println("Configuração...");
}

void loop() {
  Serial.println("Procurando...");

  int qntDeRedes = WiFi.scanNetworks();

  Serial.println("Verificação...");

  if (qntDeRedes == 0) {
    Serial.print("Total de redes: ");
    Serial.println(qntDeRedes);
  } else {
    for (int i = 0; i < qntDeRedes; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" - Sinal (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(") - Possui senha? ");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "Não" : "Sim");
      delay(10);
      Serial.println("--------------------");
    }

    String melhorRedeSSID = "";
    int melhorSinal = -100;

    for (int i = 0; i < qntDeRedes; i++) {
      if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN && WiFi.RSSI(i) > melhorSinal) {
        melhorRedeSSID = WiFi.SSID(i);
        melhorSinal = WiFi.RSSI(i);
      }
    }

    if (melhorRedeSSID != "") {
      Serial.print("Rede aberta com melhor sinal: ");
      Serial.println(melhorRedeSSID);

      if (wifiConnected == "") {
        Serial.print("Conectando a melhor rede aberta: ");
        Serial.println(melhorRedeSSID);

        WiFi.begin(melhorRedeSSID.c_str());

        int tentativas = 0;
        while (WiFi.status() != WL_CONNECTED && tentativas < 100) {
          Serial.print("."); 
          tentativas++;
          delay(100);
        }

        if (WiFi.status() == WL_CONNECTED) {
          wifiConnected = melhorRedeSSID;
          Serial.println("WiFi conectado!");
        } else {
          wifiConnected = "";
          Serial.println("Não foi possível conectar");
        }
      } else {
        Serial.println("ESP32 já conectado a alguma rede: " + wifiConnected);
      }
    } else {
      Serial.println("Nenhuma rede aberta encontrada");
    }

    delay(5000);
  }
}
