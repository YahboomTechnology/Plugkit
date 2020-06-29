/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Key_switch_Angle
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        按键切换舵机角度
* @details
* @par History  见如下说明
*
*/
#include <Servo.h>  //Arduino IDE comes with servo library files

Servo myservo;      //Defining a servo object myservo

int ServoPin = 5;
int button = 4;
int val;
int i = 0;

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
    
    Serial.begin(9600);
    pinMode(button,INPUT_PULLUP);
} 

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         main function
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop() 
{ 
    val=digitalRead(button);//Read digital level 2 and assign it to val
    if(val==LOW)//Detect whether the button is pressed, the small light is on when the button is pressed
    {
       i+=1;
       delay(1000);
     }
    if(i == 1)
    {
       myservo.write(0);
     }
    if(i == 2)
    {
       myservo.write(90);
     }
    if(i == 3)
    {
       myservo.write(180);
       i = 0;
     }

}
