
#ifndef ESP8266_yonoodle_h
#define ESP8266_yonoodle_h


//void WatchSerial(string);

void wsend(class SoftwareSerial & x,class String string);

void send_to_web(class SoftwareSerial & x,class String cmd);

void watch_esp8266(class SoftwareSerial & x) ; 

void watch_Serial(class SoftwareSerial & x)  ;


#endif

