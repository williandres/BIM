const int BUZZER = 32;                                                   ;

void setup() {
    Serial.begin(115200); // Starts the serial communication
    pinMode(BUZZER, OUTPUT);// Buzzer
}

void loop() {
  for (int i = 0; i < 100000; i++)
  {
      Serial.println(i);
      tone(BUZZER, i);
      delay(100);
  }
  
  
  
  }
