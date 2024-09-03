#include <SimpleRelay.h>

#define RELAY_PIN 2

SimpleRelay relay(RELAY_PIN);

void setup()
{
    Serial.begin(9600);
    relay.begin();
}
void loop()
{
    Serial.println("Relay is on: " + relay.toggle());
    delay(1000);
}