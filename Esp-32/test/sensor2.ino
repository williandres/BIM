void Sensor2code(void * pvParameters)
{
  for(;;)
  {
    if (sensor_status[1] == 1)
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
    if (distanceCm_DOWN < dist2)
      {
      // VIBS & BUZZER
      //vibs(delay_led_DOWN, set_vib_s2, 2);
      }
    if (distanceCm_DOWN < 500)
      {
      // LED
      if (led_status[0] == 1 and led_status[1] == 2)
      {
         //digitalWrite(LED_ERROR, LOW);
         //led(delay_led_DOWN*(3/2), LED);
      }
      Serial.print("SENSOR 2 --- Distance (cm): ");
      Serial.println(distanceCm_DOWN);

      }
    else
      {
      //LED
      if (led_status[0] == 1 and led_status[1] == 2)
      {
         //digitalWrite(LED_ERROR, HIGH); 
      }
      Serial.print("SENSOR 2 --- Error ---> "); 
      Serial.print("Distance (cm): ");
      Serial.println(distanceCm_DOWN);
      }
    delay(100);
  }
  }
}
