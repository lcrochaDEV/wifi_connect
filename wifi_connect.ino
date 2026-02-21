#include "ConnectWifi.h"

//ConnectWifi connectWifi;

#include "ConnectWifi.h"

const char* SSID = "PERIGO";
const char* PASSWORD = "LIBER@RWIFI";

ConnectWifi connectWifi = ConnectWifi(SSID, PASSWORD);

void setup() {
  Serial.begin(115200);
  delay(500); 
  connectWifi.accesspoint();    
  //connectWifi.connectionsMethod();  // CONNECT WIFI 
}

void loop() {

}



