/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Buzzer
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Drive buzzer
* @details
* @par History  
*
*/

#define ding 1322
#define dong 1049

int buzzer=13;
int i = 0;

/*Ding Dong*/
int tune[]=   //List each frequency according to the notation
{
  ding, dong,
};
float durt[]= //List each durt according to the notation
{
  1, 2,
};

/*
* Function       PlayTest
* @author        Jessica
* @date          2019.8.21
* @brief         play music
* @param[in]     void
* @retval        void
* @par History   no
*/
void PlayTest()
{
 int length = sizeof(tune)/sizeof(tune[0]);  
 for(int x=0; x < length;x++)
  {
    tone(buzzer,tune[x]);
    delay(500*durt[x]);   
    noTone(buzzer);
  }
}

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
  pinMode(buzzer,OUTPUT);//Set digital IO port mode, buzzer pin is output mode
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
  PlayTest();
  delay(1000);
}
