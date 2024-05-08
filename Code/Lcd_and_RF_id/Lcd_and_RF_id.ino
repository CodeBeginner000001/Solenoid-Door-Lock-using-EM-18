#include <LiquidCrystal.h>
int rs=A5;
int en=A4;
int d4=A3;
int d5=A2;
int d6=A1;
int d7=A0;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int LOCK=2000;
int LCD_TIME=1500;
int originalNumber=23130;
int originalNumber2=12527;
char a[11];
int i;
int cardnum=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
lcd.begin(16,2);
}

void loop() 
{
lcd.setCursor(0,0);
lcd.print("   Welcome");
lcd.setCursor(0,1);
lcd.print("use code or card");

  
if(Serial.available())
{     i=0;
  
   while(Serial.available() && i < 12)
  { 
    a[i]= Serial.read();
    Serial.write(a[i]);
    i++;
    delay(1);
  }


 
for(i=6;i<10;i++)
 {
    if(a[i]>='0' && a[i]<='9')
     {
       cardnum=(cardnum*16)+a[i]-'0';
     }
    else
     {
      cardnum=(cardnum*16)+a[i]-'A'+10;
     }
 
}     
Serial.write(cardnum);
 if(cardnum==originalNumber || cardnum==originalNumber2   )
    { lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Card Is Right");
      lcd.setCursor(0,1);
      lcd.print("  Access Granted");
      digitalWrite(13,HIGH);
      delay(LOCK);
      digitalWrite(13,LOW);
      delay(LOCK);
      lcd.clear();
    }
 else
    { lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Card Is Wrong");
      lcd.setCursor(0,1);
      lcd.print("     No Access");
      delay(LCD_TIME);
      lcd.clear();
   }
}
  } 
