/*
HMC5883L.h - Header file for the HMC5883L Triple Axis Magnetometer Arduino Library.
Copyright (C) 2011 Love Electronics (loveelectronics.co.uk) / 2012 bildr.org (Arduino 1.0 compatible)

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

 WARNING: THE HMC5883L IS NOT IDENTICAL TO THE HMC5883!
 Datasheet for HMC5883L:
 http://www51.honeywell.com/aero/common/documents/myaerospacecatalog-documents/Defense_Brochures-documents/HMC5883L_3-Axis_Digital_Compass_IC.pdf

*/

#ifndef HMC5883L_h
#define HMC5883L_h

#include <Arduino.h>
#include <Wire.h>

class HMC5883L
{
	public:
	//  HMC5883L();

		void read_mag();

		void begin(int);
		
		void set_calib(int,int,int,int,int,int);
		
		void ;   // offset xyz,  amplitude xyz

		void show_cal_info();

		int x;  //raw data
		int y;
		int z;


		float rx;  //ratio output x ,y ,z
		float ry;
		float rz;

	protected:
	private:

		int Addr = 0x1E;  //7 bit address

		int Mx =-3000 ;  //Max
		int My =-3000 ; 
		int Mz =-3000 ; 

		int mx =3000 ;  //Min
		int my =3000 ; 
		int mz =3000 ; 


};
#endif