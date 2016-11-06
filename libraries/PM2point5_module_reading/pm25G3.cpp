#include "pm25G3.h"
#include <SoftwareSerial.h>
#include "Arduino.h"


long * getPMsoft(class SoftwareSerial & x)
{

	    unsigned char high;
	    unsigned char low;

	    static long value[6];

		long ini_time;

		ini_time=millis();

		while(millis()-ini_time<5000)
		{

		  			if(x.available()>10)
					  {
					  	if(x.read()==0x42)
					  	{					  			  

					  		if(x.read()==0x4d)
					  		{

							  	for(int i=0;i<7;i++)
							  	{

							 	high=256*x.read();
							 	low=x.read();

									 	if(i>0)
									 	{
									 	value[i-1] =high+low; 
									 	}
		

						 		}

						 		while (x.available())
						 		{x.read();}

						 		return value;

						  }
						}
					}
		 

		 	}

	
}





long * getPM()
{

	    unsigned char high;
	    unsigned char low;

	    static long value[6];

		long ini_time;

		ini_time=millis();

		while(millis()-ini_time<5000)
		{

		  			if(Serial.available()>10)
					  {
					  	if(Serial.read()==0x42)
					  	{					  			  

					  		if(Serial.read()==0x4d)
					  		{

							  	for(int i=0;i<7;i++)
							  	{

							 	high=256*Serial.read();
							 	low=Serial.read();

									 	if(i>0)
									 	{
									 	value[i-1] =high+low; 
									 	}
		

						 		}

						 		while (Serial.available())
						 		{Serial.read();}

						 		return value;

						  }
						}
					}
		 

		 	}

	
}

