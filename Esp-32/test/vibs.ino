

void vibs(int dl,int settings[5], int sensor)
{
  if (settings[0] == 1 and vib_status[0] == 1) 
  {
    digitalWrite(vib0, HIGH);
  }
  
    if (settings[1] == 1 and vib_status[1] == 1) 
  {
    digitalWrite(vib1, HIGH);
  }
  
    if (settings[2] == 1 and vib_status[2] == 1)
  {
    digitalWrite(vib2, HIGH);
  }
    if (settings[3] == 1 and vib_status[3] == 1)
  {
    digitalWrite(vib3, HIGH);
  }
    if (settings[4] == 1  and vib_status[4] == 1)
  {
    digitalWrite(vib4, HIGH);
  }
  if (sensor == buzzer_status[1] and buzzer_status[0] == 1)
  {
    tone(BUZZER, note);
  }

  ////////////////
  delay(2000/dl);
  ///////////////

  if (settings [0] == 1 and vib_status[0] == 1)
  {
    digitalWrite(vib0, LOW);
  }
  
    if (settings[1] == 1 and vib_status[1] == 1)
  {
    digitalWrite(vib1, LOW);
  }
  
    if (settings[2] == 1 and vib_status[2] == 1)
  {
    digitalWrite(vib2, LOW);
  }
    if (settings[3] == 1 and vib_status[3] == 1)
  {
    digitalWrite(vib3, LOW);
  }
    if (settings[4] == 1 and vib_status[4] == 1)
  {
    digitalWrite(vib4, LOW );
  }
    if (sensor == buzzer_status[1] and buzzer_status[0] == 1)
  {
    noTone(BUZZER);
  }
}
