/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Vibration_alarm
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Vibration_alarm
* @details
* @par History  
*
*/
int LED_R = 10; 
int LED_G = 11;  
int LED_B = 9;  
int SensorINPUT = 3 ;      //Connect the shock switch to interrupt 1, which is digital pin 3
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

  attachInterrupt(1, blink, RISING);   
}

/*
* Function       buzzer warning
* @author        Jessica
* @date          2019.8.21
* @brief         buzzer 
* @param[in]     void
* @retval        void
* @par History   no
*/
void buzWarning()
{
  for(int i=200;i<=800;i++)                //Increase the frequency from 200HZ to 800HZ in a cyclic manner
  {
    tone(buzzerpin,i);                     
    delay(5);                             
  }
  delay(4000);                          
  for(int i=800;i>=200;i--)
  {
    tone(buzzerpin,i);
    delay(10);
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
  if(state!=0)
  {              //if state is not 0
    state = 0;              
    buzWarning();
    digitalWrite(LED_G,HIGH);   //light up
}  
  else 
  {
    noTone(buzzerpin);
    digitalWrite(LED_G,LOW);    
  }
} 

/*
* Function       blink
* @author        Jessica
* @date          2019.8.21
* @brief         Interrupt function
* @param[in]     void
* @retval        void
* @par History   no
*/
void blink()
{                
  state++;       //Once the interrupt is triggered, the state is continuously incremented.
}
