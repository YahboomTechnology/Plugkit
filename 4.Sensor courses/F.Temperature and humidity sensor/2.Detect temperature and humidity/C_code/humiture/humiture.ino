/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         humiture
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Serial port prints out the ambient temperature and humidity
* @details
* @par History  no
*
*/
#include"dht11.h"
#define DHT11PIN 2
dht11 DHT11;

/*
* Function       setup
* @author        Jessica
* @date          2019.8.21
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup() {
  pinMode(DHT11PIN,OUTPUT);
  Serial.begin(9600);
}

/*
* Function       loop
* @author        Jessica
* @date          2019.8.21
* @brief         mian
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void loop() {
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Tep: ");
  Serial.print((float)DHT11.temperature, 2);
  Serial.println("C");
  Serial.print("Hum: ");
  Serial.print((float)DHT11.humidity, 2);
  Serial.println("%");
  Serial.println();
  delay(1000);
}
