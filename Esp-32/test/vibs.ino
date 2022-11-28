

void vibs(int dl, int pin)
{
  digitalWrite(pin, HIGH);
  delay(2000/dl);
  digitalWrite(pin, LOW);
}
