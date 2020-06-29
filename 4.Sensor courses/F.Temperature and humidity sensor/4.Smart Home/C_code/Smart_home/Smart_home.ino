/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Smart_home 
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Smart_home 
* @details
* @par History  no
*
*/
#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "dht11.h"

#define DHT11PIN 2
dht11 DHT11;

#define OLED_RESET 11
Adafruit_SSD1306 display(OLED_RESET);

#define LOGO16_GLCD_HEIGHT 32
#define LOGO16_GLCD_WIDTH 128

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int buzzerpin = 13;
int motorpin = 6;
int warn = 0;
float sinVal;
int toneVal;

void setup() 
{
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  display.display(); // show splashscreen
  delay(2000);
  pinMode(DHT11PIN,OUTPUT);
  pinMode(buzzerpin, OUTPUT);         
  pinMode(motorpin, OUTPUT);
  Serial.begin(9600);
}

void buzWarning()
{
	warn = 1;
	 for(int x=0; x<180; x++)
	{
		sinVal = (sin(x*(3.1412/180))); 
		toneVal = 2000+(int(sinVal*1000));
		tone(buzzerpin, x);           
		delay(2);                     
	 }
}

void stopWarning()
{
    warn = 0;
    noTone(buzzerpin);
}

void loop() {
  int chk = DHT11.read(DHT11PIN);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.print("Tep:");
  display.print((float)DHT11.temperature, 2);
  display.println("C");
  display.setCursor(0, 18);
  display.print("Hum:");
  display.print((float)DHT11.humidity, 2);
  display.print("%");
  display.display();

  Serial.print("Tep: ");
  Serial.print((float)DHT11.temperature, 2);
  Serial.println("C");
  Serial.print("Hum: ");
  Serial.print((float)DHT11.humidity, 2);
  Serial.println("%");
  Serial.println();
  
  if((float)DHT11.temperature >= 31 && warn == 0)
  {
    buzWarning();
    analogWrite(motorpin, 30);
  }
  else if((float)DHT11.temperature < 31 && warn == 1)
  {
  	stopWarning();  
    analogWrite(motorpin, 0);
  }
  delay(1000);
}
