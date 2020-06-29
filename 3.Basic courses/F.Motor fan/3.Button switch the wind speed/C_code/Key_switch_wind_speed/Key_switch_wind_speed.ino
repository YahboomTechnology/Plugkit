/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Key_switch_wind_speed
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Key switch wind speed
* @details
* @par History  
*
*/
int motorpin = 6;//Define the number 6 interface as the fan interface
int button = 4;//Define the number 4 interface as the button interface
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
    Serial.begin(9600);//Set the baud rate to 9600
    pinMode(motorpin,OUTPUT);//Set digital IO pin mode, OUTPUT is output
    pinMode(button,INPUT_PULLUP);//Define the key interface as the input interface
} 

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         main
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
       analogWrite(motorpin, 30);
     }
    if(i == 2)
    {
       analogWrite(motorpin, 60);
     }
    if(i == 3)
    {
       analogWrite(motorpin, 90);
     }
    if(i == 4)
    {
       analogWrite(motorpin, 0);
       i = 0;
     }

}
