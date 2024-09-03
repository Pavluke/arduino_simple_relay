#include "SimpleRelay.h"

SimpleRelay::SimpleRelay(int pin, bool is_normally_open)
{
	_pin = pin;
	_is_normally_open = is_normally_open;
}

void SimpleRelay::begin(bool init_state)
{
	pinMode(_pin, OUTPUT);
	_state = _is_normally_open ? init_state : !init_state;
	digitalWrite(_pin, _state);
}

bool SimpleRelay::isOn()
{
	return _is_normally_open
			   ? !_state
			   : _state;
}

bool SimpleRelay::isOff()
{
	return _is_normally_open
			   ? _state
			   : !_state;
}

void SimpleRelay::on()
{
	if ((_is_normally_open && !_state) ||
		(!_is_normally_open && _state))
		return;
	toggle();
}

void SimpleRelay::off()
{
	if ((_is_normally_open && _state) ||
		(!_is_normally_open && !_state))
		return;
	toggle();
}

bool SimpleRelay::toggle()
{
	digitalWrite(_pin, _state);
	_state = !_state;
	return _state;
}