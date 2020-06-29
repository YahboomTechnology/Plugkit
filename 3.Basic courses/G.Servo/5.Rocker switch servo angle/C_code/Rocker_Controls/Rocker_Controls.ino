/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Rocker Controls
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Rocker Control control
* @details
* @par History  
*
*/
#include <Servo.h>
Servo myservo1;//Defining servo object myservo1
//Servo myservo2;//Defining servo object myservo2
int seroverdown = 5; //Define the servo signal cable interface
//int seroverup = 3; //Define the servo signal cable interface
int VRX = A0; //X axis of rocker connected to analog A0 input
int VRY = A1; //Y axis of rocker connected to analog A1 input
int x = 0, y = 0; //Define the variables x and y, and read the values from the joystick interface (0-1023, but generally not available, about 90-900 or so)

/*
* Function       setup
* @author        Jessica
* @date          2019.8.21
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup()
{
  Serial.begin(9600);
  pinMode(VRX, INPUT); 
  pinMode(VRY, INPUT);
  myservo1.attach(seroverdown);
//  myservo2.attach(seroverup);
}

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         main function
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void loop()
{
  x = analogRead(VRX);
  y = analogRead(VRY);
  x = map(x,0,1023,0,179);
  y = map(y,0,1023,0,179);
  Serial.print("x: "); 
  Serial.println(x);   
  Serial.print("y: ");
  Serial.println(y);
    
//  myservo2.write(x);
  myservo1.write(y);
  delay(15);
}
