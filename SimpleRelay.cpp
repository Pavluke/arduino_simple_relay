#include "SimpleRelay.h"

#define RELAY_ON  true
#define RELAY_OFF false

Relay::Relay(int pin, bool is_normally_open){
	_pin = pin;
	_is_normally_open = is_normally_open;
}

void Relay::begin(bool init_state){
	pinMode(_pin, OUTPUT);
    _state = _is_normally_open ? init_state : !init_state;
    digitalWrite(_pin, _state);
}

bool Relay::isOn(){
    return _is_normally_open 
		? !_state
		: _state;
}

bool Relay::isOff(){
    return _is_normally_open 
		? _state
		: !_state;
}

void Relay::on(){
	if ((_is_normally_open && !_state) ||
		(!_is_normally_open && _state)) return;
	invert();
}

void Relay::off(){
	if ((_is_normally_open && _state) ||
		(!_is_normally_open && !_state))  return;
	invert();
}

bool Relay::invert(){
	digitalWrite(_pin, _state);
	_state = !_state;
	return _state;
}