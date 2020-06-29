/*
*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         IR.ino
* @author       Jessica
* @version      V1.0
* @date         2019.09.17
* @brief        IR serial print data
* @details
* @par History  
*
*/
#include "./IRremote.h"

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

int g_carstate = enSTOP; 
int g_colorlight = 0;

/*
* Function       setup
* @author        Jessica
* @date          2019.09.17
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup()
{

  Serial.begin(9600);	

  irrecv.enableIRIn(); 
  pinMode(RECV_PIN, INPUT_PULLUP);     
}


/*
* Function       IR_Deal
* @author        Jessica
* @date          2019.09.17
* @brief         Infrared receiving data processing
* @param[in]     void
* @retval        void
* @par History   no
*/
void IR_Deal()
{
  if (irrecv.decode(&results))
  {
    //Serial.println(results.value, HEX);

    //Perform different operations based on different values
    //  00FF00FF  switch
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
* Function       IR_Deal
* @author        Jessica
* @date          2019.09.17
* @brief         Infrared receiving data serial port print display
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
    case enLIGHT: Serial.println("LIGHT"); break; //Press the light button, the serial port prints characters LIGHT
    case en0: Serial.println("0"); break;         //Press the 0 button, the serial port prints characters 0
    case en1: Serial.println("1"); break;         //Press the 1 button, the serial port prints characters 1
    case en2: Serial.println("2"); break;         //Press the 2 button, the serial port prints characters 2
    case en3: Serial.println("3"); break;         //Press the 3 button, the serial port prints characters 3
    case en4: Serial.println("4"); break;         //Press the 4 button, the serial port prints characters 4
    case en5: Serial.println("5"); break;         //Press the 5 button, the serial port prints characters 5
    case en6: Serial.println("6"); break;         //Press the 6 button, the serial port prints characters 6
    case en7: Serial.println("7"); break;         //Press the 7 button, the serial port prints characters 7
    case en8: Serial.println("8"); break;         //Press the 8 button, the serial port prints characters 8
    case en9: Serial.println("9");break;          //Press the 9 button, the serial port prints characters 9
    case enPLUS: Serial.println("PLUS"); break;   //Press the + button, the serial port prints characters PLUS
    case enLESS: Serial.println("LESS"); break;   //Press the - button, the serial port prints characters LESS
    case enBEEP: Serial.println("BEEP"); break;   //Press the buzzer button, the serial port prints characters BUZZER
    case enRUN: Serial.println("RUN"); break;     //Press the advance button, the serial port prints characters RUN
    case enLEFT: Serial.println("LEFT"); break;   //Press the turn left button, the serial port prints characters LEFT
    case enRIGHT: Serial.println("RIGHT"); break; //Press the turn right button, the serial port prints characters RIGHT
    case enBACK: Serial.println("BACK"); break;   //Press the turn back button, the serial port prints characters BACK
    case enTLEFT:Serial.println("TLEFT"); break;  //Press the spin left button, the serial port prints characters TLEFT
    case enTRIGHT:Serial.println("TRIGHT");break; //Press the spin right button, the serial port prints characters TRIGHT
    default: break;
  }
  delay(500);
}
