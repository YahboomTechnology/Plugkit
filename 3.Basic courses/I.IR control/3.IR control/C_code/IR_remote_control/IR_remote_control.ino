/*
*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         IR remote control
* @author       Jessica
* @version      V1.0
* @date         2019.09.17
* @brief        IR control
* @details
* @par History  
*
*/
#include "./IRremote.h"
#include <Servo.h>
#define ON 1    
#define OFF 0    
Servo myservo1;//Defining a servo object myservo1
//Servo myservo2;
int seroverupdown = 5; 
//int seroverleftright = 6; 
int motorpin = 6;

/*Key name enumeration*/
enum {
  enSTOP = 0,
  enLIGHT,
  en0,
  en1,
  en2,
  en3,
  en4,
  en5,
  en6,
  en7,
  en8,
  en9,
  enPLUS,
  enLESS,
  enBEEP,
  enRUN,
  enBACK,
  enLEFT,
  enRIGHT,
  enTLEFT,
  enTRIGHT
} enCarState;

int RECV_PIN = 12; //Infrared integrated receiver connected to Arduino pin 12
IRrecv irrecv(RECV_PIN);
decode_results results; //The object used to store the encoding result
unsigned long last = millis();

int buzzerpin = 13;   
int LED_R = 10;  
int LED_G = 11;  
int LED_B = 9;   

int g_carstate = enSTOP; 
int g_colorlight = 0;
long frequency = 900;  
int fan_speed = 30;

/*
* Function       setup
* @author        Jessica
* @date          2019.09.17
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   NO
*/
void setup()
{
  Serial.begin(9600);	

  irrecv.enableIRIn(); 
  pinMode(RECV_PIN, INPUT_PULLUP);     
  pinMode(buzzerpin, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  pinMode(motorpin, OUTPUT);
  myservo1.attach(seroverupdown);

  int ServoPos = 90;
  myservo1.write(ServoPos);
}

/*
* Function       IR_Deal
* @author        Jessica
* @date          2019.09.17
* @brief         红外接收数据处理
* @param[in]     void
* @retval        void
* @par History   无
*/
void IR_Deal()
{
  if (irrecv.decode(&results))
  {
    //Serial.println(results.value, HEX);

    //Perform different operations based on different values
    //  00FF00FF  开关
    //  00FF30CF   +
    //  00FF708F   -
    //  00FFA05F     beep
    //  00FF807F     advance
    //  00FF20DF     turn left
    //  00FF00FF     stop
    //  00FF609F     turn right
    //  00FF906F     back
    //  00FF10EF     spin left
    //  00FF50AF     spin right
    //  00FFB04F     0
    //  00FF08F7     1
    //  00FF8877     2
    //  00FF48B7     3
    //  00FF28D7     4
    //  00FFA857     5
    //  00FF6897     6
    //  00FF18E7     7
    //  00FF9867     8
    //  00FF58A7     9    

      switch (results.value)
      {
        case 0X00FF00FF: g_carstate = enSTOP;  break;
        case 0X00FF40BF: g_carstate = enLIGHT;  break;
        case 0X00FFB04F: g_carstate = en0;  break;
        case 0X00FF08F7: g_carstate = en1;  break;
        case 0X00FF8877: g_carstate = en2;  break;
        case 0X00FF48B7: g_carstate = en3; break;
        case 0X00FF28D7: g_carstate = en4; break;
        case 0X00FFA857: g_carstate = en5; break;
        case 0x00FF6897: g_carstate = en6;  break;
        case 0x00ff18e7: g_carstate = en7; break;
        case 0x00ff9867: g_carstate = en8; break;
        case 0x00ff58a7: g_carstate = en9; break;
        case 0x00FF30CF: g_carstate = enPLUS;  break;
        case 0x00FF708F: g_carstate = enLESS; break;
        case 0x00FFA05F: g_carstate = enBEEP; break;
        case 0x00FF807F:  g_carstate = enRUN; break;
        case 0x00FF20DF:  g_carstate = enLEFT; break;
        case 0x00FF609F:  g_carstate = enRIGHT; break;
        case 0x00FF906F:  g_carstate = enBACK; break;
        case 0x00FF10EF:  g_carstate = enTLEFT; break;
        case 0x00FF50AF:  g_carstate = enTRIGHT; break;
        default: break; //Keep the original state
      }
    last = millis();
    irrecv.resume(); //Receive the next code
  }
  else if (millis() - last > 120)
  {
    g_carstate = enSTOP;
    last = millis();
  }

}

/*
* Function       color_led
* @author        Jessica
* @date          2019.8.21  
* @brief         7 different colors formed by different combinations of R, G, B three colors 
* @param[in1]    Red
* @param[in2]    Green
* @param[in3]    Blue
* @retval        void
* @par History   NO
*/
void color_led(int v_iRed, int v_iGreen, int v_iBlue)
{
   //Red LED
  if (v_iRed == ON)
  {
      digitalWrite(LED_R, HIGH);//Red light is on
  }
  else
  {
      digitalWrite(LED_R, LOW);//Red light is off
  }
  //Green LED
  if (v_iGreen == ON)
  {
      digitalWrite(LED_G, HIGH);//Green light is on
  }
  else
  {
      digitalWrite(LED_G, LOW);//Green light is off
  }
  //Blue LED
  if (v_iBlue == ON)
  {
      digitalWrite(LED_B, HIGH);//Blue light is on
  }
  else
  {
      digitalWrite(LED_B, LOW);//Blue light is off
  }
}

/*
* Function       ColorLED
* @author        Jessica
* @date          2019.8.21   
* @brief         Lanterns alternate in turns
* @param[in]     void
* @retval        void
* @par History   no
*/
void ColorLED()
{    
    color_led(ON, OFF, OFF);   //   1        0        0  red
    delay(2000);
    color_led(OFF, ON, OFF);   //   0        1        0  green
    delay(2000);
    color_led(OFF, OFF, ON);   //   0        0        1  blue
    delay(2000);
    color_led(ON, ON, OFF);    //   1        1        0  yellow
    delay(2000);
    color_led(ON, OFF, ON);    //   1        0        1  magenta
    delay(2000);
    color_led(OFF, ON, ON);    //   0        1        1  cyan
    delay(2000);
    color_led(ON, ON, ON);     //   1        1        1  white
    delay(2000);
}


/*
* Function       BreathLED
* @author        Jessica
* @date          2019.8.21
* @brief         BreathLED
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   no
*/
void BreathLED() 
{
  for(int i = 0; i <= 255; i++) 
  {
    analogWrite(LED_R, i);
    delay(10);
  }
  for(int i = 255; i >= 0; i--)
  {
    analogWrite(LED_R, i);
    delay(10);
  }
}

/*
* Function       IR_Deal
* @author        Jessica
* @date          2019.09.17
* @brief         
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()
{
  IR_Deal();
  switch (g_carstate)
  {
    case enSTOP: break;
    case enLIGHT:digitalWrite(LED_R, !digitalRead(LED_R)); break; 
    case en0: ColorLED(); break;       
    case en1: color_led(ON, OFF, OFF); break;         
    case en2: color_led(OFF, ON, OFF); break;         
    case en3: color_led(OFF, OFF, ON); break;         
    case en4: color_led(ON, ON, OFF); break;          
    case en5: color_led(ON, OFF, ON); break;          
    case en6: color_led(OFF, ON, ON); break;          
    case en7: color_led(ON, ON, ON); break;          
    case en8: color_led(OFF, OFF, OFF); break;        
    case en9: BreathLED() ;break;          
    case enPLUS: fan_speed++;
                 if(fan_speed>100)
                 {
                  fan_speed=100;
                 }
                 analogWrite(motorpin, fan_speed); 
                 break;   
    case enLESS: fan_speed--;
                 if(fan_speed<0)
                 {
                  fan_speed=0;
                 }
                 analogWrite(motorpin, fan_speed); 
                 break;   
    case enBEEP: for (int i = 0; i < 80; i++) 
                {
                  digitalWrite(buzzerpin, HIGH);
                  delay(1);
                  digitalWrite(buzzerpin, LOW); 
                  delay(1);
                }
                 break;   
    case enRUN:  myservo1.write(90);break; 
    case enLEFT:  myservo1.write(0);break; 
    case enRIGHT: myservo1.write(180);break; 
    case enBACK:  
                break; 
    case enTLEFT:for (int pos = 0; pos < 180; pos++)
                {
                  myservo1.write(pos);
                  delay(20);
                } 
                break;  
    case enTRIGHT:for (int pos = 180; pos > 0; pos--)
                {
                  myservo1.write(pos);
                  delay(20);
                } 
                break; 
    default: break;
  }
  delay(500);
}
