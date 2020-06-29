/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         OLED_showvocie
* @author       Jessica
* @version      V1.0
* @date         2019.07.01
* @brief        OLED display analog value of sound sensor
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

int voicepin = A1;
int val = 0;
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
  pinMode(voicepin, INPUT);
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
* @brief         main
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()   
{
   showvoice();
   delay(1000);
}

/*
* Function       showvoice
* @author        Jessica
* @date          2019.07.01
* @brief         Display analog value of sound sensor
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void showvoice()
{
  val = analogRead(voicepin);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("voice:");
  display.println(val);
  display.display();
}
