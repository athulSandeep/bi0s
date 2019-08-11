/*This program takes input from serial monitor 
and shows if the password is right or wrong.
PS:The password is 1234*/

String pass="1234";
String pass1;
void setup()
{
  Serial.begin(9600);

}

void loop()
{
  if(Serial.available())
  {
  pass1= Serial.readString();
  if (pass1==pass) {
    Serial.println("Correct Password");
  } else {
    Serial.println("Incorrect Password");
  }
  }  
  delay(10); // Delay a little bit to improve simulation performance
}