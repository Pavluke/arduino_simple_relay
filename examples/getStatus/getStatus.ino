#include <SimpleRelay.h>

#define RELAY_PIN 2

SimpleRelay relay(RELAY_PIN, NORMALLY_CLOSE);

void setup()
{
    Serial.begin(9600);
    relay.begin(RELAY_OFF);
}
void loop()
{
    relay.on();
    Serial.println("Relay is on: " + relay.isOn());

    delay(1000);

    relay.off();
    Serial.println("Relay is off: " + relay.isOff());

    delay(1000);
}