/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Potentiometer Controls Angle
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Potentiometer Controls servo
* @details
* @par History  
*
*/
#include <Servo.h>  

Servo myservo;      //Define servo object myservo

int ServoPin = 5;//Define servo pin
int potpin = A1;
int angle = 0;

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
  myservo.attach(ServoPin);
//  int ServoPos = 0;
//  myservo.write(ServoPos);
  Serial.begin(9600);
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
  angle = analogRead(potpin);//Read the analog voltage value of Potentiometer and assign it to angle
  angle = map(angle, 0, 1023, 0, 180);//Map read analog values to 0-180
  Serial.print("angle = ");
  Serial.println(angle);//Serial port print angle variable
  myservo.write(angle);//Write rotation angle
  delay(10);
}
