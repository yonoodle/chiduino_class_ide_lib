#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

// by yonoodle 2018/jan



/*

original state   
1 or 2是按下的   
1剛被按下    
2仍是按下的     
3 or 4是放開的   
3剛被放開    
4仍是放開的

new input and new state

Low按下   2  2  2  1  1  1

HIGH放開  3  3  3  4  4  4   


*/

class easyButton {
    
  public:

    easyButton(uint8_t,bool);    // pin and initial state
  	
    void renew();

  	bool isPressed();
    bool onPress();
    bool stillPressed();

    bool isReleased();
    bool onRelease();
    bool stillReleased();   
    
  private:

    uint8_t _pin;    
    uint8_t _state;            

};

