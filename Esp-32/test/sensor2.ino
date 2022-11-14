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
      digitalWrite(vib1, HIGH);
      delay(delay_led_DOWN * 2);
      digitalWrite(vib1, LOW);
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
      digitalWrite(vib1, LOW);
      digitalWrite(LED_ERROR_DOWN, HIGH);
      //Serial.print("SENSOR 2 --- Error ---> "); 
      //Serial.print("Distance (cm): ");
      //Serial.println(distanceCm_DOWN);
      }
  }
}
