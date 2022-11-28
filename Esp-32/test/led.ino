
void led(int dly, int pinl)
{
  digitalWrite(pinl, HIGH);
  delay(dly*(3/2));
  digitalWrite(pinl, LOW);
}
