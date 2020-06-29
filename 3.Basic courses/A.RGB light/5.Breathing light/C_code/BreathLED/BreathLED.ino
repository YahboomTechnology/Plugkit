/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         BreathLED
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Breathing LED
* @details
* @par History  
*
*/

int LED_R = 10;  //LED_R connect digital I/O port 10 of Arduino
int LED_G = 11;  //LED_G connect digital I/O port 11 of Arduino
int LED_B = 9;   //LED_B connect digital I/O port 9 of Arduino


/*
* Function       setup
* @author        Jessica
* @date          2019.8.21
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   NO
*/
void setup() 
{
  pinMode(LED_R, OUTPUT);
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
  for(int i = 0; i <= 255; i++) //i increases from 0 to 255
  {
    analogWrite(LED_R, i);//Write analog value i to RGB interface
    delay(10);
  }
  for(int i = 255; i >= 0; i--)//i decreases from 255 to 0
  {
    analogWrite(LED_R, i);//Write analog value i to RGB interface
    delay(10);
  }
}
