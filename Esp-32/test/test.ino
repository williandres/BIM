//ULTRASONIC SENSOR 1
const int trigPin_UP = 27;
const int echoPin_UP = 26;
const int LED_UP = 19;
const int LED_ERROR_UP = 21;
//ULTRASONIC SENSOR 2
const int trigPin_DOWN = 25;
const int echoPin_DOWN = 33;
const int LED_DOWN = 22;
const int LED_ERROR_DOWN = 23;



//define sound speed in cm/uS
#define SOUND_SPEED 0.034

long duration_UP;
long duration_DOWN;
float distanceCm_UP;
float distanceCm_DOWN;
float delay_led_UP;
float delay_led_DOWN;

 

void setup() {
  Serial.begin(115200); // Starts the serial communication
  // ULTRASONIC SENSOR 1
  pinMode(trigPin_UP, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_UP, INPUT); // Sets the echoPin as an Input
  pinMode(LED_UP, OUTPUT); // Green LED
  pinMode(LED_ERROR_UP, OUTPUT); // Error LED 
  // ULTRASONIC SENSOR 2
  pinMode(trigPin_DOWN, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_DOWN, INPUT); // Sets the echoPin as an Input
  pinMode(LED_DOWN, OUTPUT); // Green LED
  pinMode(LED_ERROR_DOWN, OUTPUT); // Error LED 
}

void loop() {
  // * ULTRASONIC SENSOR 1 - 2 *
  // Clears the trigPin
  digitalWrite(trigPin_UP, LOW);
  digitalWrite(trigPin_DOWN, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin_UP, HIGH);
  digitalWrite(trigPin_DOWN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_UP, LOW);
  digitalWrite(trigPin_DOWN, LOW);

  

  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration_UP = pulseIn(echoPin_UP, HIGH); //ULTRASONIC SENSOR 1
  //duration_DOWN = pulseIn(echoPin_DOWN, HIGH); //ULTRASONIC SENSOR 2
  
  // Calculate the distance
  distanceCm_UP = duration_UP * SOUND_SPEED/2; //ULTRASONIC SENSOR 1
  distanceCm_DOWN = duration_DOWN * SOUND_SPEED/2; //ULTRASONIC SENSOR 2

  // * ULTRASONIC SENSOR 1 *
  // Prints the distance in the Serial Monitor 
  // Green LED twinkle means distance
  // Red LED means a mistake in the data capturing
  Serial.print("SENSOR 2 --- Distance (cm): ");
  Serial.println(distanceCm_DOWN);
  if (distanceCm_UP < 500)
    {
    digitalWrite(LED_ERROR_UP, LOW);
    delay_led_UP = distanceCm_UP * 2;
    Serial.print("SENSOR 1 --- Distance (cm): ");
    Serial.println(distanceCm_UP);
    digitalWrite(LED_UP, HIGH);
    delay(delay_led_UP);
    digitalWrite(LED_UP, LOW);
    delay(delay_led_UP); 
    }
  else{
    digitalWrite(LED_ERROR_UP, HIGH);
    Serial.print("SENSOR 1 --- Error ---> "); 
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm_UP);
    }

  // * ULTRASONIC SENSOR 2 *
  // Prints the distance in the Serial Monitor 
  // Green LED twinkle means distance
  // Red LED means a mistake in the data capturing
   
  }
