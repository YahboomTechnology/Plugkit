/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Drive fan
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Drive motor fan
* @details
* @par History  
*
*/
int motorpin = 6;

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
  pinMode(motorpin, OUTPUT);
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
  analogWrite(motorpin, 100); //30~100
}
