#include <Servo.h>
#include <IRremote.h>

int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);    
decode_results results;    

Servo myservobase;  
Servo myservoarm1;  
Servo myservoarm2;  
Servo myservogrip;  

int pos1 = 90;    // variable to store the servo position
int pos2 = 90;
int pos3 = 90;
int pos4 = 0;
int multi = 4;
int value;

int status1 = 0;
int status2 = 0;
int status3 = 0;

void setup(){
  Serial.begin(9600);    
  irrecv.enableIRIn();
 
  myservobase.attach(2);  // attaches the servo on pin 9 to the servo object
  myservoarm1.attach(3);
  myservoarm2.attach(4);
  myservogrip.attach(5);
}

void loop()
{  
 if (irrecv.decode(&results)){      
 value = results.value;
   
   switch(value){    
    case 0XFF6897:  
     if(status1 < 1)
      {
       status1++;
      }  
     break;
     
    case 0xFF30CF:      
     if(status2 < 1)    
      {
       status2++;
      }  
     break;
     
    case 0xFF18E7:    
     if(status3 < 1)
      {
       status3++;
      }  
     break;
 
    case 0xFF7A85:
     if(status1 > -1)
      {
       status1--;                    
      }
     break;
 
    case 0xFF10EF:
     if(status2 > -1)
      {
       status2--;                    
      }
     break;
     
    case 0xFF38C7:
     if(status3 > -1)
      {
       status3--;
      }
     break;
       
    case 0xFFE01F:
      if(4 < multi)
       {
        multi-=2;
       }
    break;
     
    case 0xFFA857:
       if(multi < 20)
       {
        multi+=2;
       }
   }
 }
   //Serial.println(pos1);
   //Serial.println(multi);
   irrecv.resume();
   Serial.println("--------");
   Serial.println(value);
   Serial.println(status1);
   Serial.println(status2);
   Serial.println(status3);
   Serial.println("--------");
 
   //The Spinning code lol
   if(status1 == 1)
    {
     if(pos1 <= 180)
       {
       pos1+=multi;
       myservobase.write(pos1);
       }  
    }  
         
    if(status2 == 1){
        if(pos2 <= 180)
         {
         pos2+=multi;
         pos3+=multi;
         myservoarm1.write(pos2);
         myservoarm2.write(pos3);
         delay(15);
        }  
      }  

     if(status3 == 1)
      {
       if(pos4 <= 90)
        {
         pos4+=multi;
         myservogrip.write(pos4);
         delay(15);
        }  
      }  

     if(status1 == -1)
      {
         if(pos1 >= 0)
        {
         pos1-=multi;
         myservobase.write(pos1);            
         delay(15);                      
        }                    
      }

     if(status2 == -1)
      {
       if(pos2 >= 0)
        {
         pos2-=multi;
         pos3-=multi;
         myservoarm1.write(pos2);
         myservoarm2.write(pos3);  
         delay(15);                      
        }                      
      }
   
     if(status3 == -1)
      {
       if(pos4 >= 0)
        {
         pos4-=multi;
         myservogrip.write(pos4);            
         delay(15);  
        }
      }
   
   
}
