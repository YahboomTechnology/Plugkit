/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Light_intensity
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Read the external light intensity
* @details
* @par History  
*
*/
#define Light A2   
 
int Intensity = 0;

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
  Intensity = analogRead(Light);	//Read the value of analog port AD2 and store it into the Intensity variable
  Serial.print("Intensity = ");  //Serial output"Intensity = "
  Serial.println(Intensity);  //Serial output the value of Intensity variable, and wrap   
  delay(500);			
}
