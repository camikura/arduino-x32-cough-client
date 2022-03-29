#include <FlexiTimer2.h>
#include <header.h>

// 27, 25, 24
#define ID 0x01  // ch ID

#define PIN_485 7

volatile bool pressed = false;

void setup() {
  Serial.begin(9600);
  Serial1.begin(31250);  // 485

  oled = Oled();
  oled.setup();
  oled.clear();

  button = Button();
  button.pressed_handler = on_pressed;
  button.released_handler = on_released;

  led = Led();

  pinMode(PIN_485, OUTPUT);  // 485 Enable
  digitalWrite(PIN_485, 0);  // 485 is receive

  FlexiTimer2::set(5 * ID, response);
}

void loop() {
  button.scan();
  delay(5);
}

void on_pressed() { pressed = true; }

void on_released() {}

void serialEvent1() {
  while (Serial1.available()) {
    byte input = (byte)Serial1.read();
    if (input == 0xf0) {
      FlexiTimer2::start();
    }
  }
}

void response() {
  FlexiTimer2::stop();

  if (pressed) {
    byte data = 0x80 + ID;
    digitalWrite(PIN_485, 1);
    Serial1.write(data);
    Serial1.flush();
    digitalWrite(PIN_485, 0);
    pressed = false;
  }
}
