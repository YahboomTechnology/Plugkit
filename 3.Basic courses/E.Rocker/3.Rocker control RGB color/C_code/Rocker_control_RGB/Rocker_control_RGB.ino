
/* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Rocker_control_RGB
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Rocker control RGB
* @details
* @par History  
*
*/
int VRX = A1; //X axis of rocker connected to analog A1 input
int VRY = A0; //Y axis of rocker connected to analog A0 input
int LED_R = 10;  //LED_R connect arduino digital I/O 10
int LED_G = 11;  //LED_G connect arduino digital I/O 11
int LED_B = 9;   //LED_B connect arduino digital I/O 9
int x = 0, y = 0;//Define val

/*
* Function       setup
* @author        Jessica
* @date          2019.8.21
* @brief         Initially configure the joystick as the input port, and the RGB lights are all output ports
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup()
{
  pinMode(VRX, INPUT);   
  pinMode(VRY, INPUT);  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  Serial.begin(9600);
}

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         Remotely switch between different directions and light up different colors
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()
{
  x = analogRead(VRX); //Read the analog voltage value of A0 and assign it to x
  y = analogRead(VRY); //Read the analog voltage value of A1 and assign it to y
  Serial.print("x: "); //Serial printing to view the X axis value of the rocker
  Serial.println(x);
  Serial.print("y: "); //Serial printing to view the Y axis value of the rocker
  Serial.println(y);
    if (x < 100) 
    {
        digitalWrite(LED_R, HIGH);//Set the digital interface value to high and light up red 
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_B, LOW);
    }
    if (x > 600)
    {
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, HIGH);//Set the digital interface value to high and light up green
        digitalWrite(LED_B, LOW);
    }
    if (y < 100)
    {
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_B, HIGH);//Set the digital interface value to high and light up blue
    }
	if (y > 600)
	{
		digitalWrite(LED_R, HIGH);//Set the digital interface value to high and light up red 
		digitalWrite(LED_G, HIGH);//Set the digital interface value to high and light up green
		digitalWrite(LED_B, HIGH);//Set the digital interface value to high and light up blue 
	}
}
