
#include "pitches.h"

#define BUZZER 18   // buzzer pasivo en pin 18


int melody[] = {   // array con las notas de la melodia
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int durations[] = {    
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  pinMode(BUZZER, OUTPUT); 
 
}

void loop() {
  for (int i = 0; i < 8; i++)
  {     
    int duration = 1000 / durations[i];    // duracion de la nota en milisegundos
    tone(BUZZER, melody[i], duration);  // ejecuta el tono con la duracion
    int pause = duration * 1.30;      // calcula pausa
    delay(pause);         // demora con valor de pausa
    noTone(BUZZER);        // detiene reproduccion de tono
  }
}
