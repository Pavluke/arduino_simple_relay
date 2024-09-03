# Простая библиотека для управления реле.

### Добавляем библиотеку в проект:
```ini
// Вписываем в platformio.ini
lib_deps = https://github.com/pavluke/arduino_simple_relay.git
```

### Инициализация:
```cpp
#include <SimpleRelay.h>

// Пин, реле_нормально_разомкнуто 
// Можно использовать `NORMALLY_OPEN`/`NORMALLY_CLOSE` (по дефолту NORMALLY_OPEN)
SimpleRelay relay(int pin, bool is_normally_open);
```

### Настройка:
```cpp
// Начальное значение.
// Можно использовать `RELAY_ON`/`RELAY_OFF`(по дефолту RELAY_ON)
void begin(bool init_state);
```
### Управление:
```cpp
// Замыкает реле.
void on();
// Размыкает реле. 
void off();

// Инвертирует состояние реле.
// После выполнения возвращает статус реле.
// `true` если реле замкнуто, иначе `false`.
bool toggle();
```
### Состояние:
```cpp
// Возвращает `true` если реле замкнуто, иначе `false`.
bool isOn();

// Возвращает `true` если реле разомкнуто, иначе `false`.
bool isOff();
```
