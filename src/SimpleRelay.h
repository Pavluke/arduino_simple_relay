#include <Arduino.h>

#ifndef _SIMPLERELAY_H
#define _SIMPLERELAY_H

#define RELAY_ON LOW
#define RELAY_OFF HIGH

#define NORMALLY_OPEN true
#define NORMALLY_CLOSE false

class SimpleRelay
{
protected:
    int _pin;
    bool _state;
    bool _is_normally_open;

public:
    /// @brief  Создание реле.
    /// Параметру `is_normally_open` можно передать значения `NORAMALLY_OPEN` / `NORAMALLY_CLOSE`.
    /// @param pin
    /// @param is_normally_open
    SimpleRelay(int pin, bool is_normally_open = NORMALLY_OPEN);

    /// @brief  Инициализация реле.
    /// `init_state` - начальное состояние реле.
    /// Можно передать значения `RELAY_ON` / `RELAY_OFF`.
    /// @param init_state
    void begin(bool init_state = RELAY_ON);
    /// @brief  Получает состояние реле.
    /// @return `true` если реле замкнуто, иначе `false`.
    bool isOn();
    /// @brief  Получает состояние реле.
    /// @return `true` если реле разомкнуто, иначе `false`.
    bool isOff();
    /// @brief  Замыкает реле.
    void on();
    /// @brief  Размыкает реле.
    void off();
    /// @brief  Инвертирует состояние реле.
    /// @return `true` если реле замкнуто, иначе `false`.
    bool toggle();
};
#endif