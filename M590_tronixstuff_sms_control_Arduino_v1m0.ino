// http://tronixstuff.com/2014/01/08/tutorial-arduino-and-sim900-gsm-modules/
// base sketch: Example 55.7
// rewrite after phote by niq_ro from http://nicuflorica.blogspot.com/
// and http://arduinotehniq.blogspot.com/
// rewrite for M590 GPRS module by niq_ro - 13.08.2015, Craiova - Romania, Europe, Earth

 
// #include <SoftwareSerial.h> 
char inchar; // Will hold the incoming character from the GSM shield
// SoftwareSerial SIM900(7, 8);
 
int led1 = 10;
int led2 = 11;
int led3 = 12;
int led4 = 13;
 
void setup()
{
 // initialize both serial ports:
  Serial.begin(115200);
  Serial2.begin(115200);
  
  //  Serial.begin(19200);
 // set up the digital pins to control
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
 
  // wake up the GSM shield
//  SIM900power(); 
//  SIM900.begin(19200);
//  delay(20000);  // give time to log on to network.
  delay(5000);
//  SIM900.print("AT+CMGF=1\r");  // set SMS mode to text
Serial.println("set SMS mode to txt");  // set SMS mode to text
Serial2.print("AT+CSCS=\"GSM\"");
Serial2.print("\r");
delay(500);
Serial.println("set SMS mode to txt");  // set SMS mode to text
Serial2.print("AT+CMGF=1\r");  // set SMS mode to text
Serial.println("set SMS mode to txt");  // set SMS mode to text
Serial2.print("AT+CMGF=1\r");  // set SMS mode to text


  delay(500);
//  SIM900.print("AT+CNMI=2,2,0,0,0\r"); 
  // blurt out contents of new SMS upon receipt to the GSM shield's serial out
Serial.println("blurt out contents of new SMS upon receipt to the GSM shield's serial out"); 
Serial2.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(100);
  Serial.println("Ready...");
  
    Serial2.println("AT+CMGD=1,4"); // delete all SMS
            Serial.println("delete all SMS"); // delete all SMS

  
}
 
void SIM900power()
// software equivalent of pressing the GSM shield "power" button
{
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(7000);
}
 
void loop() 
{
  //If a character comes in from the cellular module...
/*  
  if(Serial2.available() >0)
    {
      Serial2.print("AT+CMGR=1\r"); // read the SMS
      while(Serial2.available()) Serial.write(Serial2.read());
    }
  delay(1000);  
*/      
//  if(SIM900.available() >0)
  if(Serial2.available() >0)
    {
//   while(Serial2.available()) Serial.write(Serial2.read());    
      
  //  inchar=SIM900.read(); 
    inchar=Serial2.read(); 
//    Serial.write(inchar);
    if (inchar=='#')
    {
      delay(10);
 
    //  inchar=SIM900.read(); 
    inchar=Serial2.read(); 
      if (inchar=='a')
      {
        delay(10);
     //   inchar=SIM900.read();
     inchar=Serial2.read();
        if (inchar=='0')
        {
          digitalWrite(led1, LOW);
          Serial.println("LED1 stins");
        } 
        else if (inchar=='1')
        {
          digitalWrite(led1, HIGH);
          Serial.println("LED1 aprins");
        }
        delay(10);
        
      // inchar=SIM900.read(); 
      inchar=Serial2.read(); 
        if (inchar=='b')
        {
      //     inchar=SIM900.read();
      inchar=Serial2.read(); 
          if (inchar=='0')
          {
            digitalWrite(led2, LOW);
            Serial.println("LED2 stins");
          } 
          else if (inchar=='1')
          {
            digitalWrite(led2, HIGH);
            Serial.println("LED2 aprins");
          }
          delay(10);
          
      //    inchar=SIM900.read(); 
      inchar=Serial2.read(); 
          if (inchar=='c')
          {
      //      inchar=SIM900.read();
      inchar=Serial2.read(); 
            if (inchar=='0')
            {
              digitalWrite(led3, LOW);
              Serial.println("LED3 stins");
            } 
            else if (inchar=='1')
            {
              digitalWrite(led3, HIGH);
              Serial.println("LED3 aprins");
            }
            delay(10);
           
       //    inchar=SIM900.read(); 
       inchar=Serial2.read(); 
            if (inchar=='d')
            {
              delay(10);
              
       //       inchar=SIM900.read();
       inchar=Serial2.read(); 
              if (inchar=='0')
              {
                digitalWrite(led4, LOW);
                Serial.println("LED4 stins");
              } 
              else if (inchar=='1')
              {
                digitalWrite(led4, HIGH);
                Serial.println("LED4 aprins");
              }
              delay(10);
            }
          }
//          SIM900.println("AT+CMGD=1,4"); // delete all SMS
            Serial2.println("AT+CMGD=1,4"); // delete all SMS
            Serial.println("delete all SMS"); // delete all SMS
        }
      }
    }
  }
}
