// taken from online to serve as a motor, H bridge, and arduino test. Don't actually use this for our final code.

// connect motor controller pins to Arduino digital pins
// Left Wheel Motor
int enA = 10;               //enable A pin connected to UNO pin 10 to enable LW Motor Driver
int in1 = 9;                //in1 pin connected to UNO pin 9 to control LW Motor
int in2 = 8;                //in2 pin connected to UNO pin 8 to control LW Motor
// Right Wheel Motor
int enB = 5;                //enable B pin connected to UNO pin 5 to enable RW Motor Driver
int in3 = 7;                //in3 pin connected to UNO pin 7 to control RW Motor
int in4 = 6;                //in4 pin connected to UNO pin 6 to control RW Motor

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  
  // turn on Left Wheel Motor
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // set speed to 180 out of possible range 0~255
  analogWrite(enA, 180);
  
  // turn on Right Wheel Motor
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  // set speed to 180 out of possible range 0~255
  analogWrite(enB, 180);
  delay(600);              //wait 600ms
 
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(600);
  
  //twist one way
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(600);
  
  //twist another
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  delay(600);
  
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void demoTwo()
{
  // this function will run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and the operating voltage
  // the PWM values sent by analogWrite() are fractions of the maximum speed possible 
  // by your hardware
  // turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  // accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  } 
  // decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  } 
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
}

void loop()
{
  demoOne();
  //demoTwo();    //will not run demoTwo at this stage
  delay(1000);    //wait 1 sec
}
