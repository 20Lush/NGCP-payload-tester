#include <Servo.h>

Servo door, drop1, drop2;
int btn1 = 12, btn2 = 11;

bool initServos = true, diagnostic = true;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  delay(3000);

  door.attach(A0);
  drop1.attach(A1);
  drop2.attach(A2);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  if(initServos){

    door.writeMicroseconds(microSecondsConvert(0));
    drop1.writeMicroseconds(microSecondsConvert(0));
    drop2.writeMicroseconds(microSecondsConvert(0));

  }

  Serial.println("==");
  Serial.println("----------- initialized servos -----------");
  Serial.print("door: ");
  Serial.print(door.read());
  Serial.print(" drop1: ");
  Serial.print(drop1.read());
  Serial.print(" drop2: ");
  Serial.println(drop2.read());
  Serial.println("------------------------------------------");
  Serial.println("==");

  delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(!diagnostic){
    if(!digitalRead(btn1)){ // run open

    }

    else if(!digitalRead(btn2)){ // reset to close

    }

    else{ // default the values

    }
  }

  else{

    Serial.print("door: ");
    Serial.print(door.read());
    Serial.print(" drop1: ");
    Serial.print(drop1.read());
    Serial.print(" drop2: ");
    Serial.println(drop2.read());

  }
  


}

int servoConvert(int angle){

  return map(angle, 0, 270, 0, 180);

}

int microSecondsConvert(int angle){

  return map(angle, 0, 270, 544, 2400);

}

void trueAngleTo(Servo servo, int angle){ //0 - 180 shifted for 270deg servos

  angle = microSecondsConvert(angle);
  servo.writeMicroseconds(angle);
  
}

void feedForwardSlew(Servo servo, int angle, int step = 1){

  int curr = servo.read();
  int delta = angle - curr;
  int pol = delta/(abs(delta));

  for(int i = 0; i < abs(delta); i+step){

    servo.writeMicroseconds(microSecondsConvert(curr + (i*pol)));

  }

}
