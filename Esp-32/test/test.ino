const int trigPin = 5;
const int echoPin = 18;
const int LED = 19;
const int LED_ERROR = 21;
//define sound speed in cm/uS
#define SOUND_SPEED 0.034

long duration;
float distanceCm;
float delay_led;
 

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(LED, OUTPUT); // Led
  pinMode(LED_ERROR, OUTPUT); // Led error 
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  if (distanceCm < 500){
    digitalWrite(LED_ERROR, LOW);
    delay_led = distanceCm*3;
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm);
    digitalWrite(LED, HIGH);
    delay(delay_led);
    digitalWrite(LED, LOW);
    delay(delay_led); 
    }
  else{
    digitalWrite(LED_ERROR, HIGH);
    Serial.print("Error ---> "); 
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm);
    }
  delay(10);
  }

/* Si la distancia es mayor a 2000 cm significa que el sensor esta mal posicionado y registrando erroneamente
 * El sensor tiene conflictos cuando apunta a las esquinas
 * 
 * , por las ondas que emite el sensor
 * 
 * 
 * 
 */
