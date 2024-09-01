#ifndef _RELAY_h
#define _RELAY_h

#include <Arduino.h>

class Relay
{
    protected:
        int _pin;
        bool _state;
        bool _is_normally_open;

    public:
        Relay(int pin, bool is_normally_open=true);
        void begin(bool init_state=HIGH);
        bool isOn();
        bool isOff();
        void on();
        void off();
        bool invert();
};