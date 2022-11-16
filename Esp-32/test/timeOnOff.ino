boolean flag = true;
long previousMillis = 0;
// pin = pin, timeOn = tiempo que va a durar encendido, timeOff = tiempo que va a durar apagado
void countms(int pin, long timeOn, long timeOff){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillis + timeOn + timeOff)){
    flag = true; 
  }
  else {
    flag = false;
    previousMillis = millis();
  }
  if (flag == true){
    if (millis() > (previousMillis + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}


boolean flag2 = true;
long previousMillis2 = 0;
void countms2(int pin, long timeOn, long timeOff){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillis2 + timeOn + timeOff)){
    flag2 = true; 
  }
  else {
    flag2 = false;
    previousMillis2 = millis();
  }
  if (flag2 == true){
    if (millis() > (previousMillis2 + timeOn)){
      digitalWrite(pin, LOW);
    }
    else{
      digitalWrite(pin, HIGH);
    }
  }
}
