void Sensor1code(void * pvParameters)
{
  for(;;)
  { 
    if (sensor_status[0] == 1)
    {
    // * ULTRASONIC SENSOR 1 *
    digitalWrite(trigPin_UP, LOW);
    delayMicroseconds(20);
    digitalWrite(trigPin_UP, HIGH);
    delayMicroseconds(100);
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
      {
      // VIBS & BUZZER
      vibs(delay_led_UP, set_vib_s1, 1);
      }
    if (distanceCm_UP < 500)
      {
      //LED
      if (led_status[0] == 1 and led_status[1] == 1)
      {
         digitalWrite(LED_ERROR, LOW);
         led(delay_led_UP*(3/2), LED);
      }
      Serial.print("SENSOR 1 --- Distance (cm): ");
      Serial.println(distanceCm_UP);
      
      }
    else
      {
      //LED
      if (led_status[0] == 1 and led_status[1] == 1)
      {
         digitalWrite(LED_ERROR, HIGH); 
      }
      Serial.print("SENSOR 1 --- Error ---> "); 
      Serial.print("Distance (cm): ");
      Serial.println(distanceCm_UP);
      }
      delay(100);
  }
  }
}
