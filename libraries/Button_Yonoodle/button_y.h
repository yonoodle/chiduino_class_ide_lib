#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif


class button {
    unsigned long iTimeout;

  public:

  	
  	bool isReleased(unsigned long);
    bool onReleased(unsigned long);
    bool StillReleased(unsigned long);

    bool isReleased(unsigned long);
    bool onReleased(unsigned long);
    bool StillReleased(unsigned long);


    void read(void);
    unsigned long Time(void);
};

