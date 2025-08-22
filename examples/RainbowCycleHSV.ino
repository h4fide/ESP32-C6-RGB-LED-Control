#include <Adafruit_NeoPixel.h>
#include <cmath>

constexpr uint8_t LED_PIN = 8;
constexpr uint8_t NUM_LEDS = 1;

Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// brightness variable (0-255)
uint8_t brightness = 255; 

struct RGB { uint8_t r, g, b; };

RGB hsvToRgb(float h, float s, float v) {
  float c = v * s;
  float x = c * (1 - fabs(fmod(h / 60.0f, 2) - 1));
  float m = v - c;
  float r=0, g=0, b=0;
  if (h < 60) { r=c; g=x; }
  else if (h < 120) { r=x; g=c; }
  else if (h < 180) { g=c; b=x; }
  else if (h < 240) { g=x; b=c; }
  else if (h < 300) { r=x; b=c; }
  else { r=c; b=x; }
  return { 
    (uint8_t)((r+m) * brightness), 
    (uint8_t)((g+m) * brightness), 
    (uint8_t)((b+m) * brightness) 
  };
}

void setup() {
  rgbLed.begin();
  rgbLed.show();
}

void setColor(const RGB &c) {
  rgbLed.setPixelColor(0, rgbLed.Color(c.r, c.g, c.b));
  rgbLed.show();
}

void loop() {
  constexpr float cycleMs = 6000.0f; // 6 second full loop
  unsigned long ms = millis();
  float hue = fmod(ms, (unsigned long)cycleMs) / cycleMs * 360.0f;
  RGB c = hsvToRgb(hue, 1.0f, 1.0f);
  setColor(c);
  delay(10); // smooth
}