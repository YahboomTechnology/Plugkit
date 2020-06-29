/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         oscillating_fan
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        oscillating_fan
* @details
* @par History  
*
*/
#include <Servo.h>  //Arduino IDE comes with servo library files

Servo myservo;      //Defining a servo object myservo

int motorpin = 6;
int ServoPin = 5;//Define the servo pin
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
    pinMode(motorpin, OUTPUT);
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
    analogWrite(motorpin, 35);
    val=digitalRead(button);//Read digital level 2 and assign it to val
    if(val==LOW)//Detect whether the button is pressed, the small light is on when the button is pressed
    {
       i+=1;
       delay(1000);
     }
    if(i == 1)
    {
        int pos = 0;
        for (pos = 0; pos < 180; pos++)
        {
          //Servo 0 rotates to 180, each time delay 20ms
          myservo.write(pos);
          delay(20);
        }
      
        for (pos = 180; pos > 0; pos--)
        {
          //Servo 180 rotates to 0, each time delay 20ms
          myservo.write(pos);
          delay(20);
        }
     }
    if(i == 2)
    {
       myservo.write(0);
     }
    if(i == 3)
    {
       myservo.write(90);
     }
    if(i == 4)
    {
       myservo.write(180);
       i = 0;
     }

}
