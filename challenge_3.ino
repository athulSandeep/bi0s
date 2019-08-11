/*This is the 2*2 LED matrix program.
In this program we can individually control each LED.
To do so we have to type r (for red), g (for green),
b (for blue) and y (for yellow).(note that it is case sensitive)
By pressing each key into serial input we can turn on or 
off the LED's*/


char inpt = 'a';

int R = 0;

int G = 0;

int B = 0;

int Y = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  inpt='a';
if(Serial.available())
  {
  inpt = Serial.read();
  if (inpt == 'r') {
    R += 1;
  }
  if (inpt == 'g') {
    G += 1;
  }
  if (inpt == 'b') {
    B += 1;
  }
  if (inpt == 'y') {
    Y += 1;
  }
  if (R %2==0) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  if (G %2==0) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(11, LOW);
  }
  if (B %2==0) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  if (Y %2==0) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
}
  delay(10); // Delay a little bit to improve simulation performance
}