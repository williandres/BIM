const int vib = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(vib, OUTPUT);

}

void loop() {
  digitalWrite(vib, HIGH);

}
