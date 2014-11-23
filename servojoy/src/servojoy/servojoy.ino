#include <Servo.h>

Servo servo;
int angle;

void setup()
{
  Serial.begin(9600);  
  servo.attach(4);
  servo.write(90);
}

void loop()
{
  if( Serial.available() > 0 )
  {
    angle = Serial.read();
    if(angle < 10 || angle > 170)
    {
      angle = 90;
    }
    servo.write(angle);
  }
}
