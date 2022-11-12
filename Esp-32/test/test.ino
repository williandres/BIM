

TaskHandle_t Sensor1;
TaskHandle_t Sensor2;

//ULTRASONIC SENSOR 1
const int trigPin_UP = 13;
const int echoPin_UP = 12;
const int LED_UP = 26;
const int LED_ERROR_UP = 25;
//ULTRASONIC SENSOR 2
const int trigPin_DOWN = 14;
const int echoPin_DOWN = 27;
const int LED_DOWN = 15;
const int LED_ERROR_DOWN = 32;
const int BUZZER = 2;

//VIBRATION
const int vib = 4;

// melodys to a buzzer
#include "pitches.h"

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

  long duration_UP;
  long duration_DOWN;
  float distanceCm_UP;
  float distanceCm_DOWN;
  float delay_led_UP;
  float delay_led_DOWN;
  
   
  
  void setup() {
  Serial.begin(92600); // Starts the serial communication
  // ULTRASONIC SENSOR 1
  pinMode(trigPin_UP, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_UP, INPUT); // Sets the echoPin as an Input
  pinMode(LED_UP, OUTPUT); // Green LED
  pinMode(LED_ERROR_UP, OUTPUT); // Error LED 
  // ULTRASONIC SENSOR 2
  pinMode(trigPin_DOWN, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_DOWN, INPUT); // Sets the echoPin as an Input
  pinMode(LED_DOWN, OUTPUT); // Green LED
  pinMode(LED_ERROR_DOWN, OUTPUT); // Error LED

  // EXTRAS 
  pinMode(BUZZER, OUTPUT);// Buzzer
  pinMode(vib, OUTPUT); // Vibration 0

  xTaskCreatePinnedToCore(
             Sensor1code, /* Task function. */
             "Sensor1",   /* name of task. */
             10000,     /* Stack size of task */
             NULL,      /* parameter of the task */
             1,         /* priority of the task */
             &Sensor1,    /* Task handle to keep track of created task */
             0);        /* pin task to core 0 */
      
  xTaskCreatePinnedToCore(
             Sensor2code,  /* Task function. */
             "Sensor2",    /* name of task. */
             10000,      /* Stack size of task */
             NULL,       /* parameter of the task */
             1,          /* priority of the task */
             &Sensor2,     /* Task handle to keep track of created task */
             1);         /* pin task to core 0 */
}



void Sensor1code(void * pvParameters)
{
  for(;;)
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


    // * ULTRASONIC SENSOR 1 *
    // Prints the distance in the Serial Monitor 
    // Green LED twinkle means distance
    // Red LED means a mistake in the data capturing
    if (distanceCm_UP < 500)
      {
      digitalWrite(LED_ERROR_UP, LOW);
      delay_led_UP = distanceCm_UP * 2;
      Serial.print("SENSOR 1 --- Distance (cm): ");
      Serial.println(distanceCm_UP);
      digitalWrite(LED_UP, HIGH);
      delay(delay_led_UP);
      digitalWrite(LED_UP, LOW);
      delay(delay_led_UP); 
      }
    else
      {
      digitalWrite(LED_ERROR_UP, HIGH);
      Serial.print("SENSOR 1 --- Error ---> "); 
      Serial.print("Distance (cm): ");
      Serial.println(distanceCm_UP);
      }
  }
}

void Sensor2code(void * pvParameters)
{
  for(;;)
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
    if (distanceCm_DOWN < 100)
      {
      tone(BUZZER, NOTE_GS5);
      digitalWrite(vib, HIGH);
      delay(delay_led_DOWN * 2);
      digitalWrite(vib, LOW);
      noTone(BUZZER);
      
      }
    if (distanceCm_DOWN < 500)
      {
      digitalWrite(LED_ERROR_DOWN, LOW); //ERROR LED OFF
      Serial.print("SENSOR 2 --- Distance (cm): ");
      Serial.println(distanceCm_DOWN);
      digitalWrite(LED_DOWN, HIGH);
      delay(delay_led_DOWN);
      digitalWrite(LED_DOWN, LOW);
      delay(delay_led_DOWN); 
      }
    else
      {
      digitalWrite(LED_ERROR_DOWN, HIGH);
      Serial.print("SENSOR 2 --- Error ---> "); 
      Serial.print("Distance (cm): ");
      Serial.println(distanceCm_DOWN);
      }
  }
}

void loop() {}
    
