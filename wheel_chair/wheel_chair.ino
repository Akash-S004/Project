int a = 13; 
int b = 12; 
int c = 10;
int d= 9;
int sel =40;

int aa=7;
int bb=6;
int cc=5;
int dd=4;

int sensorpin1 = 0;  
int sensorpin2 = 1;                 
int vals1 = 0;
int vals2 = 0;
    

int sensorValue;
int sensorValue1;
int sensorValue2;
int sensorValue3;
int sell;

byte com = 0; 

void setup()
{
pinMode(aa,INPUT);
pinMode(bb,INPUT);
pinMode(cc,INPUT);
pinMode(dd,INPUT);
pinMode(sel,INPUT);
Serial.begin(9600);
pinMode(a, OUTPUT); // sets the ledPin to be an output
pinMode(b, OUTPUT); // sets the redPin to be an output
pinMode(c, OUTPUT); // sets the ledPin to be an output
pinMode(d, OUTPUT); 
delay(2000);
Serial.write(0xAA);
Serial.write(0x37);
delay(1000);
Serial.write(0xAA);
Serial.write(0x22);
}

void loop() 
{
  sell=digitalRead(sel);
  vals1 = analogRead(sensorpin1); 
  vals2 = analogRead(sensorpin2); 
 
  if(vals1<110 | vals2<200)
  {
    if(sell==1)
    {
    while(Serial.available())
    {
      com = Serial.read();
      switch(com)
      {
        case 0x21:
        digitalWrite(a,HIGH);
        digitalWrite(b,LOW);
        digitalWrite(c,HIGH);
        digitalWrite(d,LOW);
        break;

        case 0x22:
        digitalWrite(a,LOW);
        digitalWrite(b,HIGH);
        digitalWrite(c,LOW);
        digitalWrite(d,HIGH);
        break;

        case 0x23:
        digitalWrite(a,LOW);
        digitalWrite(b,LOW);
        digitalWrite(c,HIGH);
        digitalWrite(d,LOW);
        break;
      
        case 0x24:
        digitalWrite(a,HIGH);
        digitalWrite(b,LOW);
        digitalWrite(c,LOW);
        digitalWrite(d,LOW);
        break;
      
       case 0x25:
        digitalWrite(a,LOW);
        digitalWrite(b,LOW);
        digitalWrite(c,LOW);
        digitalWrite(d,LOW);
        break;
      }
    }
  }
  if(sell==0)
    {
      sensorValue = digitalRead(aa);
      sensorValue1 = digitalRead(bb);
      sensorValue2 = digitalRead(cc);
      sensorValue3 = digitalRead(dd);

   if(sensorValue==1)
 { 
   
  digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
 }

 else if(sensorValue1==1)
 { 
  
  digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,HIGH);
 digitalWrite(d,LOW);
   
 }
  
  else if(sensorValue2==1)
 { 

  digitalWrite(a,HIGH);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
   
   }
   
  else if(sensorValue3==1)
 { 

  digitalWrite(a,LOW);
 digitalWrite(b,HIGH);
 digitalWrite(c,LOW);
 digitalWrite(d,HIGH);
 
   }
  
  else
{ 
  digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
}
        
 
  }
  }
  else
  {
 digitalWrite(a,LOW);
 digitalWrite(b,LOW);
 digitalWrite(c,LOW);
 digitalWrite(d,LOW);
  }
  
  }
