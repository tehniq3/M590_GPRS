// http://letsplaywitharduino.blogspot.in/p/gsm-modem-with-arduino-uno.html
// adapted sketch by niq_ro from http://www.tehnic.go.ro
// http://arduinotehniq.blogspot.com/
// sms sender with 1 button with M590 GPRS module



void setup()
{
  Serial2.begin(115200);  //Baud rate of the GSM/GPRS Module 

  pinMode(A0, INPUT);  // send button is put at A0
  digitalWrite(A0, HIGH); // pull-up the input

  pinMode(13, OUTPUT);  // D13 is output pin

}
void loop()
{
digitalWrite(13, LOW);    // led from D13 is off

   if (digitalRead(A0) == LOW) // if button is push
   {
     digitalWrite(13, HIGH);    // led from D13 is on
   trimitere();
   }

delay(100);
}

void trimitere()
{
  Serial2.print("\r");
  delay(1000);
  Serial2.print("AT+CSCS=\"GSM\"\r");    
  delay(1000);
  Serial2.print("AT+CMGF=1\r");    
  delay(1000);
  Serial2.print("AT+CMGS=\"+407xxxxxxxx\"\r");    //Number to which you want to send the sms
  delay(1000);
  Serial2.print("Test M590 SMS kit module using AT commands from Arduino mega boards - niq_ro\r");   //The text of the message to be sent
  delay(1000);
  Serial2.write(0x1A);
  delay(1000); 
}
