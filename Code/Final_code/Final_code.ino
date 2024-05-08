# include <LiquidCrystal.h>
#include <Keypad.h>
#define RELAYPIN 2         // Pin in arduino.
#define Length 7            // set the length.
int rs = A5;
int en = A4;
int d4 = A3;               // from (int rs) to (int d7) used for arduino.
int d5 = A2;
int d6 = A1;
int d7 = A0;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int LOCK=2000;            // Time set for relay.
int LCD_TIME=1500;        // Time to delay the lcd display text.

int originalNumber=23130;     // following two card numbers are the last five digit number on card.
int originalNumber2=12527;
char a[11];                  // array to store the value from card.
int i;
int cardnum=0;

char Data[Length];            // to compare to the master password
char Master[Length]="123456";  // master password code
byte data_count = 0;
char customKey;

const byte ROWS = 3;                 // Rowa and Columns for keypad
const byte COLS = 3;
char keys[ROWS][COLS]= {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
};

byte rowPins[ROWS] = {5,6,7};
byte colPins[COLS] = {8,9,10};

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);  



void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);                      // to begin writting in LCD Display.
Serial.begin(9600);                   // Serial monitor.
pinMode(RELAYPIN,OUTPUT);             // To power the arduino pin.
}



void loop() {
  // put your main code here, to run repeatedly:
  // main body starts here.
customKey = customKeypad.getKey();
lcd.setCursor(0,0);                 //1
lcd.print("   Welcome");            //2
lcd.setCursor(0,1);                 //3                          // lines from 1 to 4 are used to set the cursor on display and write the text.
lcd.print("use code or card");      //4
if(customKey)
{
  Open();// function called from bottom.
  lcd.clear();
}

if(Serial.available())                  // if data available in serial monitor then store the 12 digit number from card in the array.
{     i=0;
  
   while(Serial.available() && i < 12)
  { 
    a[i]= Serial.read();
    Serial.write(a[i]);
    i++;
    delay(1);
  }
  card(); // function called from bottom.
  lcd.clear(); 
}
  
}            // main body ends here.


void Open(){  // function made to call in main function.
  
if (customKey)                    // if customkey is available.
{
 Data[data_count] = customKey;     //store the data in the array data[data_count].
 data_count++;
}

if(data_count==Length-1)           // if data_count is equal to length-1 i.e 6 numbers from keypad.
{  if(!strcmp(Data, Master))       // compare the data and master key and if equal then do the needful. 
   // strcmp is used to compare the two string or integer number.
  { 
    lcd.clear();                  // To clear the displayed text on lcd to print new
    lcd.setCursor(0,0);
    lcd.print("Pass Is Good");
    lcd.setCursor(0,1);
    lcd.print("Access Granted"); 
    digitalWrite(RELAYPIN,HIGH);     //  the power to the pin
    delay(5000);                      // power will flow for 5 sec.
    digitalWrite(RELAYPIN,LOW);// To stop the power in pin
    delay(5000);                   
  }
  else
  { lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pass is wrong");
    lcd.setCursor(0,1);
    lcd.print("Not Granted");
    delay(2000);                 // displayed only for 2 sec.
    
  }
 clearData();      // call the function from bottom
 
  }
}



void card(){
for(i=6;i<10;i++)                               // for is used run a loop for 6 to 9 value that is stored in array a[11] i.e it will pick the value from 6 to 9 that is stored in array
 {
    if(a[i]>='0' && a[i]<='9')                   // To convert hexdecimal number to decimal number
     {
       cardnum=(cardnum*16)+a[i]-'0';            // for digit 
     }
    else
     {
      cardnum=(cardnum*16)+a[i]-'A'+10;         // for alphabet
     }
}     
Serial.write(cardnum);                        // to print the decimal number that is converted from hexdecimal
if(cardnum==originalNumber || cardnum==originalNumber2   )          // if cardnum is equal to the number on card then do the needful
    { lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Card Is Right");
      lcd.setCursor(0,1);
      lcd.print("  Access Granted");
      digitalWrite(RELAYPIN,HIGH);
      delay(LOCK);
      digitalWrite(RELAYPIN,LOW);
      delay(LOCK);
      
    }
 else
    { lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Card Is Wrong");
      lcd.setCursor(0,1);
      lcd.print("     No Access");
      delay(LCD_TIME);
      
   }
}


void clearData()                                         // to clear the coming data after use of data from keypad.
{
  while(data_count !=0)
  {
    Data[data_count--]=0;
  }
  return ;
}
