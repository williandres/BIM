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
    delay_led_UP = distanceCm_UP * 2;

    // * ULTRASONIC SENSOR 1 *
    // Prints the distance in the Serial Monitor 
    // Green LED twinkle means distance
    // Red LED means a mistake in the data capturing
    if (distanceCm_UP < 100)
      {
      digitalWrite(vib2, HIGH);
      delay(delay_led_UP * 2);
      digitalWrite(vib2, LOW);
      }
    if (distanceCm_UP < 500)
      {
      digitalWrite(LED_ERROR_UP, LOW);
      Serial.print("SENSOR 1 --- Distance (cm): ");
      Serial.println(distanceCm_UP);
      digitalWrite(LED_UP, HIGH);
      delay(delay_led_UP);
      digitalWrite(LED_UP, LOW);
      delay(delay_led_UP); 
      }
    else
      {
      digitalWrite(vib2, LOW);
      digitalWrite(LED_ERROR_UP, HIGH);
      Serial.print("SENSOR 1 --- Error ---> "); 
      Serial.print("Distance (cm): ");
      Serial.println(distanceCm_UP);
      }
  }
}
