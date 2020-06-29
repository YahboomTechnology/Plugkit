#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
 
#define OLED_RESET 11
Adafruit_SSD1306 display(OLED_RESET);
 
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
 
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
 
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
 
void setup()  
{                
  Serial.begin(115200);
  delay(500);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64) 
  display.display(); // show splashscreen  
  delay(2000);
  display.clearDisplay(); // clears the screen and buffer  
}
 
void loop() 
{
  String inString = "";
  while (Serial.available()>0)
  {
    char inChar = Serial.read();      
    inString += (char)inChar;
    delay(10);
  }  
  if(inString!="")
  {
    display.setTextSize(1);		//Set the font size
    display.setTextColor(WHITE);	//Set the font color to white
    display.setCursor(36,16);	//Sets the starting position of the font
    display.println(inString);	//Display input data
    display.display();	//display information
    delay (1000);  
    display.clearDisplay();
  }
}
