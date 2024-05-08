
char a[11];
int i;
int cardnum=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{     i=0;
  
   while(Serial.available() && i < 12)
  { 
    a[i]= Serial.read();
    Serial.write(a[i]);
    i++;
    delay(1);
  }
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
    if(cardnum==23130)
    {
      
      Serial.print(cardnum);
      digitalWrite(13,HIGH);
      delay(1000);
      digitalWrite(13,LOW);
      delay(1000);
    }
  } 
