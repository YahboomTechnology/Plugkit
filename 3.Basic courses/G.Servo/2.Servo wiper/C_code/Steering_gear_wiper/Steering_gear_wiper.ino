/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Steering_gear_wiper
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        servo_wiper
* @details
* @par History  
*
*/
#include <Servo.h>  //Arduino IDE comes with servo library files

Servo myservo;      //Define myservo

//Define servo pin
int ServoPin = 5;

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
  int ServoPos = 90;
  myservo.write(ServoPos);
}

/*
* Function       servo_control
* @author        Jessica
* @date          2019.8.21
* @brief         servo control
* @param[in]     void
* @retval        void
* @par History   no
*/
void servo_control()
{
  //Define servo ratation position
  int pos = 0;
  for (pos = 0; pos < 180; pos++)
  {
    myservo.write(pos);
    delay(20);
  }

  for (pos = 180; pos > 0; pos--)
  {
    myservo.write(pos);
    delay(20);
  }
}

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         main
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void loop()
{
  delay(500);
  servo_control();
}
