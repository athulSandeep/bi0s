/*This is the LCD monitor and the keypad task.
This program takes input from keypad and 
gives the output in the LCD monitor.
The password of the program is: 4321*/

#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(5, 4, 3, 2, A4, A5);

char Main[5]= "4321";
char cKey;
char pass[4];
byte count = 0; 
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rPins[4] = {A0, A1, 11, 10}; //connect to the row pinouts of the keypad
byte cPins[4] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(keys), rPins, cPins, 4, 4 );
void setup(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   
}

void loop(){
lcd.setCursor(0,0);
  lcd.print("Input Password");

  cKey = keypad.getKey();
  if (cKey)
  {
    pass[count] = cKey; 
    lcd.setCursor(count,1);
    lcd.print(pass[count]); 
    count++; 
  }

  if(count == 4)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
  

    if((pass[0]==Main[0])&& (pass[1]==Main[1])&& (pass[2]==Main[2])&&(pass[3]==Main[3]))
      lcd.print("ACCESS GRANTED");
    else
    {
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("WRONG PASSWORD");     
    }
    delay(1000);
    lcd.clear();
    clearData();   
  }
}

void clearData()
{
  while(count !=0)
  {  
    pass[count--] = 0;
  }
  return;
}
