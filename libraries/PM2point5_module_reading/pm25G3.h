
#include "stdint.h"

#ifndef pm25G3
#define pm25G3

    long * getPMsoft(class SoftwareSerial & x); 
    void getPMsoft_Y(class SoftwareSerial & x , uint16_t *addr); 
    long * getPM();   



    /* use print(*(getPM()+n)) to fetching single value from pointed array

       n =1 for  pm1.0 CF=1  ug/m3
       n =2 for  pm2.5 CF=1  ug/m3
       n =3 for  pm10 CF=1  ug/m3
       n =4 for  pm1.0 atm  ug/m3
       n =5 for  pm2.5 atm  ug/m3
       n =6 for  pm10  atm  ug/m3
      
     */



#endif
