// http://letsplaywitharduino.blogspot.in/p/gsm-modem-with-arduino-uno.html
// adapted sketch by niq_ro from http://www.tehnic.go.ro
// http://arduinotehniq.blogspot.com/
// sms sender with 3 buttons with M590 GPRS module



void setup()
{
  Serial.begin(115200);  //Baud rate of the GSM/GPRS Module 

  pinMode(2, INPUT);  // send button is put at D2
  digitalWrite(A0, HIGH); // pull-up the input

  pinMode(3, INPUT);  // send button is put at D3
  digitalWrite(A0, HIGH); // pull-up the input

  pinMode(4, INPUT);  // send button is put at D4
  digitalWrite(A0, HIGH); // pull-up the input


  pinMode(13, OUTPUT);  // D13 is output pin

}
void loop()
{

if (digitalRead(2) == LOW) // if 1st button is push
   {
     digitalWrite(13, HIGH);    // led from D13 is on
   trimitere();
digitalWrite(13, LOW);    // led from D13 is off
   }

if (digitalRead(3) == LOW) // if 2nd button is push
   {
     digitalWrite(13, HIGH);    // led from D13 is on
   trimitere2();
digitalWrite(13, LOW);    // led from D13 is off
   }

if (digitalRead(2) == LOW) // if 3rd button is push
   {
     digitalWrite(13, HIGH);    // led from D13 is on
   trimitere3();
digitalWrite(13, LOW);    // led from D13 is off
   }


delay(100);
}

void trimitere()
{
  Serial.print("\r");
  delay(1000);
  Serial.print("AT+CSCS=\"GSM\"\r");    
  delay(1000);
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+407xxxxxxxx\"\r");    //Number to which you want to send the sms
  delay(1000);
  Serial.print("Test1 by niq_ro\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000); 
}

void trimitere2()
{
  Serial.print("\r");
  delay(1000);
  Serial.print("AT+CSCS=\"GSM\"\r");    
  delay(1000);
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+407xxxxxxxx\"\r");    //Number to which you want to send the sms
  delay(1000);
  Serial.print("Test2 by niq_ro\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000); 
}

void trimitere3()
{
  Serial.print("\r");
  delay(1000);
  Serial.print("AT+CSCS=\"GSM\"\r");    
  delay(1000);
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+407xxxxxxxx\"\r");    //Number to which you want to send the sms
  delay(1000);
  Serial.print("Test3 by niq_ro\r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000); 
}
