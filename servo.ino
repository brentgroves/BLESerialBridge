#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
int ledpin=13;
void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}
void loop()
{
  int i,j,k,l,m,done;
   
  if (mySerial.available())
  {
    i = mySerial.parseInt();  
    j = mySerial.parseInt();  
    k = mySerial.parseInt();  
    l = mySerial.parseInt();  
    m = mySerial.parseInt();  
 //   done = mySerial.parseInt();
//    if(done==9)
//    {
//      mySerial.flush(); 
//      Serial.println("Received 9:");
//    } 
    if(mySerial.read() == '\n'){              // if the last byte is '\n' then stop reading and execute command '\n' stands for 'done'
        mySerial.flush();                     //clear all other commands piled in the buffer
        mySerial.print('d');                  //send completion of the command "d" stands for "done executing"
    Serial.println("Received newline:");
      
    }    
//    i=mySerial.read();
//    Serial.println(mySerial.read());
    Serial.println("DATA RECEIVED:");
    Serial.println(i);
    Serial.println(j);
    Serial.println(k);
    Serial.println(l);
    Serial.println(m);
    if(i==1)
    {
      digitalWrite(ledpin,1);
      Serial.println("led on");
    }
    if(i==0)
    {
      digitalWrite(ledpin,0);
      Serial.println("led off");
    }
  }
}