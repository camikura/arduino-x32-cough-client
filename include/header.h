#include <Arduino.h>
#include <button.h>
#include <oled.h>

#define PIN_LED1 4

Oled oled;
Button button;

void on_pressed();
void on_released();

void light_on();
void light_off();
