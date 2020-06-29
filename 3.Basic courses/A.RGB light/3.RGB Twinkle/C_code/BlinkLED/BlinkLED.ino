/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         BlinkLED
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        et a blinking LED
* @details
* @par History  
*
*/
int LED_R = 10;  //LED_R connect digital I/O port 10 of Arduino
int LED_G = 11;  //LED_G connect digital I/O port 11 of Arduino
int LED_B = 9;   //LED_B connect digital I/O port 9 of Arduino

/**
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
  //Initialize the IO port of RGB as output mode
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

/**
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
  while(1)
  {
    digitalWrite(LED_R,  HIGH); //red light is on
    digitalWrite(LED_G,  LOW);  //green light is off
    digitalWrite(LED_B,  LOW);  //blue light is off
    delay(500);//delay 0.5s
    digitalWrite(LED_R,  LOW);  //red light is off
    delay(500);//delay 0.5s
  }
}
