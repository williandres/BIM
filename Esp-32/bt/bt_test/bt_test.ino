#include "BluetoothSerial.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

BluetoothSerial ESP_BT;
char incoming; 
char bytes[0];
int i;

int dist1;
int dist2;

String value; 

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
        for (int x = 0; x < i; x = x + 1) 
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
  /////
  ////
  ///
  // SENSORS

  //S1
  if (bytes[1] == 'q')
    {
       Serial.println("Sensor 1 : ON");
    }
  if (bytes[1] == 'w')
    {
      Serial.println("Sensor 1 : OFF");
    }
  //S2
  if (bytes[1] == 'e')
    {
      Serial.println("Sensor 2 : ON");
    }
  if (bytes[1] == 'r')
    {
      Serial.println("Sensor 2 : OFF");
    }
  // DIST 1
  if (bytes[1] == 'm')
    {
      value = "";
      for (int x = 2; x < i; x = x + 1)//LIST TO STRING
      {
        value = value + bytes[x];
      }
      Serial.println(value);
      Serial.println("Assigned distance in Sensor 1");
      dist1 = value.toInt(); // STR to INT
    }
  // DIST 2  
  if (bytes[1] == 'n')
    {
      value = "";
      for (int x = 2; x < i; x = x + 1)//LIST TO STRING
      {
        value = value + bytes[x];
      }
      Serial.println(value);
      Serial.println("Assigned distance in Sensor 2");
      dist2 = value.toInt(); // STR to INT
    }
  /////
  ////
  ///
  // BUZZERS









  /////
  ////
  ///
  // VIBS
}

 
