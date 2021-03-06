/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         count_down
* @author       Jessica
* @version      V1.0
* @date         2019.07.01
* @brief        Oled Count down
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

/*Notes in a score*/
//Define the notes in B
#define NTBL1 248
#define NTBL2 278
#define NTBL3 294
#define NTBL4 330
#define NTBL5 371
#define NTBL6 416
#define NTBL7 467

#define NTB1 495
#define NTB2 556
#define NTB3 624
#define NTB4 661
#define NTB5 742
#define NTB6 833
#define NTB7 935

#define NTBH1 990
#define NTBH2 1112
#define NTBH3 1178
#define NTBH4 1322
#define NTBH5 1484
#define NTBH6 1665
#define NTBH7 1869


//low pitch
#define NTCL1 131
#define NTCL2 147
#define NTCL3 165
#define NTCL4 175
#define NTCL5 196
#define NTCL6 221
#define NTCL7 248

//middle pitch
#define NTC1 262
#define NTC2 294
#define NTC3 330
#define NTC4 350
#define NTC5 393
#define NTC6 441
#define NTC7 495

//high pitch
#define NTCH1 525
#define NTCH2 589
#define NTCH3 661
#define NTCH4 700
#define NTCH5 786
#define NTCH6 882
#define NTCH7 990

//Define the note in D
#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 1112

//Define the note in E
#define NTE1 330
#define NTE2 350
#define NTE3 393
#define NTE4 441
#define NTE5 495
#define NTE6 556
#define NTE7 624

#define NTEL1 165
#define NTEL2 175
#define NTEL3 196
#define NTEL4 221
#define NTEL5 248
#define NTEL6 278
#define NTEL7 312

#define NTEH1 661
#define NTEH2 700
#define NTEH3 786
#define NTEH4 882
#define NTEH5 990
#define NTEH6 1112
#define NTEH7 1248


#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//Tongnian C
int tune[]=                 //List the frequencies according to the spectrum
{
NTC3, NTC5, NTC5, NTC3, NTC6, NTC6, NTC7, NTC6, NTC6, NTC6, NTC5, NTCH1, NTCH1, NTCH1, NTCH1, NTC6,
 NTCH1, NTC6, NTC5, 

NTC3, NTC5, NTC5, NTC5, NTC3, NTC6, NTC6, NTC7, NTC6, NTC6, NTC6, NTC5, NTCH1, NTCH1, NTCH1,
 NTCH1, NTC6, NTC6, NTCH1, NTCH2, 

NTCH5, NTCH5, NTCH5, NTCH5,NTCH5, NTCH3, NTCH2, NTCH1, NTCH1, NTC6, NTCH1, NTC6, NTCH1, NTCH2,
  NTCH2, NTCH2, NTCH2,NTCH2, NTCH1, NTCH3, NTCH2, NTCH2, 

NTCH3, NTCH3, NTCH3, NTCH3, NTCH2, NTCH2, NTCH1, NTCH1, NTCH1, NTCH2, NTCH1, NTC6, NTC5, NTC5, 
 NTC5, NTC5, NTC6, NTC5,NTCH2, NTCH3, NTCH1
 
};

float durt[]=                   //List the beats according to the notation
{
0.5, 0.5, 1.5, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 
 0.5, 0.5, 2,
 
0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 
 0.5, 0.5, 0.5, 0.5, 2,

0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 0.5, 0.5, 0.5, 1, 0.25,
 0.5, 0.5, 0.5, 0.5, 1, 0.25, 2, 

0.5, 1, 0.5, 0.5, 0.5, 1, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 
 0.5, 0.5, 0.5, 0.5, 0.5, 2
};

static const unsigned char PROGMEM smile[] =
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF8,0x00,0x00,0x00,
0x00,0x00,0x00,0xE0,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x07,0x00,0x00,0x00,
0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,
0x00,0x00,0x0C,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x30,0x00,0x00,
0x00,0x00,0x10,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x08,0x00,0x00,
0x00,0x00,0x20,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x04,0x00,0x00,
0x00,0x00,0x40,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x02,0x00,0x00,
0x00,0x00,0x81,0x00,0x04,0x04,0x00,0x00,0x00,0x00,0x20,0x20,0x01,0x01,0x00,0x00,
0x00,0x00,0x81,0x00,0x04,0x04,0x00,0x00,0x00,0x00,0x20,0x20,0x01,0x01,0x00,0x00,
0x00,0x01,0x02,0x80,0x0A,0x02,0x00,0x00,0x00,0x00,0x40,0x50,0x02,0x80,0x80,0x00,
0x00,0x01,0x06,0xC0,0x1B,0x02,0x00,0x00,0x00,0x00,0x40,0xD8,0x06,0xC0,0x80,0x00,
0x00,0x01,0x18,0x30,0x60,0xC2,0x00,0x00,0x00,0x00,0x43,0x06,0x18,0x30,0x80,0x00,
0x00,0x02,0x06,0xC0,0x1B,0x01,0x00,0x00,0x00,0x00,0x80,0xD8,0x06,0xC0,0x40,0x00,
0x00,0x02,0x02,0x80,0x0A,0x01,0x00,0x00,0x00,0x00,0x80,0x50,0x02,0x80,0x40,0x00,
0x00,0x02,0x01,0x00,0x04,0x01,0x00,0x00,0x00,0x00,0x80,0x20,0x01,0x00,0x40,0x00,
0x00,0x02,0x01,0x00,0x04,0x01,0x00,0x00,0x00,0x00,0x80,0x20,0x01,0x00,0x40,0x00,
0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x40,0x00,
0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x40,0x00,
0x00,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x00,
0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x80,0x00,
0x00,0x01,0x0C,0x00,0x01,0x02,0x00,0x00,0x00,0x00,0x41,0x80,0x00,0x20,0x80,0x00,
0x00,0x00,0x83,0x00,0x06,0x04,0x00,0x00,0x00,0x00,0x20,0x60,0x00,0xC1,0x00,0x00,
0x00,0x00,0x80,0xC0,0x18,0x04,0x00,0x00,0x00,0x00,0x20,0x18,0x03,0x01,0x00,0x00,
0x00,0x00,0x40,0x38,0xE0,0x08,0x00,0x00,0x00,0x00,0x10,0x07,0x1C,0x02,0x00,0x00,
0x00,0x00,0x20,0x07,0x00,0x10,0x00,0x00,0x00,0x00,0x08,0x00,0xE0,0x04,0x00,0x00,
0x00,0x00,0x10,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x08,0x00,0x00,
0x00,0x00,0x0C,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x30,0x00,0x00,
0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,
0x00,0x00,0x00,0xE0,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x07,0x00,0x00,0x00,
0x00,0x00,0x00,0x1F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF8,0x00,0x00,0x00};/*"C:\Users\Administrator\Desktop\face.bmp",0*/

int buzzer = 13;  //Set the digital IO pin that controls the buzzer
int LED_R = 10;  //LED R is connected to the Arduino digital I/O port 10
int LED_G = 11;  //LED G is connected to the Arduino digital I/O port 11
int LED_B = 9;   //LED B is connected to the Arduino digital I/O port 9
int val;

/*
* Function       PlayTest
* @author        Jessica
* @date          2019.8.21
* @brief         Play music
* @param[in]     void
* @retval        void
* @par History   no
*/
void PlayTest()
{
 int val=0;
 int length = sizeof(tune)/sizeof(tune[0]);   //calculated length
 val = length;
 for(int x=0; x < length; x++)
  {
    tone(buzzer,tune[x]);
    delay(500*durt[x]);   //This is used to adjust the delay according to the beat, the 500 index can be adjusted by itself, in this music, I find 500 is more appropriate.
    noTone(buzzer);
  }
  Serial.println(val);
}

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
  val = 61;
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(buzzer,OUTPUT);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display(); // show splashscreen
  delay(2000);
  // display.clearDisplay(); // clears the screen and buffer
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
void loop()   //Initialization has completed the display
{
  digitalWrite(LED_R,  LOW); 
  digitalWrite(LED_G,  LOW); 
  digitalWrite(LED_B,  LOW); 
   welcome();
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
  delay(1000);
  val -= 1;
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(50, 8);
  display.clearDisplay();
  display.println(val);
  if(val == 0)
  {
    delay(500);  
    display.clearDisplay();
    display.drawBitmap(0, 0, smile, 128, 32, 1); //Draws the character corresponding to the dot matrix data
    display.display();//display
    delay(500);  
    digitalWrite(LED_R,  HIGH); //light up red light
    PlayTest();
  }
  display.display();
//  delay(2000);
//  display.clearDisplay();
}
