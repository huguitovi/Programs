#include <AFMotor.h>

AF_DCMotor Motor1(1);
AF_DCMotor Motor2(2);
AF_DCMotor Motor3(3);
AF_DCMotor Motor4(4);
 

void setup() 
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Motor1.setSpeed(200);
  Motor2.setSpeed(200);
  Motor3.setSpeed(200);
  Motor4.setSpeed(200);

}

void loop() 
{

  Motor1.run(RELEASE);
  Motor2.run(RELEASE);
  Motor3.run(RELEASE);
  Motor4.run(RELEASE);  
  delay (1000) ;

  Motor1.setSpeed(150);
  Motor2.setSpeed(150);
  Motor3.setSpeed(150);
  Motor4.setSpeed(150);
  Motor1.run(FORWARD);
  Motor2.run(BACKWARD);
  Motor3.run(FORWARD);
  Motor4.run(BACKWARD);
  delay (10000);

  Motor1.run(BACKWARD);
  Motor2.run(FORWARD);
  Motor3.run(BACKWARD);
  Motor4.run(FORWARD);
  delay (10000);
  
  Motor1.run(BACKWARD);
  Motor2.run(BACKWARD);
  Motor3.run(BACKWARD);
  Motor4.run(BACKWARD);   
  delay (10000);

  Motor1.run(FORWARD);
  Motor2.run(FORWARD);
  Motor3.run(FORWARD);
  Motor4.run(FORWARD);   
  delay (10000);
}
