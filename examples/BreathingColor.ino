#include <Adafruit_NeoPixel.h>

constexpr uint8_t LED_PIN = 8;
constexpr uint8_t NUM_LEDS = 2;    
Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

const uint8_t BASE_R = 180, BASE_G = 0, BASE_B = 255; // purple

void setup() {
  rgbLed.begin();
  rgbLed.show();
}

inline uint8_t scaleColor(uint8_t base, uint8_t level) {
  return (uint8_t)((uint16_t)base * level / 255);
}

void loop() {
  for (int i = 0; i < 512; ++i) {
    uint8_t level = (i < 256) ? i : (511 - i); 

    rgbLed.setPixelColor(0, rgbLed.Color(
      scaleColor(BASE_R, level),
      scaleColor(BASE_G, level),
      scaleColor(BASE_B, level)));

    if (NUM_LEDS > 1) {
      uint8_t inv = 255 - level;
      rgbLed.setPixelColor(1, rgbLed.Color(
        scaleColor(BASE_R, inv),
        scaleColor(BASE_G, inv),
        scaleColor(BASE_B, inv)));
    }

    rgbLed.show();
    delay(5);
  }
}
