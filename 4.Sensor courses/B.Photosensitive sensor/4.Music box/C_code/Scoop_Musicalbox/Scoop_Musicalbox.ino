/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Scoop Musicalbox
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Musicalbox
* @details
* @par History  
*
*/
#include <Servo.h>  //Arduino IDE comes with servo library files
#include "SCoop.h"  //We need to add library
defineTask(Task1);
#define Light A2       

#define NOTE_A0 -1
#define NOTE_A1 441
#define NOTE_A2 495
#define NOTE_A3 556
#define NOTE_A4 589
#define NOTE_A5 661
#define NOTE_A6 742
#define NOTE_A7 833

#define NOTE_AL1 221
#define NOTE_AL2 248
#define NOTE_AL3 278
#define NOTE_AL4 294
#define NOTE_AL5 330
#define NOTE_AL6 371
#define NOTE_AL7 416

#define NOTE_AH1 882
#define NOTE_AH2 990
#define NOTE_AH3 1112
#define NOTE_AH4 1178
#define NOTE_AH5 1322
#define NOTE_AH6 1484
#define NOTE_AH7 1665

#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625


int tune[] =
{
  //line1
  NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A2,NOTE_A2,NOTE_A3,NOTE_A5,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A3,NOTE_A2,NOTE_A1,NOTE_A1,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A3,NOTE_A5,NOTE_A5,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A2,
  //line2
  NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A2,NOTE_A2,NOTE_A2,
  NOTE_A3,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A6,NOTE_A5,NOTE_A1,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A3,NOTE_A5,NOTE_A5,NOTE_AL5,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A2,
  //line3
  NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A2,NOTE_A2,NOTE_A3,NOTE_A3,NOTE_A1,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A3,NOTE_A1,NOTE_A1,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A3,NOTE_A5,NOTE_A2,NOTE_A2,NOTE_A1,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A2,NOTE_A2,
  //line4
  NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A2,NOTE_A2,NOTE_A2,
  NOTE_A3,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A5,NOTE_A6,NOTE_A6,NOTE_A5,NOTE_A2,NOTE_A1,
  NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A2,NOTE_A3,NOTE_A5,NOTE_A5,NOTE_A3,NOTE_A3,
  NOTE_A6,NOTE_A5,NOTE_A5,NOTE_A3,NOTE_A3,NOTE_A2,NOTE_A2,NOTE_A0,NOTE_AL5,NOTE_A1,NOTE_A2,
  //line5
  NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A4,NOTE_A3,NOTE_A2,NOTE_AL7,NOTE_AL7,
  NOTE_A2,NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A0,NOTE_A1,NOTE_A3,NOTE_A5,
  NOTE_A6,NOTE_A6,NOTE_A6,NOTE_A6,NOTE_A6,NOTE_A5,NOTE_A2,NOTE_A3,NOTE_A4,
  NOTE_A4,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_A0,NOTE_A1,NOTE_A3,NOTE_A5,
  //line6
  NOTE_A6,NOTE_A6,NOTE_A6,NOTE_A7,NOTE_A6,NOTE_A5,NOTE_A4,NOTE_A4,
  NOTE_A3,NOTE_A5,NOTE_A6,NOTE_A1,NOTE_A2,NOTE_A3,
  NOTE_A4,NOTE_A0,NOTE_A3,NOTE_A4,NOTE_A3,NOTE_A2,NOTE_A1,NOTE_A7,
  NOTE_A2,NOTE_A1,NOTE_A1,NOTE_A1,NOTE_A0,
};
float duration[]=
{
  //line1
  0.5,0.5,0.5,0.25,0.25,0.5,0.5,1,
  0.5,0.5,0.5,0.5,0.5,0.25,0.25,1,
  0.5,0.5,0.5,0.5,0.5,0.5,1,
  0.5,0.5,0.5,0.25,0.25,1+1,
  //line2
  0.5,0.5,0.5,0.5,0.25,0.25,0.5,0.5,
  0.5,0.5,0.5,0.5,0.5,0.5,1,
  0.5,0.5,0.5,0.5,0.5,0.5,0.5+0.25,0.25,
  0.5,0.5,0.5,0.25,0.25,1+1,
  //line3
  0.5,0.5,0.5,0.5,0.5,0.25,0.25,0.25,0.5+0.25,
  0.5,0.5,0.5,0.5,0.5,0.5,1,
  0.5,0.5,0.5,0.5,0.5,0.25,0.25,0.25,0.5+0.25,
  0.5,0.25,0.25,0.25,0.5,0.25,1+1,
  //line4
  0.5,0.5,0.5,0.5,0.25,0.25,0.5,1,
  0.5,0.25,0.25,0.25,0.5,0.25,0.5,0.25,0.25,1,
  0.5,0.5,0.5,0.5,0.5,0.5,0.25,0.5,0.25,
  0.5,0.25,0.25,0.25,0.25,0.25,0.25,0.5,0.5,0.5,0.5,
  //line5
  0.5,0.25,0.5,0.5,0.5,0.5,0.25,0.25,0.5,
  0.5,0.25,0.25,1,0.5,0.5,0.5,0.5,
  0.5,0.25,0.5,0.5,0.5,0.5,0.5,0.5,
  0.25,0.5,0.25,1,0.5,0.5,0.5,0.5,
  //line6
  0.5,0.25,1,0.5,0.5,0.25,0.25,0.5,
  1,0.25,0.5,1,0.5,0.5,
  1,0.5,0.25,0.25,0.5,0.5,0.5,0.5,
  0.5,0.25,0.52,1+1,0.5,

};

int length;
int buzzer=13;

Servo myservo;      
int ServoPin = 3;  

int Intensity = 0;  

//Initial settings
void Task1::setup()
{
  myservo.attach(ServoPin);

  int ServoPos = 90;
  myservo.write(ServoPos);
}

void servo_control()
{
  int pos = 0;
  while(analogRead(Light) > 400);
  {
	myservo.write(0);
  }
  for (pos = 0; pos < 180; pos++)
  {
	myservo.write(pos);
	sleep(20);
  }

  for (pos = 180; pos > 0; pos--)
  {
	myservo.write(pos);
	sleep(20);
  }
}

void Task1::loop()
{
  sleep(500);
  servo_control();
}

void PlayTest()
{
 int val=0;
 int length = sizeof(tune)/sizeof(tune[0]);  
 val = length;
  for(int x=0; x < length; x++)
  {
    while(analogRead(Light) > 400)
    {
      noTone(buzzer);
    }
    tone(buzzer,tune[x]);
    sleep(600*duration[x]);   
    noTone(buzzer);
  }
}

defineTaskLoop(Task2)
{
   PlayTest();
   sleep(100);
}
void setup() {
   mySCoop.start();
   pinMode(buzzer, OUTPUT);
 }
void loop()
 {
   yield();
 }
