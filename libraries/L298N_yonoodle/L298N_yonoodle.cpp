
#include "Arduino.h"
#include "L298N_yonoodle.h"


/*
 * two-wire constructor.
 * Sets which wires should control the motor.
 */





TTmotor::TTmotor(int pin_1, int pin_2)
{
 
  this->pin_1 = pin_1;
  this->pin_2 = pin_2;



  pinMode(pin_1, OUTPUT);
  pinMode(pin_2, OUTPUT);

  this->wheel_num = 1 ;


}


TTmotor::TTmotor(int Lpin_1, int Lpin_2,int Rpin_1, int Rpin_2)
{
 
  this->Lpin_1 = Lpin_1;
  this->Lpin_2 = Lpin_2;


  this->Rpin_1 = Rpin_1;
  this->Rpin_2 = Rpin_2;



  pinMode(Rpin_1, OUTPUT);
  pinMode(Rpin_2, OUTPUT);

  pinMode(Lpin_1, OUTPUT);
  pinMode(Lpin_2, OUTPUT);

  this->wheel_num = 2 ;

}






void TTmotor::forward(void)
{ 

if(this->wheel_num == 1)

    {


      digitalWrite(pin_1, HIGH);
      digitalWrite(pin_2, LOW);
    }


if(this->wheel_num == 2)
    {

          digitalWrite(Lpin_1, HIGH);
          digitalWrite(Lpin_2, LOW);


          digitalWrite(Rpin_1, HIGH);
          digitalWrite(Rpin_2, LOW);

    }


}




void TTmotor::backward(void)

{ 


if(this->wheel_num == 1)

    {

      digitalWrite(pin_1, LOW);
      digitalWrite(pin_2, HIGH);
    }




if(this->wheel_num == 2)
    {

          digitalWrite(Lpin_1, LOW);
          digitalWrite(Lpin_2, HIGH);


          digitalWrite(Rpin_1, LOW);
          digitalWrite(Rpin_2, HIGH);

    }


}



void TTmotor::brake(void)
{
if(this->wheel_num == 1)

    {


      digitalWrite(pin_1, LOW);
      digitalWrite(pin_2, LOW);
    }




if(this->wheel_num == 2)
    {

          digitalWrite(Lpin_1, LOW);
          digitalWrite(Lpin_2, LOW);


          digitalWrite(Rpin_1, LOW);
          digitalWrite(Rpin_2, LOW);

    }



}





    void TTmotor::turn_right(void)
    {
        if(this->wheel_num == 2)
        {

              digitalWrite(Lpin_1, HIGH);
              digitalWrite(Lpin_2, LOW);


              digitalWrite(Rpin_1, LOW);
              digitalWrite(Rpin_2, HIGH);

        }


    }

    void TTmotor::turn_left(void)
    {
              if(this->wheel_num == 2)
        {

              digitalWrite(Lpin_1, LOW);
              digitalWrite(Lpin_2, HIGH);


              digitalWrite(Rpin_1, HIGH);
              digitalWrite(Rpin_2, LOW);

        }

    }

    void TTmotor::forward_right(void)
    {
                    if(this->wheel_num == 2)
        {

              digitalWrite(Lpin_1, HIGH);
              digitalWrite(Lpin_2, LOW);


              digitalWrite(Rpin_1, LOW);
              digitalWrite(Rpin_2, LOW);

        }

    }

    void TTmotor::forward_left(void)
    {
        if(this->wheel_num == 2)
        {

              digitalWrite(Lpin_1, LOW);
              digitalWrite(Lpin_2, LOW);


              digitalWrite(Rpin_1, HIGH);
              digitalWrite(Rpin_2, LOW);

        }
    }

    void TTmotor::backward_right(void)
    {


         if(this->wheel_num == 2)
        {

              digitalWrite(Lpin_1, LOW);
              digitalWrite(Lpin_2, LOW);


              digitalWrite(Rpin_1, LOW);
              digitalWrite(Rpin_2, HIGH);

        }
    }


    void TTmotor::backward_left(void)
    {
          
                          if(this->wheel_num == 2)
        {

              digitalWrite(Lpin_1, LOW);
              digitalWrite(Lpin_2, HIGH);


              digitalWrite(Rpin_1, LOW);
              digitalWrite(Rpin_2, LOW);

        }
    
    }