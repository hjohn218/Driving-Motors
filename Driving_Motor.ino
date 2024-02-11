
/*
*Motor driving code from Arduino Project hub
*
*/

/*
//defines the pins connected to each coil.
//Also sets the rotation of the motor (clockwise)
#define A 2
#define B 3
#define C 4
#define D 5
 
#define NUMBER_OF_STEPS_PER_REV 512


//Functions
//Sets each pin as an output.
void setup()
{
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
}//End of void sertup() function

void write(int a,int b,int c,int d)
{
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}//End of void write(int a,int b,int c,int d)function.

//This step does all the work.
//This engergizes each pin in return for a movement of the motor
void onestep()
{
  //Energizes the pin
  write(1,0,0,0);
  //determines the speed of the motor.
  delay(5);
  write(1,1,0,0);
  delay(5);
  write(0,1,0,0);
  delay(5);
  write(0,1,1,0);
  delay(5);
  write(0,0,1,0);
  delay(5);
  write(0,0,1,1);
  delay(5);
  write(0,0,0,1);
  delay(5);
  write(1,0,0,1);
  delay(5);
}//End of void onestep() function

//This will turn the motor one full turn .
void loop()
{
  int i;
  i=0;
  while(i<NUMBER_OF_STEPS_PER_REV)
  {
  onestep();
  i++;
  }//End of while loop
}//End of main void loop()
*/

/*
*Ardunio demo code for stepper motor speeds
*this on I would change my speed 
*15rpm is at 100%
*11.25 is at 75%
*7.5 is at 50%
*3.75 is at 25%
*/

// Include the Arduino Stepper.h library:
#include <Stepper.h>
// Define number of steps per rotation:
const int stepsPerRevolution = 2048;
// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver
// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
void setup() {
  // Set the speed to 15 rpm:
  myStepper.setSpeed(15);
 
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);

   // Set the speed to 11.25 rpm:
  myStepper.setSpeed(11.25);
 
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);

   // Set the speed to 7.5 rpm:
  myStepper.setSpeed(7.5);
 
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);

   // Set the speed to 3.75 rpm:
  myStepper.setSpeed(3.75);
 
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);
}
void loop() {
  // Step one revolution in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  // Step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
