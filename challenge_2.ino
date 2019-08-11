/*This is the temperature sensor program.
Once the temperature gets above 26 degree celsius 
the LED lights up and turns off if it gets below 26*/

int temp = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  temp = -40 + 0.488155 * (analogRead(A0) - 20);
  if (temp > 26) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}