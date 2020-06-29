/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         OLED_Ultrasonic
* @author       Jessica
* @version      V1.0
* @date         2019.07.01
* @brief        OLED
* @details
* @par History  no
*
*/
#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include <Servo.h>  

#define OLED_RESET 11
Adafruit_SSD1306 display(OLED_RESET);

#define LOGO16_GLCD_HEIGHT 32
#define LOGO16_GLCD_WIDTH 128

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

Servo myservo;      
int ServoPin = 5;    

int Echo = 8;  
int Trig = 7; 

int Distance = 0;
void Distance_test();
void Display_Data(int data);

static const unsigned char PROGMEM str[] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x07,0xC0,0x00,0x00,0x00,0xF8,0x00,0x00,0x0F,0xE0,0x00,0x00,0x01,0xFC,0x00,
	0x00,0x1C,0x70,0x00,0x00,0x03,0x8E,0x00,0x00,0x38,0x38,0x00,0x00,0x07,0x07,0x00,
	0x00,0x70,0x1C,0x00,0x00,0x0E,0x03,0x80,0x00,0xE0,0x0E,0x00,0x00,0x1C,0x01,0xC0,
	0x00,0xC0,0x06,0x00,0x00,0x18,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0x00,
	0x00,0x00,0x00,0xE0,0x01,0xC0,0x00,0x00,0x00,0x00,0x00,0x70,0x03,0x80,0x00,0x00,
	0x00,0x00,0x00,0x38,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x0E,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF8,0x00,0x00,0x00,
	0x00,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};//笑脸

/**
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
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);   
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display(); // show splashscreen
  delay(2000);
  // display.clearDisplay(); // clears the screen and buffer
  delay(1000);

  myservo.attach(ServoPin);

  int ServoPos = 90;
  myservo.write(ServoPos);
}

/**
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
    Distance_test();
    Display_Data(Distance);
	if(Distance < 20)
	{
		display.clearDisplay();
		display.drawBitmap(64, 0, str, 64, 32, 1);
		display.display();

		delay(500);

		servo_control();
	}
	else
	{
	    myservo.write(0);
	}
    Serial.print("Distance:");      
    Serial.print(Distance);         
    Serial.println("cm");        
}

void servo_control()
{

  int pos = 0;
  for (pos = 0; pos < 180; pos++)
  {
    myservo.write(pos);
    delay(20);
  }

  for (pos = 180; pos > 0; pos--)
  {
    myservo.write(pos);
    delay(20);
  }
}

/*
* Function       Display_Data
* @author        Jessica
* @date          2019.07.01
* @brief         Display data
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void Display_Data(int data)
{
//  Distance_test();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("data:");
  display.println(data);
  display.display();
}
/*
* Function       Distance_test
* @author        Jessica
* @date          2019.07.01
* @brief         Distance test
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void Distance_test()   
{
  digitalWrite(Trig, LOW);   //Give the trigger pin a low level of 2μs
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  //Give the trigger pin a high level of at least 10 μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    //Continue to give trigger pin low level
  float Fdistance = pulseIn(Echo, HIGH);  //Read high time (unit: microsecond)
  Fdistance= Fdistance/58;       //Y meters = (X seconds * 344) / 2
  // X seconds=（ 2*Y meters）/344 ==》X seconds=0.0058*Y meters ==》cm = microseconds/58
  Distance = Fdistance;
} 
