bool flagV0 = true;
bool flagV1 = true;
bool flagV2 = true;
bool flagV3 = true;
bool flagV4 = true;
long previousMillisV0 = 0;
long previousMillisV1 = 0;
long previousMillisV2 = 0;
long previousMillisV3 = 0;
long previousMillisV4 = 0;

void countmsV0(int pin, long timeOn, long timeOff){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisV0 + timeOn + timeOff)){
    flagV0 = true; 
  }
  else {
    flagV0 = false;
    previousMillisV0 = millis();
  }
  if (flagV0 == true){
    if (millis() > (previousMillisV0 + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}

void countmsV1(int pin, long timeOn, long timeOff){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisV1 + timeOn + timeOff)){
    flagV1 = true; 
  }
  else {
    flagV1 = false;
    previousMillisV1 = millis();
  }
  if (flagV1 == true){
    if (millis() > (previousMillisV1 + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}

void countmsV2(int pin, long timeOn, long timeOff){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisV2 + timeOn + timeOff)){
    flagV2 = true; 
  }
  else {
    flagV2 = false;
    previousMillisV2 = millis();
  }
  if (flagV2 == true){
    if (millis() > (previousMillisV2 + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}

void countmsV3(int pin, long timeOn, long timeOff){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisV3 + timeOn + timeOff)){
    flagV3 = true; 
  }
  else {
    flagV3 = false;
    previousMillisV3 = millis();
  }
  if (flagV3 == true){
    if (millis() > (previousMillisV3 + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}

void countmsV4(int pin, long timeOn, long timeOff){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisV4 + timeOn + timeOff)){
    flagV4 = true; 
  }
  else {
    flagV4 = false;
    previousMillisV4 = millis();
  }
  if (flagV4 == true){
    if (millis() > (previousMillisV4 + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}
