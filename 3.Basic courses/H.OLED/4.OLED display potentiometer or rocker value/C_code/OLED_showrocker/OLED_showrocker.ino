/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         OLED_showrocker
* @author       Jessica
* @version      V1.0
* @date         2019.07.01
* @brief        Oled Display the rocker value
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

int xpin = A1;
int ypin = A0;
int x = 0;
int y = 0;

/*
* Function       setup
* @author        Jessica
* @date          2019.07.01
* @brief         Initial Configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup()
{
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display(); // show splashscreen
  delay(2000);
  //display.clearDisplay(); // clears the screen and buffer
  //delay(1000);
}

/*
* Function       loop
* @author        Jessica
* @date          2017.07.25
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()   //Initialization has completed the display
{
   showrocker();
   delay(1000);
}

/*
* Function       showrocker
* @author        Jessica
* @date          2019.07.01
* @brief         display rocker value
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void showrocker()
{
  x = analogRead(xpin);
  y = analogRead(ypin);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("x:");
  display.println(x);
  display.display();
//  delay(2000);
//  display.clearDisplay();
}
