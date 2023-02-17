#include <Servo.h>

Servo door, drop;
int btn1 = 12, btn2 = 11;

bool initServos = false;


void setup() {
  // put your setup code here, to run once:

  door.attach(A0);
  drop.attach(A1);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  if(initServos){

    door.writeMicroseconds(microSecondsConvert(0));
    drop.writeMicroseconds(microSecondsConvert(0));

  }

}

void loop() {
  // put your main code here, to run repeatedly:

  if(!digitalRead(btn1)){
    door.write(servoConvert(90));
    delay(2000);
    drop.write(servoConvert(270));
    delay(2000);
  }

  else if(!digitalRead(btn2)){
    drop.write(servoConvert(0));
    delay(2000);
    door.write(servoConvert(0));
    delay(2000);
  }

  else{
    door.write(servoConvert(0));
    drop.write(servoConvert(0));
  }
  


}

int servoConvert(int angle){

  return map(angle, 0, 270, 0, 180);

}

int micr0SecondsConvert(int angle){

  return map(angle, 0, 270, 544, 2400);

}
