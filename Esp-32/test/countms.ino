bool flagS1 = true;
bool flagS2 = true;
bool flagBZ = true;
long previousMillisS1 = 0;
long previousMillisS2 = 0;
long previousMillisBZ = 0;

// pin = pin, timeOn = tiempo que va a durar encendido, timeOff = tiempo que va a durar apagado // LED VERDE SENSOR 1
void countmsS1(int pin, long timeOn, long timeOff){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisS1 + timeOn + timeOff)){
      flagS1 = true; 
  }
  else {
    flagS1 = false;
    previousMillisS1 = millis();
  }
  if (flagS1 == true){
    if (millis() > (previousMillisS1 + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}

void countmsS2(int pin, long timeOn, long timeOff){ // LED VERDE SENSOR 2
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisS2 + timeOn + timeOff)){
    flagS2 = true; 
  }
  else {
    flagS2 = false;
    previousMillisS2 = millis();
  }
  if (flagS2 == true){
    if (millis() > (previousMillisS2 + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}

void countmsBZ(int pin, long timeOn, long timeOff){ // LED VERDE SENSOR 2
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisBZ + timeOn + timeOff)){
    flagBZ = true; 
  }
  else {
    flagBZ = false;
    previousMillisBZ = millis();
  }
  if (flagBZ == true){
    if (millis() > (previousMillisBZ + timeOn)){
      noTone(BUZZER);
    }
    else{
      tone(BUZZER, 50);
    }
  }
}
