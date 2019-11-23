/*
Author: Angelica Smith-Evans
        (add your name if you worked on this!)

The purpose of this code is to control the pathing of the robot but receiving 
input from proximity sensors, and changing the direction of the robot's 
trajectory through the motor control.

This code is currently in it's bare bones stages. I've written so far what needs to be completed
*/

//////////////////////////////////////////////////////////////////////////////////////
//                        Variable Declaration Section                              //
//////////////////////////////////////////////////////////////////////////////////////
//Speed Control
//**need to do: make sure these configurations work
  int vSpeed = 110;        // MAX 255
  int turn_speed = 180;    // MAX 255 
  int turn_delay = 10;
  
//Motor Control Connections
// Left Wheel Motor
  int enA = 10;               //enable A pin connected to UNO pin 10 to enable LW Motor Driver
  int in1 = 9;                //in1 pin connected to UNO pin 9 to control LW Motor
  int in2 = 8;                //in2 pin connected to UNO pin 8 to control LW Motor
// Right Wheel Motor
  int enB = 5;                //enable B pin connected to UNO pin 5 to enable RW Motor Driver
  int in3 = 7;                //in3 pin connected to UNO pin 7 to control RW Motor
  int in4 = 6;                //in4 pin connected to UNO pin 6 to control RW Motor

//Proximity Sensor Connections
//**need to do: make sure these connections match the board
  const int front_left_IR = A0;             // connect the front left IR sensor to pin A0
  const int front_right_IR = A1;            // connect the front right IR sensor to pin A1
  int front_left_IR_state = 0;              // variable to store the values from front left sensor
  int front_right_IR_state = 0;             // variable to store the values from front right sensor

//////////////////////////////////////////////////////////////////////////////////////
//                                Pin Set-up Section                                //
//////////////////////////////////////////////////////////////////////////////////////
void setup() 
{
  //**need to do: make sure these connections match the board
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);                       // starts the serial monitor (data rate=9600bps)  
  delay(3000);                              // wait 3 seconds before starting main code execution
}

//////////////////////////////////////////////////////////////////////////////////////
//                             Pathing Control Section                              //
//////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  
//**need to do: implement the code as i envisioned it
//step 1: line following of 2 IR sensors (on front of chassis)
//step 2: implement a mode bit which traces if bot moving forward or backward
//        implement a counter which traces the mode bit switching to trace current point of the robot

  
front_left_IR_state = analogRead(front_left_IR);// reads the value of the sharp sensor
front_right_IR_state = analogRead(front_right_IR);

//checks for line detection from the left side IR sensor
if(front_right_IR_state > 500 && front_left_IR_state < 500)
  {
  Serial.println("turning right");

  digitalWrite (in1,LOW);
  digitalWrite(in2,HIGH);                       
  digitalWrite (in3,LOW);
  digitalWrite(in4,HIGH);

  analogWrite (enA, vSpeed);
  analogWrite (enB, turn_speed);
  }
  
//checks for line detection from the left side IR sensor
if(front_right_IR_state < 500 && front_left_IR_state > 500)
  {
  Serial.println("turning left");
  
  digitalWrite (in1,HIGH);
  digitalWrite(in2,LOW);                       
  digitalWrite (in3,HIGH);
  digitalWrite(in4,LOW);

  analogWrite (enA, turn_speed);
  analogWrite (enB, vSpeed);

  delay(turn_delay);
  }
  
//checks for no line detection from either side
if(front_right_IR_state > 500 && front_left_IR_state > 500)
  {
  Serial.println("going forward");

  digitalWrite(in1,HIGH); 
  digitalWrite (in2,LOW);                      
  digitalWrite(in3,LOW);
  digitalWrite (in4,HIGH);
 
  analogWrite (enA, vSpeed);
  analogWrite (enB, vSpeed);

  delay(turn_delay);
  }

//checks for line detection from both sides and stops robot if true
if(front_right_IR_state < 500 && front_left_IR_state < 500)
  { 
  Serial.println("stop");
  
  analogWrite (enA, 0);
  analogWrite (enB, 0);
  } 
  
}//end of main

