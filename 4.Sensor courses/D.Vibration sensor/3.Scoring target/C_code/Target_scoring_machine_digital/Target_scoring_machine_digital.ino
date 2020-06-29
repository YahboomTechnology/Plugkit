/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Target scoring machine
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Scoring target
* @details
* @par History  
*
*/

#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

#define OLED_RESET 11
Adafruit_SSD1306 display(OLED_RESET);

#define LOGO16_GLCD_HEIGHT 32
#define LOGO16_GLCD_WIDTH 128

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int LED_R = 10;  
int LED_G = 11; 
int LED_B = 9;   
int SensorINPUT = A1;      
int buzzerpin = 13;
int number = 0;

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
  pinMode(buzzerpin,OUTPUT);
  pinMode(SensorINPUT, INPUT);        
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

// by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
// init done
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(1, 8);
  display.clearDisplay();
  display.print("Ready,go!");
  display.display(); // show splashscreen

  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);  
  digitalWrite(LED_B, LOW);  
  Serial.begin(9600);     
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
  if(digitalRead(SensorINPUT))
  {                         
	  digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);  
    digitalWrite(LED_B, LOW);   
  }  
  else 
  { 
	  number = number + 1;
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(1, 8);
    display.clearDisplay();
    display.print("Hits:");
    display.println(number);
    display.display();
    light();
  }
} 

/*
* Function       light
* @author        Jessica
* @date          2019.8.21
* @brief         red light flashing
* @param[in]     void
* @retval        void
* @par History   no
*/
void light()
{
  for(int i=0;i<4;i++)
  {
    digitalWrite(LED_R, HIGH);
    delay(100);
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);  
    digitalWrite(LED_B, LOW);    
  	delay(100);
  }
}
