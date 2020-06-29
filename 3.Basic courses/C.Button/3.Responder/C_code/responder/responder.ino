/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         responder
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        responder
* @details
* @par History  
*
*/
#include "pitches.h"

int melody[] = {

NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4

};

int noteDurations[] = {

4, 8, 8, 4,4,4,4,4

};

int buzzerpin=13;//Set buzzer digital pin 13 
int LED_R = 10;  //LED_R connect I/O 10 of Arduino
int LED_G = 11;  //LED_G connect I/O 11 of Arduino
int LED_B = 9;   //LED_B connect I/O 9 of Arduino
int Button_R = 2;//Define Red button IO
int Button_G = 3;//Define Green Button IO
int Button_B = 4;//Define Blue button IO
int val1,val2,val3;

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
  pinMode(LED_R, OUTPUT);//set red light pin to output mode
  pinMode(LED_G, OUTPUT);//set green light pin to output mode
  pinMode(LED_B, OUTPUT);//set blue light pin to output mode
  pinMode(Button_R, INPUT);//set red button pin to input mode
  digitalWrite(Button_R ,HIGH);//set red digital pin to high level
  pinMode(Button_G, INPUT);//set green button pin to input mode
  digitalWrite(Button_G ,HIGH);//set green digital pin to high level 
  pinMode(Button_B, INPUT);//set blue button pin to input mode
  digitalWrite(Button_B ,HIGH);//set blue digital pin to high level 
}

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
  for (int thisNote = 0; thisNote < 8; thisNote++)
  
  {
 //to calculate the note duration, take one second
 //divided by the note type.
 // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  int noteDuration = 1000/noteDurations[thisNote];
  tone(buzzerpin, melody[thisNote],noteDuration);
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);
  noTone(buzzerpin);
  
  }
}

/*
* Function       setup
* @author        Jessica
* @date          2019.8.21
* @brief         main function
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop() 
{
  val1 = digitalRead(Button_R);//Read digital level 2 and assign it to val
  if(val1 == LOW)//Detect whether the button is pressed, the small light is on when the button is pressed
  {
    digitalWrite(LED_R,   HIGH);//Light up red light
    PlayTest();
    while(1);//After the red light turns on, it stays in the infinite loop to keep the red light
  }
  else
  {
    digitalWrite(LED_R,   LOW);//otherwise red light is closed
  }
  val2 = digitalRead(Button_G);//Read digital level 3 and assign it to val
  if(val2 == LOW)//Detect whether the button is pressed, the small light is on when the button is pressed
  {
    digitalWrite(LED_G,  HIGH);//Light up green light
    PlayTest();
    while(1);//After the green light turns on, it stays in the infinite loop to keep the green light
  }
  else
  {
    digitalWrite(LED_G,  LOW);//otherwise green light is closed
  }
  val3 = digitalRead(Button_B);//Read digital level 4 and assign it to val
  if(val3 == LOW)//Detect whether the button is pressed, the small light is on when the button is pressed
  {
    digitalWrite(LED_B, HIGH);//Light up blue light
    PlayTest();
    while(1);//After the bluelight turns on, it stays in the infinite loop to keep the blue light
  }
  else
  {
    digitalWrite(LED_B, LOW);//otherwise blue light is closed
  }
}
