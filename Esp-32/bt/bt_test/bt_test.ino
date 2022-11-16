#include "BluetoothSerial.h"
//BluetoothSerial ESP_BT;
char incoming; 
char bytes[] =  {'2', '4', '8','3', '6'};

void setup() {
  Serial.begin(115200); // Starts the serial communication
  //ESP_BT.begin("BIM");
  
}

void loop() 
  {
  for(int i = 0; i < 5; i++)
{
  Serial.print(bytes[i]);
}
    /*if (ESP_BT.available()) 
    {
    incoming = ESP_BT.read(); //Read what we receive
    Serial.println(incoming);

    }*/
  }
