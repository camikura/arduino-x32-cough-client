#include <Arduino.h>
#include <button.h>
#include <led.h>
#include <oled.h>

Oled oled;
Button button;
Led led;

void on_pressed();
void on_released();
