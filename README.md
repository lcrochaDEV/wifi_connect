### 🚀 ESP Gateway - ConnectWifi Module
Este módulo é responsável por gerenciar a conexão Wi-Fi de dispositivos **ESP32** e **ESP8266** utilizando a técnica de **Captive Portal**. Ele permite que o usuário configure as credenciais de rede sem a necessidade de reprogramar o código-fonte.

```
Status da Branch: feature/ponto-de-acesso (Em desenvolvimento)
```

### 🛠️ Funcionalidades
* **Dual Boot**: Tenta conectar em redes conhecidas ou abre um Access Point (AP) se falhar.
* **Portal** de Configuração: Interface web customizada para inserção de SSID e Senha.
* **Informações** de Rede: Exibe no console o IP, MAC Address e o Canal Wi-Fi (essencial para projetos com ESP-NOW).
* **Resiliência**: Sistema de tentativas limitadas e reconexão automática.

### 📋 Requisitos
Para compilar este projeto, você precisará das seguintes bibliotecas:
* [WiFiManager](https://github.com/tzapu/WiFiManager) (tzapu)
* Biblioteca nativa WiFi.h (ESP32) ou ESP8266WiFi.h (ESP8266)

### 💻 Estrutura do Código
O módulo está dividido em dois arquivos principais para manter a organização POO (Programação Orientada a Objetos):

### 1. ConnectWifi.h: Declaração da classe e atributos.
### 2. ConnectWifi.cpp: Implementação da lógica de conexão e layout do portal.

### Exemplo de Uso
No seu arquivo principal (.ino):

```c++
// cpp
#include "ConnectWifi.h"

// Instancia a classe
ConnectWifi meuWifi("SSID_Padrao", "Senha_Padrao");

void setup() {
  Serial.begin(115200);
  
  // Inicia o modo Ponto de Acesso com Portal Web
  meuWifi.accesspoint();
}
void loop() {
  // Verifica o status da conexão periodicamente
  if(meuWifi.connect_status()) {
    // Lógica do sistema conectado
  }
}
```


### 🎨 Customização do Portal
A página de configuração foi estilizada via CSS injetado para incluir um **Dark Mode**, facilitando a visualização em dispositivos móveis e dando um aspecto profissional ao produto.

```c++
// cpp
// O portal é acessível via IP 192.168.4.1 quando o ESP está em modo AP
wm.setCustomHeadElement("<style>body{background-color:#1a1a1a; ... }</style>");
```

### ⚠️ Notas de Versão
* **Logs de Boot**: O rádio do ESP pode gerar caracteres aleatórios na inicialização (Baud rate de hardware). O código ignora esses ruídos e inicia os logs limpos após a estabilização.
* **Canal Wi-Fi**: O canal exibido no log deve ser o mesmo configurado nos dispositivos Senders se for utilizado ESP-NOW em conjunto.