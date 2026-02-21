#include "ConnectWifi.h"

ConnectWifi connectWifi;

void setup() {
  Serial.begin(115200);
  delay(500); 
  connectWifi.accesspoint();     
}

void loop() {

}



