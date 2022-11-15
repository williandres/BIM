// Headers
#include "const.h"
#include "pitches.h"
#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;
 
void setup() 
  {
  setup_bim();
  }

void Sensor1code(void * pvParameters)
{
  for(;;)
  {    
    if (sen1 == 1)
    {
    // * ULTRASONIC SENSOR 1 *
    // Clears the trigPin
    digitalWrite(trigPin_UP, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin_UP, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin_UP, LOW);  
  
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration_UP = pulseIn(echoPin_UP, HIGH); //ULTRASONIC SENSOR 1
  
    // Calculate the distance
    distanceCm_UP = duration_UP * SOUND_SPEED/2; //ULTRASONIC SENSOR 1
    delay_led_UP = distanceCm_UP * 2;

    // * ULTRASONIC SENSOR 1 *
    // Prints the distance in the Serial Monitor 
    // Green LED twinkle means distance
    // Red LED means a mistake in the data capturing
    if (distanceCm_UP < dist1)
      {/*
      digitalWrite(vib1, HIGH);
      delay(delay_led_UP * 2);
      digitalWrite(vib1, LOW);
      */
      countms(vib1, delay_led_UP * 2, delay_led_UP * 2);
      }
    if (distanceCm_UP < 500)
      {
      digitalWrite(LED_ERROR_UP, LOW);
      Serial.print("SENSOR 1 --- Distance (cm): ");
      Serial.println(distanceCm_UP);
      //digitalWrite(LED_UP, HIGH);
      //delay(delay_led_UP);
      //digitalWrite(LED_UP, LOW);
      //delay(delay_led_UP); 
      countms(LED_UP, delay_led_UP, delay_led_UP);
      }
    else
      {
      digitalWrite(vib1, LOW);
      digitalWrite(LED_UP, LOW);
      digitalWrite(LED_ERROR_UP, HIGH);
      //Serial.print("SENSOR 1 --- Error ---> "); 
      //Serial.print("Distance (cm): ");
      //Serial.println(distanceCm_UP);
      }
    }
    else
    {
    digitalWrite(vib1, LOW);
    digitalWrite(LED_ERROR_UP, LOW);
    digitalWrite(LED_UP, LOW);
    }
  }
}

void Sensor2code(void * pvParameters)
{
  for(;;)
  {
    if (sen2 == 1)
    {
    // * ULTRASONIC SENSOR 2 *
    // Clears the trigPin
    digitalWrite(trigPin_DOWN, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin_DOWN, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin_DOWN, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration_DOWN = pulseIn(echoPin_DOWN, HIGH); //ULTRASONIC SENSOR 2
  
    // Calculate the distance 
    distanceCm_DOWN = duration_DOWN * SOUND_SPEED/2; //ULTRASONIC SENSOR 2
    delay_led_DOWN = distanceCm_DOWN * 2;
    
    // * ULTRASONIC SENSOR 2 *
    // Prints the distance in the Serial Monitor 
    // Green LED twinkle means distance
    // Red LED means a mistake in the data capturing
    if (distanceCm_DOWN < dist2)
      {
      tone(BUZZER, NOTE_GS5);
      digitalWrite(vib2, HIGH);
      delay(delay_led_DOWN * 2);
      digitalWrite(vib2, LOW);
      noTone(BUZZER);
      }
    if (distanceCm_DOWN < 500)
      {
      digitalWrite(LED_ERROR_DOWN, LOW); //ERROR LED OFF
      //Serial.print("SENSOR 2 --- Distance (cm): ");
      //Serial.println(distanceCm_DOWN);
      digitalWrite(LED_DOWN, HIGH);
      delay(delay_led_DOWN);
      digitalWrite(LED_DOWN, LOW);
      delay(delay_led_DOWN); 
      }
    else
      {
      digitalWrite(vib2, LOW);
      digitalWrite(LED_ERROR_DOWN, HIGH);
      //Serial.print("SENSOR 2 --- Error ---> "); 
      //Serial.print("Distance (cm): ");
      //Serial.println(distanceCm_DOWN);
      }
    }
    else
    {
    digitalWrite(vib2, LOW);
    digitalWrite(LED_ERROR_DOWN, LOW);
    digitalWrite(LED_DOWN, LOW);
    noTone(BUZZER);
    }
  }
}


void loop() 
  {
    if (ESP_BT.available()) 
    {
    incoming = ESP_BT.read(); //Read what we receive
    Serial.print(incoming);
    if (incoming == "a")
      {
      Serial.println("Sensor 1: ON");
      sen1 = 1;
      }
    if (incoming == "b")
      {
      Serial.println("Sensor 1: OFF");
      sen1 = 0;
      }
    if (incoming == "c")
      {
      Serial.println("Sensor 2: ON");
      sen2 = 1;
      }
    if (incoming == "d")
      {
      Serial.println("Sensor 2: OFF");
      sen2 = 0;
      }
    if (incoming.substring(0,1) == "x") //Sensor 1 Distance
      {
      dist1 = incoming.substring(1).toInt();
      }
    if (incoming.substring(0,1) == "y") //Sensor 2 Distance
      {
      dist2 = incoming.substring(1).toInt();
      }
    }
  }

    
