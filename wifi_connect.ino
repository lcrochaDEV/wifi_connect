#include "ConnectWifi.h"


const char* SSID = "PERIGO";
const char* PASSWORD = "LIBER@RWIFI";

ConnectWifi connectWifi = ConnectWifi(SSID, PASSWORD);

void setup() {
  Serial.begin(115200);
  connectWifi.connectionsMethod();
}

void loop() {
  bool nonect_wifi = connectWifi.connect_status();
  if(nonect_wifi == true){
    Serial.println("Conectado com sucesso!");
  }else{
     Serial.println("Erro ao Conectado!");
  }
}
