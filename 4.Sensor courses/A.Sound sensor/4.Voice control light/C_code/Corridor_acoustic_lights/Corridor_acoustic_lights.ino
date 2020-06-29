/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Corridor acoustic lights
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Voice control light
* @details
* @par History  
*
*/
int voicepin = A1;
int LED_R = 10;  
int LED_G = 11;  
int LED_B = 9;   
int val = 0;

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
  pinMode(voicepin,INPUT);
  pinMode(LED_G,OUTPUT);
  Serial.begin(9600);
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
  val = analogRead(voicepin);//Read the analog value of the sound sensor and assign it to val
  Serial.println(val);//Serial port print val variable
  if (analogRead(voicepin) >= 400) //Determine whether the received data value meets the range, and you can adjust this parameter according to the current environment
  {
    digitalWrite(LED_G, HIGH); //light is on
    for(int i=0; i<10; i++)//When it senses that there is movement, it turns off after 10s, and the for loop 10 times is 1s * 10 = 10s
    {
      delay(1000);
    } 
  }
  else
  {
    digitalWrite(LED_G, LOW); //light is off
  }
  delay(1000);
}
