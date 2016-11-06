/*
  version 1

keyword

TTmotor



methods

forward(unsigned long duration in millisecond);
backward(unsigned long duration in millisecond);
off(void)
brake(void)


*/

// ensure this library description is only included once

#ifndef TTmotor_h

#define TTmotor_h

// library interface description
class TTmotor {
  public:
    // constructors:

   
    TTmotor(int pin_1, int pin_2);
    TTmotor(int Lpin_1, int Lpin_2, int Rpin_1, int Rpin_2);
  

    // methods

    void forward(void);

    void backward(void);


    void brake(void);




    void turn_right(void);

    void turn_left(void);

    void forward_right(void);

    void forward_left(void);

    void backward_right(void);

    void backward_left(void);



  private:
       
    // motor pin numbers:
    int pin_1;
    int pin_2;
    

    int Lpin_1;
    int Lpin_2;

    int Rpin_1;
    int Rpin_2;

    int wheel_num;
};

#endif

