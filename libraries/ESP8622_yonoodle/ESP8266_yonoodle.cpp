
#include "Arduino.h"
#include "ESP8266_yonoodle.h"
#include  <SoftwareSerial.h>


void wsend(class SoftwareSerial & x,class String string)
{

  //Serial.println("command sent to esp8266:\n"+string); 
  x.print(string); 
x.flush();
delay(50);
  
  /*

 char c;
  String msg = "";
 

  while (x.available())
      {        
      c = x.read();
      Serial.print(c);
        msg += c ;         
      }
      
  Serial.println("esp8266 replied:\n"+msg);  
*/
  
  
}

void send_to_web(class SoftwareSerial & x,class String cmd)
{
wsend(x,"AT+CIPSEND=" + (String)cmd.length() +"\r\n");
wsend(x,cmd);
}





void watch_esp8266(class SoftwareSerial & x)  
{
  

     if (x.available())
      { 
         char c;
        c = x.read();
        Serial.write(c); 
        }

}




void watch_Serial(class SoftwareSerial & x)  
 {

  if (Serial.available())
     {
       String cmd = "";
       delay(1000);
       while(Serial.available())
        {
          cmd+=(char)Serial.read();
          delay(20);
        }
        x.println(cmd);       
     }
 }