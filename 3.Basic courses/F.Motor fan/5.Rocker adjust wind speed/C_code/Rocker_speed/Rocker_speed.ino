/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Rocker_speed
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Rocker adjust speed
* @details
* @par History  
*
*/
int motorpin = 6;//Define digital interface 6 (PWM output)
int VRX = A1; //X axis of joystick connected to analog A0 input
int VRY = A0; //X axis of joystick connected to analog A1 input
int x = 0, y = 0;//Define x,y
int val = 30;//Define val

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
  pinMode(motorpin,OUTPUT);//Define digital interface 2 as output
  pinMode(VRX, INPUT);//Define the X axis of the rocker as an analog input interface
  pinMode(VRY, INPUT);//Define the Y axis of the rocker as an analog input interface
  Serial.begin(9600);
}

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         main function
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void loop() 
{
  x = analogRead(VRX); //Read the analog voltage value of A0 and assign it to x
  y = analogRead(VRY); //Read the analog voltage value of A1 and assign it to y
  if(x > 600)//If rocker X is greater than 600
  {
    val = val + 1;
    delay(100);
    if(val > 100)
    {
      val=100;
    }
    Serial.println(val);
  }
  if(x < 100)
  {
    val = val - 1;
    delay(100);
    if(val < 0)	
    {
      val=0;
    }
    Serial.println(val);
  }
  analogWrite(motorpin,val);
}
