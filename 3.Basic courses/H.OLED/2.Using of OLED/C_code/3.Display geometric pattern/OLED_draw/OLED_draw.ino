/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         OLED_drawcircle
* @author       Jessica
* @version      V1.0
* @date         2019.07.01
* @brief        Display geometric pattern
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
  display.display(); 
  delay(2000);
  display.clearDisplay();//Clear
  
  testdrawcircle();//Calling a circular function
  delay(2000);
  display.clearDisplay();//Clear

  testfillrect();//Calling a rectangle function
  delay(2000);
  display.clearDisplay();//Clear

  testdrawtriangle();//Call triangle function
  delay(2000);
  display.clearDisplay();//Clear

  testfilltriangle();
  delay(2000);
  display.clearDisplay();//Clear

  testdrawroundrect();
  delay(2000);
  display.clearDisplay();//Clear

  testfillroundrect();
  delay(2000);
  display.clearDisplay();//Clear

  testdrawrect();
  delay(2000);
  display.clearDisplay();//Clear
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
void loop()      //Initialization has been completed and the main loop has no action
{
        
}

void testdrawcircle(void) //Circle function
{
  for (int16_t i=0; i<display.height(); i+=2) 
  {
    display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
    display.display();
  }
}

void testfillrect(void)//Fill rectangle function
{
  uint8_t color = 1;
  for (int16_t i=0; i<display.height()/2; i+=3) 
  {
    // alternate colors
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
    display.display();
    color++;
  }
}

void testdrawtriangle(void) //triangle function
{
  for (int16_t i=0; i<min(display.width(),display.height())/2; i+=5) 
  {
    display.drawTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    display.display();
  }
}

void testfilltriangle(void)//Fill triangle function
{
  uint8_t color = WHITE;
  for (int16_t i=min(display.width(),display.height())/2; i>0; i-=5)
  {
    display.fillTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
}

void testdrawroundrect(void) //Round rectangle function
{
  for (int16_t i=0; i<display.height()/2-2; i+=2)
  {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, WHITE);
    display.display();
  }
}

void testfillroundrect(void) //Fill Round rectangle function
{
  uint8_t color = WHITE;
  for (int16_t i=0; i<display.height()/2-2; i+=2) 
  {
    display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
}
   
void testdrawrect(void) //Rectangle function
{
  for (int16_t i=0; i<display.height()/2; i+=2)
  {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
    display.display();
  }
}



