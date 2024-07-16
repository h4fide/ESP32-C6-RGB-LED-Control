#include <Adafruit_NeoPixel.h>

constexpr uint8_t LED_PIN = 8;
constexpr uint8_t NUM_LEDS = 1;

Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

struct RGB {
    uint8_t r, g, b;
};

constexpr RGB COLOR_OFF   = {0, 0, 0};

constexpr RGB COLOR_RED   = {255, 0, 0};
constexpr RGB COLOR_GREEN = {0, 255, 0};
constexpr RGB COLOR_BLUE  = {0, 0, 255};
constexpr RGB COLOR_WHITE = {255, 255, 255};
// ...Feel free to add more colors here...
constexpr RGB CUSTOM_COLOR = {255, 0, 255}; 



void setup() {
    rgbLed.begin(); 
    rgbLed.show(); 
}

void setColor(const RGB& color) {
    rgbLed.setPixelColor(0, rgbLed.Color(color.r, color.g, color.b));
    rgbLed.show();
}

void blinkColor(const RGB& color, unsigned long duration) {
    setColor(color);
    delay(duration);
    setColor(COLOR_OFF);
    delay(duration);
}


void loop() {
    constexpr unsigned long BLINK_DURATION = 500;

    blinkColor(COLOR_RED, BLINK_DURATION);
    blinkColor(COLOR_GREEN, BLINK_DURATION);
    blinkColor(COLOR_BLUE, BLINK_DURATION);
    blinkColor(COLOR_WHITE, BLINK_DURATION);
    blinkColor(CUSTOM_COLOR, BLINK_DURATION);
}
