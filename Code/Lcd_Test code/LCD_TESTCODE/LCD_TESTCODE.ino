 #include <LiquidCrystal.h>
int rs=A5;
int en=A4;
int d4=A3;
int d5=A2;
int d6=A1;
int d7=A0;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("LCD  IS");
lcd.setCursor(0,1);
lcd.print("         WORKING");
}
