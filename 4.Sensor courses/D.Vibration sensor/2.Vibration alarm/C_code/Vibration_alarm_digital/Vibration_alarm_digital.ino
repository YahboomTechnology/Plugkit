/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Vibration_alarm
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Vibration_alarm
* @details
* @par History  no
*
*/
#include "pitches.h"

int melody[] = {

NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4

};

int noteDurations[] = {

4, 8, 8, 4,4,4,4,4

};

int LED_R = 10;  
int LED_G = 11;  
int LED_B = 9;   
int SensorINPUT = 3 ;      
int buzzerpin = 13;
unsigned char state = 0;

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
  pinMode(LED_G, OUTPUT);         
  pinMode(buzzerpin, OUTPUT);         
  pinMode(SensorINPUT, INPUT);        
  
}

/*
* Function       buzzer warning
* @author        Jessica
* @date          2019.8.21
* @brief         buzzer warning
* @param[in]     void
* @retval        void
* @par History   no
*/
void buzWarning()
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
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         main
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void loop()
{
  if(digitalRead(SensorINPUT))
  {              
    noTone(buzzerpin);
    digitalWrite(LED_G,LOW);   
  }  
  else 
  {
    buzWarning();
    digitalWrite(LED_G,HIGH);  //light up
    delay(2000);
  }
} 
