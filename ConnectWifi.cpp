// Configuração automática de bibliotecas baseada na placa
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#elif defined(ESP32)
  #include <WiFi.h>
#endif

#include "ConnectWifi.h"

ConnectWifi::ConnectWifi(const char* ssid, const char* password){
  this->ssid = ssid;
  this->password = password;
}

void ConnectWifi::connectionsMethod(){
  //Serial.begin(115200);
  Serial.printf("Conectando a %s ", this->ssid);
  WiFi.begin(this->ssid, this->password); // Inicia a conexão

  while (WiFi.status() != WL_CONNECTED) { // Aguarda a conexão ser estabelecida
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado ao Wi-Fi!");
  Serial.print("Endereco IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Endereco MAC do Gateway: ");
  Serial.println(WiFi.macAddress()); // Anote este MAC para usar no codigo do Sender
  Serial.print("Canal Wi-Fi atual: ");
  Serial.println(WiFi.channel()); // Todos os senders devem usar este canal
}