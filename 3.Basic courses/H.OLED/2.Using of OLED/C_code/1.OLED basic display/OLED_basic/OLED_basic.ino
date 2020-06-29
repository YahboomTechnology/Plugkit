/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         OLED
* @author       Jessica
* @version      V1.0
* @date         2019.07.01
* @brief        OLED basic display
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


/*
* Function       setup
* @author        Jessica
* @date          2019.07.01
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup()
{
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display(); // show splashscreen
  delay(2000);
  // display.clearDisplay(); // clears the screen and buffer
  welcome();
  delay(1000);
}

/*
* Function       loop
* @author        Jessica
* @date          2017.07.25
* @brief         main function
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()   //Initialization has been completed
{
   
}

/*
* Function       welcome
* @author        Jessica
* @date          2019.07.01
* @brief         welcome
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void welcome()
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("Welcome!");
  display.println("Hola,Maker");
  display.display();
//  delay(2000);
//  display.clearDisplay();
}



