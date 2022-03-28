#include <header.h>

void setup() {
  Serial.begin(9600);

  oled = Oled();
  oled.setup();
  oled.clear();

  button = Button();
  button.pressed_handler = on_pressed;
  button.released_handler = on_released;

  pinMode(PIN_LED1, OUTPUT);
  digitalWrite(PIN_LED1, LOW);
}

void loop() { button.scan(); }

void on_pressed() {
  oled.on_pressed();
  digitalWrite(PIN_LED1, HIGH);
}

void on_released() {
  oled.clear();
  // oled.on_released();
  digitalWrite(PIN_LED1, LOW);
}
