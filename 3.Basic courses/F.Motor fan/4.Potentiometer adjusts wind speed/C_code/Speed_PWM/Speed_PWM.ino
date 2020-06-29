/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Speed_PWM
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Potentiometer adjusts wind speed
* @details
* @par History  
*
*/
int motorpin = 6;//Define digital interface 6 (PWM output)
int potpin = A1;//Define analog interface A1
int val = 0;//Temporary variable value from sensor

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
  pinMode(motorpin,OUTPUT);
  pinMode(potpin,INPUT);
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
  val = analogRead(potpin);//Read the analog value of the potentiometer and assign it to val
  if(val < 300)//limit range
    {
        val = 300;
     }
  if(val > 450)//limit range
    {
        val = 450;
     }
  val = map(val,300,450,0,100);//Map the read analog value to 0-100
  Serial.println(val);//Serial port print val variable
  analogWrite(motorpin,val);//Turn on the fan and set the wind speed (maximum PWM output 100)
  delay(10);//delay 0.01s
}
