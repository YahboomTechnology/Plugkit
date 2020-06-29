/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         LED_PWM
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Control RGB light
* @details
* @par History  
*
*/
int ledpin = 10;  //Use red RGB lights connect I/O 10
int potpin = A1;  //Define analog interface A1
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
  pinMode(ledpin,OUTPUT);//set digital interface 10 pin to input mode
  pinMode(potpin,INPUT);//set analog interface A1 pin to input mode
  Serial.begin(9600);
}

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         Limit the value of the potentiometer to 200 to 450 and map it to 0-255 to the LED pins
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop() 
{
  val = analogRead(potpin);//Read the analog value of the potentiometer and assign it to val
  if(val < 200)//limit range
    {
        val = 200;
     }
  if(val > 450)//limit range
    {
        val = 450;
     }
  val = map(val,200,450,0,255);//Map the read analog value to 0-255
  Serial.println(val);//Serial port print val variable
  analogWrite(ledpin,val);//Turn on the LED and set the brightness (maximum PWM output 255)
  delay(10);//delay 0.01s
}
