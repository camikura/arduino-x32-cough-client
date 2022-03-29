#include <led.h>

Led::Led() {
  pinMode(PIN_LED1, OUTPUT);
  digitalWrite(PIN_LED1, LOW);
}

void Led::on() { digitalWrite(PIN_LED1, HIGH); }
void Led::off() { digitalWrite(PIN_LED1, LOW); }
