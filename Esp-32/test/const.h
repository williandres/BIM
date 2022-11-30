///////// PINS //////////////

//ULTRASONIC SENSOR 1
const int trigPin_UP = 13;
const int echoPin_UP = 12;
//const int LED_UP = 26;
//const int LED_ERROR_UP = 25;
//ULTRASONIC SENSOR 2
const int trigPin_DOWN = 33;
const int echoPin_DOWN = 25;
//const int LED_DOWN = 15;
//const int LED_ERROR_DOWN = 32;

int sensor_status[2] = {1,1}; // [sensor1, sensor2]

//VIBRATION
const int vib0 = 4; //PULGAR 
const int vib1 = 5; 
const int vib2 = 18;
const int vib3 = 19;
const int vib4 = 21;

int vib_status[5] = {1,1,1,1,1};
int set_vib_s1[5] = {1,1,0,0,0};
int set_vib_s2[5] = {0,0,0,0,1};

//BUZZER
const int BUZZER = 2;
int note = 1000;
int buzzer_status[2] = {1,2}; // {ON/OFF, SENSOR ASSIGNED}


//LED
int led_status[2] = {1, 1}; // {ON/OFF, SENSOR ASSIGNED}
const int LED_ERROR = 23;
const int LED = 22;

//////////////////////////
#define SOUND_SPEED 0.034
long duration_UP;
long duration_DOWN;
float distanceCm_UP;
float distanceCm_DOWN;
float delay_led_UP;
float delay_led_DOWN;
char incoming;

// USER CONFIGURATION
int dist1 = 100;
int dist2 = 100;
