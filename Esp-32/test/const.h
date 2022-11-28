///////// PINS //////////////



//ULTRASONIC SENSOR 1
const int trigPin_UP = 13;
const int echoPin_UP = 12;
const int LED_UP = 26;
const int LED_ERROR_UP = 25;
//ULTRASONIC SENSOR 2
const int trigPin_DOWN = 14;
const int echoPin_DOWN = 27;
const int LED_DOWN = 15;
const int LED_ERROR_DOWN = 32;
const int BUZZER = 2;

//VIBRATION
const int vib0 = 4; //PULGAR 
const int vib1 = 5; 
const int vib2 = 18;
const int vib3 = 19;
const int vib4 = 21;

int set_vib_s1[5] = {0,1,0,1,1};
int set_vib_s2[5] = {0,0,0,0,0};

//BUZZER
int resolution = 8;
int channel = 0;

//////////////////////////
#define SOUND_SPEED 0.034
long duration_UP;
long duration_DOWN;
float distanceCm_UP;
float distanceCm_DOWN;
float delay_led_UP;
float delay_led_DOWN;
char incoming;


///////STATUS///////
bool bzStatus = true;
bool s1Status = true;
bool s2Status = true;

bool v0Status = true;
bool v1Status = true;
bool v2Status = true;
bool v3Status = false;
bool v4Status = false;
