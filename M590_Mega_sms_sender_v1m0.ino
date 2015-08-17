// http://letsplaywitharduino.blogspot.in/p/gsm-modem-with-arduino-uno.html
// adapted sketch by niq_ro from http://www.tehnic.go.ro
// http://arduinotehniq.blogspot.com/

void setup()
{
  Serial2.begin(115200);  //Baud rate of the GSM/GPRS Module 
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
  Serial2.write(0x1A);  // command for send sms, code for CTRL-Z
  delay(1000); 
}
void loop()
{
}
