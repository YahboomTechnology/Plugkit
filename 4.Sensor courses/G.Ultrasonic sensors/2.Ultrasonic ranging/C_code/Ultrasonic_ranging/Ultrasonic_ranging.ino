/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Ultrasonic_ranging
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Ultrasonic_ranging
* @details
* @par History  no
*
*/
int Echo = 8;  
int Trig = 7; 

int Distance = 0;

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
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);   
}

/*
* Function       Distance_test
* @author        Jessica
* @date          2019.8.21
* @brief         Distance_test
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void Distance_test()   
{
  digitalWrite(Trig, LOW);   //Give the trigger pin a low level of 2μs
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  //Give the trigger pin a high level of at least 10 μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    //Continue to give trigger pin low level
  float Fdistance = pulseIn(Echo, HIGH);  //Read high time (unit: microsecond)
  Fdistance= Fdistance/58;       //Y meters = (X seconds * 344) / 2
  // X seconds=（ 2*Y meters）/344 ==》X seconds=0.0058*Y meters ==》cm = microseconds/58
  Distance = Fdistance;
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
  Distance_test();
  Serial.print("Distance:");     
  Serial.print(Distance);         
  Serial.println("cm");        
  delay(1000);
}
