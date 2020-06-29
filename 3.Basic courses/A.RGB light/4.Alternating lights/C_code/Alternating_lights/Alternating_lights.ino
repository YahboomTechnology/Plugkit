/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         ColorLED.c
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Alternating_lights
* @details
* @par History  
*
*/

#define ON 1     //Enable LED
#define OFF 0    //Disable LED

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
* @par History   no
*/
void setup()
 {
  //Initialize the IO port of RGB as output mode
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
 }
 
/*
* Function       color_led
* @author        Jessica
* @date          2019.8.21  
* @brief         7 different colors formed by different combinations of R, G, B three colors
* @param[in1]    Red switch
* @param[in2]    Greens witch
* @param[in3]    Blue switch
* @retval        void
* @par History   no
*/
//7 different colors formed by different combinations of R, G, B three colors
void color_led(int v_iRed, int v_iGreen, int v_iBlue)
{
   //red LED
  if (v_iRed == ON)
  {
      digitalWrite(LED_R, HIGH);//Red light is on
  }
  else
  {
      digitalWrite(LED_R, LOW);//Red light is off
  }
  //green LED
  if (v_iGreen == ON)
  {
      digitalWrite(LED_G, HIGH);//Green light is on
  }
  else
  {
      digitalWrite(LED_G, LOW);//Green light is off
  }
  //blue LED
  if (v_iBlue == ON)
  {
      digitalWrite(LED_B, HIGH);//Blue light is on
  }
  else
  {
      digitalWrite(LED_B, LOW);//Blue light is off
  }
}

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21   
* @brief         The lanterns are displayed alternately in turn
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()
{  
   delay(2000);
   while(1)
  {                            // LED_R    LED_G    LED_B
    
    color_led(ON, OFF, OFF);   //   1        0        0  red
    delay(2000);
    color_led(OFF, ON, OFF);   //   0        1        0  green
    delay(2000);
    color_led(OFF, OFF, ON);   //   0        0        1  blue
    delay(2000);
    color_led(ON, ON, OFF);    //   1        1        0  yellow
    delay(2000);
    color_led(ON, OFF, ON);    //   1        0        1  magenta
    delay(2000);
    color_led(OFF, ON, ON);    //   0        1        1  cyan
    delay(2000);
    color_led(ON, ON, ON);     //   1        1        1  white
    delay(2000);
  }
}

