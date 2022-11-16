boolean flagBz = true;
long previousMillisBz = 0;
// pin = pin, timeOn = tiempo que va a durar encendido, timeOff = tiempo que va a durar apagado
void countmsBz(int pin, long timeOn, long timeOff, int tones){
  // millis() es una funcion que permite contar tiempo en ms
  if (millis() < (previousMillisBz + timeOn + timeOff)){
    flagBz = true; 
  }
  else {
    flagBz = false;
    previousMillisBz = millis();
  }
  if (flagBz == true){
    if (millis() > (previousMillisBz + timeOn)){
      noTone(pin);
    }
    else{
      tone(pin, tones);
    }
  }
}
