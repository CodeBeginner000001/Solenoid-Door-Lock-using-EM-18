


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

byte rowPins[ROWS] = {
  5,6,7};
byte colPins[COLS] = {
  8,9,10};

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);  


void setup() {
  // put your setup code here, to run once:
pinMode(RELAYPIN,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
customKey = customKeypad.getKey();
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
    
    digitalWrite(RELAYPIN,HIGH);
    delay(2000);
    digitalWrite(RELAYPIN,LOW);
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
