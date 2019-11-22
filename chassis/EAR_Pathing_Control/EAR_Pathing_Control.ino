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
  int turn_speed = 230;    // MAX 255 
  int turn_delay = 10;
  
//Motor Control Connections
//**need to do: make sure these connections match what's on the board
  const int motorA1      = 8;  
  const int motorA2      = 10; 
  const int motorAspeed  = 9;
  const int motorB1      = 12; 
  const int motorB2      = 13; 
  const int motorBspeed  = 11;

//Proximity Sensor Connections
//**need to do: make sure these connections match the board
  const int left_sensor_pin =A0; // analog pin used to connect the sharp sensor
  const int right_sensor_pin =A1; 
  int left_sensor_state = 0; // variable to store the values from sensor(initially zero)
  int right_sensor_state = 0;

//////////////////////////////////////////////////////////////////////////////////////
//                                Pin Set-up Section                                //
//////////////////////////////////////////////////////////////////////////////////////
void setup() 
{
  //**need to do: make sure these connections match the board
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);

  delay(3000);
}

//////////////////////////////////////////////////////////////////////////////////////
//                             Pathing Control Section                              //
//////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  
//**need to do: implement the code as i envisioned it
//step 1: line following of 2 IR sensors (on front of chassis)
//step 2: line following of 2 IR sensors (on back of chassis)
//step 3: line following of all 4 IR sensors (on front and back)
//        implement a mode bit which traces if bot moving forward or backward
//        implement a counter which traces the mode bit switching to trace current point of the robot

  
left_sensor_state = analogRead(left_sensor_pin);// reads the value of the sharp sensor
right_sensor_state = analogRead(right_sensor_pin);

//checks for line detection from the left side IR sensor
if(right_sensor_state > 500 && left_sensor_state < 500)
  {
  Serial.println("turning right");

  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);
  }
  
//checks for line detection from the left side IR sensor
if(right_sensor_state < 500 && left_sensor_state > 500)
  {
  Serial.println("turning left");
  
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }
  
//checks for no line detection from either side
if(right_sensor_state > 500 && left_sensor_state > 500)
  {
  Serial.println("going forward");

  digitalWrite (motorA2,LOW);
  digitalWrite(motorA1,HIGH);                       
  digitalWrite (motorB2,HIGH);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

//checks for line detection from both sides and stops robot if true
if(right_sensor_state < 500 && left_sensor_state < 500)
  { 
  Serial.println("stop");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
  } 
  
}//end of main
