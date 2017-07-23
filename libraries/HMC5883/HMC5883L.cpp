/*
HMC5883L.cpp 

yonoodle 20170722

*/

#include <Arduino.h> 
#include "HMC5883L.h"

void HMC5883L::read_mag()
{

	  // Initiate communications with compass
  Wire.beginTransmission(Addr);
  Wire.write(0x03);              // Send request to X MSB register
  Wire.endTransmission();

  Wire.requestFrom(Addr, 6);    // Request 6 bytes; 2 bytes per axis
  if(Wire.available() <=6) {    // If 6 bytes available
    x = Wire.read() << 8 | Wire.read();
    z = Wire.read() << 8 | Wire.read(); //it is z,not y, it is correct.
    y = Wire.read() << 8 | Wire.read();
  }

	rx = -1.0 + 2.0*(float)(x-mx)/(float)(Mx-mx);
	ry = -1.0 + 2.0*(float)(y-my)/(float)(My-my);
	rz = -1.0 + 2.0*(float)(z-mz)/(float)(Mz-mz);

}



void HMC5883L::begin(int new_addr)
{
  Addr=new_addr;
  Wire.begin();  
  // Set operating mode to continuous
  Wire.beginTransmission(Addr); 
  Wire.write(0x02);
  Wire.write(0x00);
  Wire.endTransmission();
}

void HMC5883L::set_calib(int _mx,int _Mx,int _my ,int _My,int _mz,int _Mz)
{
mx = _mx;my = _my;mz = _mz;
Mx = _Mx;My = _My;Mz = _Mz;
}



void HMC5883L::show_cal_info()
{
 
 read_mag();

 if(x>Mx){Mx=x;} if(y>My){My=y;} if(z>Mz) {Mz=z;}
 if(x<mx){mx=x;} if(y<my){my=y;} if(z<mz) {mz=z;}


Serial.print(x);Serial.print(",");
Serial.print(y);Serial.print(",");
Serial.print(z);Serial.print(",");

Serial.print(mx);Serial.print(",");
Serial.print(Mx);Serial.print(",");

Serial.print(my);Serial.print(",");
Serial.print(My);Serial.print(",");

Serial.print(mz);Serial.print(",");
Serial.println(Mz);



}







