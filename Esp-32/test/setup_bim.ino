TaskHandle_t Sensor1;
TaskHandle_t Sensor2;


void setup_bim() 
  {
  Serial.begin(115200); // Starts the serial communication
  //ESP_BT.begin("BIM");
  
  // ULTRASONIC SENSOR 1
  pinMode(trigPin_UP, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_UP, INPUT); // Sets the echoPin as an Input
  //pinMode(LED_UP, OUTPUT); // Green LED
  //pinMode(LED_ERROR_UP, OUTPUT); // Error LED 
  
  // ULTRASONIC SENSOR 2
  pinMode(trigPin_DOWN, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_DOWN, INPUT); // Sets the echoPin as an Input
  //pinMode(LED_DOWN, OUTPUT); // Green LED
  //pinMode(LED_ERROR_DOWN, OUTPUT); // Error LED

  //LED
  pinMode(LED_ERROR, OUTPUT); 
  pinMode(LED, OUTPUT);   

  
  //BUZZER
  pinMode(BUZZER, OUTPUT); // BZ
  
  // EXTRAS 
  pinMode(vib0, OUTPUT); // Vibration 0
  pinMode(vib1, OUTPUT); // Vibration 1
  pinMode(vib2, OUTPUT); // Vibration 2
  pinMode(vib3, OUTPUT); // Vibration 3
  pinMode(vib4, OUTPUT); // Vibration 4

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
