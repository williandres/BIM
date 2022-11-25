void Sensor2code(void * pvParameters)
{
  for(;;)
  {
    // * ULTRASONIC SENSOR 2 *
    digitalWrite(trigPin_DOWN, LOW);
    delayMicroseconds(20);
    digitalWrite(trigPin_DOWN, HIGH);
    delayMicroseconds(100);
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
      countmsBZ(BUZZER, 1/delay_led_DOWN * 2, 1/delay_led_DOWN  * 2);
      countmsV2(vib2, 1/delay_led_DOWN * 2, 1/delay_led_DOWN  * 2);
      }
    if (distanceCm_DOWN < 500)
      {
      digitalWrite(vib2, LOW);
      digitalWrite(LED_ERROR_DOWN, LOW); //ERROR LED OFF
      Serial.print("SENSOR 2 --- Distance (cm): ");
      Serial.println(distanceCm_DOWN);
      countmsS2(LED_DOWN, 1/delay_led_DOWN, 1/delay_led_DOWN);

      }
    else
      {
      digitalWrite(LED_DOWN, LOW);
      digitalWrite(vib2, LOW);
      digitalWrite(LED_ERROR_DOWN, HIGH);
      Serial.print("SENSOR 2 --- Error ---> "); 
      Serial.print("Distance (cm): ");
      Serial.println(distanceCm_DOWN);
      }
    delay(100);
  }
}
