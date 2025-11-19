#include "ConnectWifi.h"


const char* SSID = "PERIGO";
const char* PASSWORD = "LIBER@RWIFI";

ConnectWifi connectWifi = ConnectWifi(SSID, PASSWORD);

void setup() {
  Serial.begin(115200);
  connectWifi.connectionsMethod();

}

void loop() {
  // put your main code here, to run repeatedly:

}
