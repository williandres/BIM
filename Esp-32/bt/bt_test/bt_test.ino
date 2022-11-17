#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;
char incoming; 
char bytes[0];
int i;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  ESP_BT.begin("BIM");
  
}

void loop() 
  {
    if (ESP_BT.available()) 
    {
    incoming = ESP_BT.read(); //Read what we receive
    
      if (incoming == 'a')//CREATE A EMPTY LIST
      {
        i = 0;
        bytes[i] = {};
      }
      if (incoming == 'z') //EVALUATE
      {
        for (byte x = 0; x < i; x = x + 1) 
          {
          Serial.println(bytes[x]);
          }
        option();

      }
      else // ADD DATA TO THE THE LIST
      {
        bytes[i] = incoming;
        i = i + 1;
      }
    }
  }


void option()
{
  if (bytes[1] == 'q')
    {
       Serial.println("Sensor 1 : ON");
    }
  if (bytes[1] == 'w')
    {
      Serial.println("Sensor 1 : OFF");
    }
  if (bytes[1] == 'e')
    {
      Serial.println("Sensor 2 : ON");
    }
  if (bytes[1] == 'r')
    {
      Serial.println("Sensor 2 : OFF");
    }
  if (bytes[1] == 'm')
    {
      Serial.println("Assigned distance in Sensor 1");
    }
  if (bytes[1] == 'n')
    {
      Serial.println("Assigned distance in Sensor 2");
    }




}

 
