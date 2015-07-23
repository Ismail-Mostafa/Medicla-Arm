// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo
Servo arm;
int current=0; 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
int old=0;
int constval;
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
current=analogRead(5);
if(current>80)
{
constval=val; 
current=analogRead(5);
arm.attach(10);
constval = (constval*0.27);
arm.write((210-constval));
//Serial.println((210-val));
delay(50); 

old=val;
  // waits for the servo to get there 
}
 
else
{
  val = analogRead(potpin);
arm.detach();  
val = (val*0.27);
if(old-val<2&&old-val>-2)
{
myservo.write((210-val));
//Serial.println((210-val));
delay(50); 
}
old=val;
  // waits for the servo to get there 
}
}
