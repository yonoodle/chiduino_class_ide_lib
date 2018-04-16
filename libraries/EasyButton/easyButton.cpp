#include "easyButton.h"

//by yonoodle 2018/jan



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

easyButton::easyButton(uint8_t pin, bool prePressed)
{

_pin = pin;
pinMode(_pin,INPUT_PULLUP);

if(prePressed)
    {
		_state=2;
	}
else
    {
    	_state=4;
    }

}

void easyButton::renew()
{
  if(digitalRead(_pin)==LOW)
  {
  	if(_state<3){_state=2;}
    else{_state=1;}
  }
  else
  {
  	if(_state<3){_state=3;}
    else{_state=4;}
  }
}

bool easyButton::isPressed()
{
    return _state<3? true:false; 
}
bool easyButton::onPress()
{
    return _state==1? true:false;	
}
bool easyButton::stillPressed()
{
	return _state==2? true:false;
}

bool easyButton::isReleased()
{
	return _state>2? true:false;
} 
bool easyButton::onRelease()
{
	return _state==3? true:false;
} 
bool easyButton::stillReleased()
{
	return _state==4? true:false;
} 
 