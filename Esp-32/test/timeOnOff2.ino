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