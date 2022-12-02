// Headers
#include "const.h"
#include "pitches.h"
#include "BluetoothSerial.h"
#include <Arduino.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
BluetoothSerial ESP_BT;
char incoming; 
char bytes[0];
int i;
String value;

void setup()
{
  setup_bim();
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
       sensor_status[0] = 1;
       Serial.println("Sensor 1 : ON");
    }
  if (bytes[1] == 'w')
    {
      sensor_status[0] = 0;
      Serial.println("Sensor 1 : OFF");
    }
  //S2
  if (bytes[1] == 'e')
    {
      sensor_status[1] = 1;
      Serial.println("Sensor 2 : ON");
    }
  if (bytes[1] == 'r')
    {
      sensor_status[2] = 0;
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
  if (bytes[1] == 'k')
    {
      buzzer_status[0] = 1;
      Serial.println("Buzzer: ON");
    }
  if (bytes[1] == 'p')
    {
      buzzer_status[0] = 0;
      Serial.println("Buzzer: OFF");
    }
  if (bytes[1] == 'x')
    {
      if (bytes[2] == 'q')
      {
        value = "";
        for (int x = 2; x < i; x = x + 1)//LIST TO STRING
        {
          value = value + bytes[x];
        }
        Serial.println(value);
        Serial.println("Assigned new tone");
      }
      if (bytes[2] == 'e')
      {
          buzzer_status[1] = 1;
      }
      if (bytes[2] == 'w')
      {
          buzzer_status[1] = 2;
      }
      }
  /////
  ////
  ///
  // VIBS

  // ON / OFF
  if (bytes[1] == 't')
    {
      Serial.println("VIB 0: ON");
      vib_status[0] = 1;
    }
  if (bytes[1] == 'y')
    {
      Serial.println("VIB 0: OFF");
      vib_status[0] = 0;
    }
  if (bytes[1] == 'u')
    {
      Serial.println("VIB 1: ON");
      vib_status[1] = 1;
    }
  if (bytes[1] == 'i')
    {
      Serial.println("VIB 1: OFF");
      vib_status[1] = 0;
    }
  if (bytes[1] == 'o')
    {
      vib_status[2] = 1;
      Serial.println("VIB 2: ON");
    }
  if (bytes[1] == 's')
    {
      vib_status[2] = 0;
      Serial.println("VIB 2: OFF");
    }
  if (bytes[1] == 'd')
    {
      vib_status[3] = 1;
      Serial.println("VIB 3: ON");
    }
  if (bytes[1] == 'f')
    {
      vib_status[3] = 0;
      Serial.println("VIB 3: OFF");
    }
  if (bytes[1] == 'g')
    {
      vib_status[4] = 1;
      Serial.println("VIB 4: ON");
    }
  if (bytes[1] == 'h')
    {
      vib_status[4] = 0;
      Serial.println("VIB 4: OFF");
    }
    
  // Set as
  if (bytes[1] == 'j')
    {
      value = "";
      for (int x = 2; x < i; x = x + 1)//LIST TO STRING
      {
        value = value + bytes[x];
      }
      Serial.println(value);
      Serial.println("Set to VIB 0");
    }
    
  if (bytes[1] == 'l')
    {
      value = "";
      for (int x = 2; x < i; x = x + 1)//LIST TO STRING
      {
        value = value + bytes[x];
      }
      Serial.println(value);
      Serial.println("Set to VIB 1");
    }
  if (bytes[1] == 'c')
    {
      value = "";
      for (int x = 2; x < i; x = x + 1)//LIST TO STRING
      {
        value = value + bytes[x];
      }
      Serial.println(value);
      Serial.println("Set to VIB 2");
    }
  if (bytes[1] == 'v')
    {
      value = "";
      for (int x = 2; x < i; x = x + 1)//LIST TO STRING
      {
        value = value + bytes[x];
      }
      Serial.println(value);
      Serial.println("Set to VIB 3");
    }
  if (bytes[1] == 'b')
    {
      value = "";
      for (int x = 2; x < i; x = x + 1)//LIST TO STRING
      {
        value = value + bytes[x];
      }
      Serial.println(value);
      Serial.println("Set to VIB 4");
    }

  /////
  ////
  ///
  // LEDS
  if (bytes[1] == '-')
    {
        if (bytes[1] == 'a')
        {
          led_status[0]= 1;
          Serial.println("LED ON");
        }
        if (bytes[1] == 'b')
        {
          led_status[0]= 0;
          Serial.println("LED OFF");
        }
    }

  /////
  ///
  //
  // Extra
  if (bytes[1] == '?')
    {
      tone(BUZZER, note);
      delay(2000);
      noTone(BUZZER);
    }
}

 
