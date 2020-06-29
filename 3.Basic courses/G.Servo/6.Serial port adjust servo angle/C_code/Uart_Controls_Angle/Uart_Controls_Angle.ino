/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Uart Controls Angle
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Uart Controls Angle
* @details
* @par History  
*
*/
//UART send 1~9==>20~180 degree
int servopin = 5;
int myangle;
int pulsewidth;
int val;
void servopulse(int servopin,int myangle)/*Define a pulse function to generate PWM value in analog mode */
{
  pulsewidth=(myangle*11)+500;//Converts the angle to a pulse width value of 500-2480
  digitalWrite(servopin,HIGH);//Set servo port to high level
  delayMicroseconds(pulsewidth);
  digitalWrite(servopin,LOW);//Set servo port to low level
  delay(20-pulsewidth/1000);//Time remaining in the delay period
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
  pinMode(servopin,OUTPUT);//Set the servo interface as the output port
  Serial.begin(9600);
  Serial.println("servo=o_seral_simple ready" ) ;
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
  val=Serial.read();//Read the data received by the serial port
  if(val>'0'&&val<='9')//Determine whether the received data value meets the range
  {
    val=val-'0';//Convert ASCII code to numeric value, eg:'9'-'0'=0x39-0x30=9
    val=val*(180/9);//Convert numbers to angles, example 9 * (180/9) = 180
    Serial.print("moving servo to ");
    Serial.print(val,DEC);
    Serial.println();
    for(int i=0;i<=50;i++) //equivalent delay to ensure that it can turn to the response angle
    {
      servopulse(servopin,val);
    }
  }
}
