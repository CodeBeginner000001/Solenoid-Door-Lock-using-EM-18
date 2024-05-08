# include<LiquidCrystal.h>
#include <Keypad.h>
#define RELAYPIN 2
#define Length 7          // give enough room for six chars + null

char Data[Length];            // to compare to the master password
char Master[Length]="123456";  // master password code
byte data_count = 0;
char customKey;

const byte ROWS = 3;
const byte COLS = 3;
char keys[ROWS][COLS]= {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
};

byte rowPins[ROWS] = {5,6,7};
byte colPins[COLS] = {8,9,10};

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);  


int rs=A5;
int en=A4;
int d4=A3;
int d5=A2;
int d6=A1;
int d7=A0;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


void setup() {
  // put your setup code here, to run once:
pinMode(RELAYPIN,OUTPUT);
Serial.begin(9600);
lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
customKey = customKeypad.getKey();
lcd.setCursor(0,0);
lcd.print("   Welcome");
lcd.setCursor(0,1);
lcd.print("use code or card");
Open();
}
void Open(){
if (customKey)
{
  
 
  Data[data_count] = customKey;
 
  data_count++;
}
if(data_count==Length-1)
{
 

  if(!strcmp(Data, Master))
  { 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pass Is Good");
    lcd.setCursor(0,1);
    lcd.print("Access Granted");
    digitalWrite(RELAYPIN,HIGH);
    delay(5000);
    digitalWrite(RELAYPIN,LOW);
    lcd.clear();
  }
  else
  { lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pass is wrong");
    lcd.setCursor(0,1);
    lcd.print("Not Granted");
    delay(3000);
    lcd.clear();
  }
 clearData();
 
  }
}





void clearData()
{
  while(data_count !=0)
  {
    Data[data_count--]=0;
  }
  return ;
}
