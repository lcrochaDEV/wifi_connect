// Configuração automática de bibliotecas baseada na placa
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  
#elif defined(ESP32)
  #include <WiFi.h>
#endif
#include <WiFiManager.h> // Biblioteca:
#include "ConnectWifi.h"

// Variável para contar as tentativas
  int maxTentativas = 10;
  int tentativaAtual = 0;

ConnectWifi::ConnectWifi(const char* ssid, const char* password)
  : ssid(ssid), password(password) {
  }

void ConnectWifi::connectionsMethod(){
  //Serial.begin(115200);
  Serial.printf("Conectando a %s ", this->ssid);
  WiFi.begin(this->ssid, this->password); // Inicia a conexão

  while (WiFi.status() != WL_CONNECTED && tentativaAtual < maxTentativas) { // Aguarda a conexão ser estabelecida
    delay(500);
    Serial.print(".");
    tentativaAtual++; // Incrementa o contador
  }
  Serial.println("\nConectado ao Wi-Fi!");
  Serial.print("Endereco IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Endereco MAC do Gateway: ");
  Serial.println(WiFi.macAddress()); // Anote este MAC para usar no codigo do Sender
  Serial.print("Canal Wi-Fi atual: ");
  Serial.println(WiFi.channel()); // Todos os senders devem usar este canal
}

void ConnectWifi::accesspoint(){
  WiFiManager wm; 
  // 1. Força a desconexão total para limpar o rádio
  WiFi.disconnect(true);
  delay(100);
  
  // Configura para reconectar automaticamente se cair
  WiFi.persistent(false);
  WiFi.setAutoReconnect(true);
  
  //wm.resetSettings();
  wm.setDebugOutput(false); 
  if(!wm.autoConnect("ESP:AP", "senha123")) { 
    Serial.println("Falha na conexão ou tempo esgotado"); 
    return;
  } 
   
  tentativaAtual = 0;
  while (WiFi.status() != WL_CONNECTED) {// Aguarda a conexão ser estabelecida
    delay(500);
    if (WiFi.status() == WL_CONNECTED) break;
    Serial.print(".");

    if(tentativaAtual == maxTentativas){
      Serial.println("\nFalha ao conectar Wifi!");
      return;
    }
    tentativaAtual++; // Incrementa o contador
  }
  Serial.printf("Conectado à Rede: %s\n", WiFi.SSID().c_str()); 
  Serial.printf("Endereco IP: %s\n", WiFi.localIP().toString().c_str());
  Serial.printf("Endereco MAC: %s\n", WiFi.macAddress().c_str()); 
  Serial.printf("Canal Wi-Fi atual: %d\n", WiFi.channel()); 
}

bool ConnectWifi::connect_status(){
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\nWifi Conectado!");
        return true; // Retorna TRUE, indicando sucesso.
    } else {
      Serial.println("\nWifi Desconectado!");
        return false; // Retorna FALSE, indicando falha.
  }
}