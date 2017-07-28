int flag;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(5,OUTPUT); //DCV 2 a
pinMode(6,OUTPUT);//DCV 2 b
pinMode(9,OUTPUT); //DCV 1 a
pinMode(10,OUTPUT); //DCV b
pinMode(13,INPUT); //Pushbutton for DCV 2 a

}

void loop() {
if(digitalRead(13)==HIGH)  //On press of a button
{
  digitalWrite(5,HIGH); //actuates Relay for clamper
  delay(10000);
  flag=1;
}

if(flag==1 && digitalRead(5)==HIGH)
  {
    digitalWrite(9,HIGH);  //actuates Relay for spindle 
    distance(); //step increment and decrement drilling
    flag=0;
  }
 

}

void distance()
{
  int a,b,dir; 
  b=a=dir=0;
  while(b!=10)
  {
    if(analogRead(A0)>900 && dir==0)
    {
      //code for actuating cyliner downwards 
      b++;
      if(b== 10)
        break;
      if(b-a == 5)
      {
        dir=1;
        a=b-3;
      }
    }
    if(analogRead(A0)>900 && dir==1)
    {
      //code for actuating cylinder upwards
      b--;
      if(a == b-3)
      {
        dir=0;
      }
    }
  }
}



/* DONT CARE
int distance()
{
  int count=0,flg;
  while(1)
  {
  if(analogRead(A0)>900)
  {
    count++;
    if(count==5)
    {
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH);  
      flg=1;
    }
    if(count==2&&flg==1)
    {
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);
      flg=2;      
    }
    if(count==7&&flg==2)
    {
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH); 
      flg=3;
    }
    if(count==4&&flg==3)
    { 
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);
      flg=4;
    }
    if(count==9&&flg==4)
    { 
      digitalWrite(9,LOW);
      digitalWrite(10,HIGH); 
    }
    
  }
  
    break;
  }
  return count;
}

*/




