/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Magnet_detector
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Magnet_detector
* @details
* @par History  
*
*/
const int magnet = A3; 
int LED_R = 10;  
int LED_G = 11;  
int LED_B = 9;  
int buzzerpin = 13;    
int inputValue = 0; 

long frequency = 900; 

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
  pinMode(magnet, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  Serial.begin(9600);
}

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         Alarm is detected when magnet is detected, otherwise the green light is always on
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop() 
{
  inputValue = analogRead(magnet);
  Serial.println(inputValue);
  if(inputValue <= 1)
  {
    Detected();
  }
  else
  {
    Not_detected();
  }
}

/*
* Function       Detected
* @author        Jessica
* @date          2019.8.21
* @brief         Alarm, red light flashing and whistle five times
* @param[in]     void
* @retval        void
* @par History   no
*/
void Detected()
{
  for(int i = 0; i < 5; i++)  
  {
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_R, HIGH);
    tone(buzzerpin, frequency);
    delay(100);
    digitalWrite(LED_R, LOW);
    noTone(buzzerpin);
    delay(100);
  }
}

/*
* Function       Not_detected
* @author        Jessica
* @date          2019.8.21
* @brief         green light keep on
* @param[in]     void
* @retval        void
* @par History   no
*/
void Not_detected()
{
  digitalWrite(LED_G, HIGH);
  noTone(buzzerpin);
}
