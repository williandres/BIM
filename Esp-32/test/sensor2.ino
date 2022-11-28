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
      // VIBS
      vibs(delay_led_DOWN, vib2);
      }
    if (distanceCm_DOWN < 500)
      {
      digitalWrite(LED_ERROR_DOWN, LOW); //ERROR LED OFF

      // LED
      led(delay_led_DOWN, LED_DOWN);
      //Serial.print("SENSOR 2 --- Distance (cm): ");
      //Serial.println(distanceCm_DOWN);

      }
    else
      {
      digitalWrite(LED_ERROR_DOWN, HIGH);
      //Serial.print("SENSOR 2 --- Error ---> "); 
      //Serial.print("Distance (cm): ");
      //Serial.println(distanceCm_DOWN);
      }
    delay(100);
  }
}
