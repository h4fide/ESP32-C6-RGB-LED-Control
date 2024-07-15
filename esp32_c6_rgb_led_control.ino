#include <Adafruit_NeoPixel.h>

#define LED_PIN 8  // The ESP32-C6 pin connected to the built-in RGB LED
#define NUM_LEDS 1

Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);


struct RGB {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

const RGB COLOR_RED = {255, 0, 0};
const RGB COLOR_GREEN = {0, 255, 0};
const RGB COLOR_BLUE = {0, 0, 255};
const RGB COLOR_WHITE = {255, 255, 255};
// .....Feel free to add more colors as needed0
const RGB LED_OFF = {0, 0, 0};

void setup() {
    rgbLed.begin();  
    rgbLed.show();  
}

void setColor(const RGB& color) {
    rgbLed.setPixelColor(0, color.red, color.green, color.blue);
    rgbLed.show();
}

void loop() {

    // Example: Blink the built-in LED
    setColor(COLOR_RED);
    delay(1000);
    setColor(LED_OFF);
    delay(1000);
}