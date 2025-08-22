#include <Adafruit_NeoPixel.h>

constexpr uint8_t LED_PIN = 8;
constexpr uint8_t NUM_LEDS = 1;

// brightness variable (0-255 range)
constexpr uint8_t brightness = 255;

Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  rgbLed.begin();
  rgbLed.setBrightness(brightness);
  rgbLed.show();
  randomSeed(analogRead(A0)); // seed randomness (A0 floating is fine)
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
  rgbLed.setPixelColor(0, rgbLed.Color(r, g, b));
  rgbLed.show();
}

void loop() {
  uint8_t r = random(0, 256);
  uint8_t g = random(0, 256);
  uint8_t b = random(0, 256);
  setColor(r, g, b);
  delay(150 + random(0, 400));
  setColor(0, 0, 0);
  delay(50 + random(0, 200));
}