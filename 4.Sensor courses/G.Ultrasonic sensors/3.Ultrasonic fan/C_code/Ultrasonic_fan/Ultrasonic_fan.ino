/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Ultrasonic_fan
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Ultrasonic_fan
* @details
* @par History  
*
*/
int motorpin = 6;//Define digital interface 5 (PWM output)

int Echo = 8;  
int Trig =7; 

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
  pinMode(motorpin,OUTPUT);//Define digital interface 5 as output
  
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  
  Serial.begin(9600);
}

/*
* Function       Distance_test
* @author        Jessica
* @date          2019.8.21
* @brief         Distance_test
* @param[in]     void
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
  Serial.print("Distance:");     
  Serial.print(Distance);        
  Serial.println("cm");        
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
  if(Distance < 30)
  {
     analogWrite(motorpin, 40);
     delay(2000);
  }
  else
  {
     analogWrite(motorpin, 0);
  }
}
