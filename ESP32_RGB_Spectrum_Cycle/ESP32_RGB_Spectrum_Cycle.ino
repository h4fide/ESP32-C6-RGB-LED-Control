#include <Adafruit_NeoPixel.h>
#include <cmath>

// Pin and LED configuration
constexpr uint8_t LED_PIN = 8;
constexpr uint8_t NUM_LEDS = 1;

// NeoPixel object
Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Color structure
struct RGB {
    uint8_t r, g, b;
};

void setup() {
    rgbLed.begin();  // Initialize the RGB LED
    rgbLed.show();   // Turn off the LED (as it's initialized to all 0s)
}

void setColor(const RGB& color) {
    rgbLed.setPixelColor(0, rgbLed.Color(color.r, color.g, color.b));
    rgbLed.show();
}

// Convert HSV to RGB
RGB hsvToRgb(float h, float s, float v) {
    float c = v * s;
    float x = c * (1 - std::abs(std::fmod(h / 60.0, 2) - 1));
    float m = v - c;
    float r, g, b;

    if (h >= 0 && h < 60) {
        r = c, g = x, b = 0;
    } else if (h >= 60 && h < 120) {
        r = x, g = c, b = 0;
    } else if (h >= 120 && h < 180) {
        r = 0, g = c, b = x;
    } else if (h >= 180 && h < 240) {
        r = 0, g = x, b = c;
    } else if (h >= 240 && h < 300) {
        r = x, g = 0, b = c;
    } else {
        r = c, g = 0, b = x;
    }

    return {
        static_cast<uint8_t>((r + m) * 255),
        static_cast<uint8_t>((g + m) * 255),
        static_cast<uint8_t>((b + m) * 255)
    };
}

void loop() {
    constexpr unsigned long CYCLE_DURATION = 10000;  // 10 seconds for a full color cycle
    constexpr unsigned long STEPS = 1000;            // Number of steps in the cycle

    unsigned long startTime = millis();
    unsigned long currentTime;

    while (true) {
        currentTime = millis();
        float progress = static_cast<float>((currentTime - startTime) % CYCLE_DURATION) / CYCLE_DURATION;
        
        float hue = progress * 360.0f;  // Hue ranges from 0 to 360
        RGB color = hsvToRgb(hue, 1.0f, 1.0f);  // Full saturation and value
        
        setColor(color);
        
        delay(CYCLE_DURATION / STEPS);  // Small delay for smooth transition
    }
}
