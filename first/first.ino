#include <Servo.h> 
char x; 
Servo myservo; 
                
 
int pos = 0;    
 
void setup() 
{ 
 // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
} 
 
 
void loop() 
{
 if(Serial.available())
{
 x=Serial.read();
if(x=='a')
{
    myservo.attach(9); 
                                  // in steps of 1 degree 
    myservo.write(110);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
 
}
if(x=='b')
{
    myservo.attach(9); 
                                  
    myservo.write(90);              // tell servo to go to position in variable 'pos' 
                     // waits 15ms for the servo to reach the position 
  
} 
if(x=='c')
{
myservo.detach(); 
  
}
}
}
