/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Magnet_sensor
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Hall
* @details
* @par History  
*
*/
const int magnet = A3; //Set Hall pin to analog input pin A3
int inputValue = 0;    //Set variable

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
  Serial.begin(115200);      
}


/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         Print the detected Hall value to the serial port display
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop() 
{
  inputValue = analogRead(magnet);  //Assign the read Hall sensor analog value to the variable inputValue
  Serial.println(inputValue);       //Print the variable inputValue value to the serial port display
  delay(500);                       
}
