#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;
char incoming; 

void setup() {
  Serial.begin(115200); // Starts the serial communication
  ESP_BT.begin("BIM");
}

void loop() 
  {
    if (ESP_BT.available()) 
    {
    incoming = ESP_BT.read(); //Read what we receive
    Serial.println(incoming);

    if 
    }
  }
