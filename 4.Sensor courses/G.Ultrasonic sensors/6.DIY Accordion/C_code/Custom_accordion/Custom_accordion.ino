/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Custom accordion
* @author       xiaojie
* @version      V1.0
* @date         2019.8.21
* @brief        Jessica
* @details
* @par History  no
*
*/

#define NTC1 262
#define NTC2 294
#define NTC3 330
#define NTC4 350
#define NTC5 393
#define NTC6 441
#define NTC7 495
#define NTC8 430


int Echo = 8;  
int Trig = 7; 
int buzzer=13;
int Distance = 0;
void setup()
{
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);   
  pinMode(buzzer,OUTPUT);
}


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

void loop()
{
  Distance_test();
  if((0<Distance)&(Distance<8))
  {
    tone(buzzer,NTC1);
    delay(1000);   //Adjust the delay according to the beat
    noTone(buzzer);
  }
  else if((8<Distance)&(Distance<16))
  {
    tone(buzzer,NTC2);
    delay(1000);  
    noTone(buzzer);
  }
  else if((16<Distance)&(Distance<24))
  {
    tone(buzzer,NTC3);
    delay(1000);   
    noTone(buzzer);
  }
  else if((24<Distance)&(Distance<32))
  {
    tone(buzzer,NTC4);
    delay(1000);   
    noTone(buzzer);
  }
  else if((32<Distance)&(Distance<40))
  {
    tone(buzzer,NTC5);
    delay(1000);   
    noTone(buzzer);
  }
  else if((40<Distance)&(Distance<48))
  {
    tone(buzzer,NTC6);
    delay(1000);  
    noTone(buzzer);
  }
  else if((48<Distance)&(Distance<56))
  {
    tone(buzzer,NTC7);
    delay(1000);   
    noTone(buzzer);
  }
  else if((56<Distance)&(Distance<64))
  {
    tone(buzzer,NTC8);
    delay(1000); 
    noTone(buzzer);
  }
  else
  {
    noTone(buzzer);
  }
}
