#include <header.h>

void setup() {
  Serial.begin(9600);

  oled = Oled();
  oled.setup();
  oled.clear();

  button = Button();
  button.pressed_handler = on_pressed;
  button.released_handler = on_released;

  led = Led();
}

void loop() { button.scan(); }

void on_pressed() {
  oled.on_pressed();

  led.on();
}

void on_released() {
  oled.clear();
  // oled.on_released();

  led.off();
}
