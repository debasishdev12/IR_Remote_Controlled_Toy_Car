#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

const int reverseMotorA = 3;   //5
const int reverseMotorB = 5;   //11
const int forwardMotorA = 1;   //3
const int forwardMotorB = 2;   //4
const int headLight = 7;       //13
const int taleLight = 4;       //6
const int brakeLight = 10;     //16
const int horn = 9;            //15
const int reverseLight = 8;
int velocity = 250;

void setup()
{
  //Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(reverseMotorA,OUTPUT);
  pinMode(reverseMotorB,OUTPUT);
  pinMode(forwardMotorA,OUTPUT);
  pinMode(forwardMotorB,OUTPUT);
  pinMode(headLight,OUTPUT);
  pinMode(taleLight,OUTPUT);
  pinMode(brakeLight,OUTPUT);
  pinMode(reverseLight,OUTPUT);
  pinMode(horn,OUTPUT);
  
  digitalWrite(reverseMotorA,LOW);
  digitalWrite(reverseMotorB,LOW);
  digitalWrite(forwardMotorA,LOW);
  digitalWrite(forwardMotorB,LOW);
  digitalWrite(headLight,LOW);
  digitalWrite(taleLight,LOW);
  digitalWrite(brakeLight,LOW);
  digitalWrite(reverseLight,LOW);
  digitalWrite(horn,LOW);
}

void loop()
{
 if (irrecv.decode(&results))
 {
   if(results.value == 0xFF02FD)
   {
     digitalWrite(reverseLight,LOW);
     digitalWrite(brakeLight,LOW);
     digitalWrite(reverseMotorA,HIGH);
     digitalWrite(reverseMotorB,LOW);
     
     //Serial.println("Move Forward");
   }
   if(results.value == 0xFF9867)
   {
     digitalWrite(reverseLight,HIGH);
     digitalWrite(brakeLight,LOW);
     digitalWrite(reverseMotorA,LOW);
     digitalWrite(reverseMotorB,HIGH);
     
     //Serial.println("Move Backward and reverse Light on");
   }
   if(results.value == 0xFF22DD)
   {
     digitalWrite(headLight,HIGH);
     //Serial.println("Headlight On");
   }
   if(results.value == 0xFFC23D)
   {
     digitalWrite(headLight,LOW);
     //Serial.println("Headlight Off");
   }
   if(results.value == 0xFF6897)
   {
     digitalWrite(taleLight,HIGH);
     //Serial.println("Talelight On");
   }
   if(results.value == 0xFFB04F)
   {
     digitalWrite(taleLight,LOW);
     //Serial.println("Talelight Off");
   }
   if(results.value == 0xFF629D)
   {
     digitalWrite(horn,HIGH);
     delay(185);
     digitalWrite(horn,LOW);
     //Serial.println("Horn Blow for 1 second");
   }
   if(results.value == 0xFFE01F)
   {
     digitalWrite(forwardMotorA,LOW);
     digitalWrite(forwardMotorB,HIGH);
     //Serial.println("Left Turn");
   }
   if(results.value == 0xFF906F)
   {
     digitalWrite(forwardMotorA,HIGH);
     digitalWrite(forwardMotorB,LOW);
     //Serial.println("Right Turn");
   }
   if(results.value == 0xFFA857)
   {
     digitalWrite(forwardMotorA,LOW);
     digitalWrite(forwardMotorB,LOW);
     //Serial.println("Straight");
   }
   if(results.value == 0xFFA25D)
   {
     digitalWrite(brakeLight,HIGH);
     digitalWrite(reverseMotorA,LOW);
     digitalWrite(reverseMotorB,LOW);
     //Serial.println("Brake");
   }
   irrecv.resume();
 }
 delay(10);
}
