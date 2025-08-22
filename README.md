# ESP32-C6 RGB LED Control

This repository contains Arduino code for controlling the built-in RGB LED on the ESP32-C6 microcontroller. It provides a simple and flexible way to manage LED colors with brightness control.

## Important Note

The built-in RGB LED on the ESP32-C6 is connected to `GPIO 8`. This is already configured in the code, but it's crucial to know if you're working with other components or modifying the pin configuration.

## Features

- Easy control of the built-in RGB LED on GPIO 8
- Predefined color constants for common colors
- Brightness control (0-100%)
- Simple function to set any RGB color
- Easily expandable to include more colors and patterns
- Examples folder with playful patterns (breathing, rainbow, sparkle)

## Software Requirements

- Arduino IDE
- ESP32 board support for Arduino IDE
- Adafruit NeoPixel library

## Installation

1. Install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software)
2. Add ESP32 board support to Arduino IDE:
   - Open Arduino IDE
   - Go to File > Preferences
   - Add the following URL to "Additional Boards Manager URLs":
     `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
   - Go to Tools > Board > Boards Manager
   - Search for "esp32" and install the latest version
3. Install the Adafruit NeoPixel library:
   - Go to Sketch > Include Library > Manage Libraries
   - Search for "Adafruit NeoPixel"
   - Install the latest version

## Usage

1. Download the `esp32_c6_rgb_led_control.ino` file
2. Open the `.ino` file in Arduino IDE
3. Select your ESP32-C6 board from Tools > Board menu
4. Select the appropriate port from Tools > Port menu
5. Click the Upload button to flash the code to your ESP32-C6

### Examples

This repo now includes an `examples/` folder with additional playful sketches you can open directly in the Arduino IDE:

- `BreathingColor.ino` – Smooth "breathing" fade in/out using a purple base color (adjust RGB values for other hues).
- `RandomSparkle.ino` – Random color flashes with variable timing for a subtle sparkle effect.
- `RainbowCycleHSV.ino` – Continuous HSV-based rainbow cycle for smooth full-spectrum transitions.

To try an example, open it from the `examples/` folder, select your board/port, and upload just like the main sketch.

## Example

Here's the basic code structure:

```cpp
#include <Adafruit_NeoPixel.h>
constexpr uint8_t LED_PIN = 8;
constexpr uint8_t NUM_LEDS = 1;
Adafruit_NeoPixel rgbLed(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
struct RGB {
    uint8_t r, g, b;
};

constexpr RGB COLOR_OFF   = {0, 0, 0};
// ...Feel free to add more colors here...
constexpr RGB CUSTOM_COLOR = {255, 0, 255}; 

void setColor(const RGB& color, uint8_t brightness = 100) {
    uint16_t scale = (uint16_t)brightness * 255 / 100;
    uint8_t r = (uint8_t)(((uint16_t)color.r * scale) / 255);
    uint8_t g = (uint8_t)(((uint16_t)color.g * scale) / 255);
    uint8_t b = (uint8_t)(((uint16_t)color.b * scale) / 255);
    rgbLed.setPixelColor(0, rgbLed.Color(r, g, b));
    rgbLed.show();
}

void setup() {
    rgbLed.begin(); 
    rgbLed.show(); 
}

void loop() {
    setColor(CUSTOM_COLOR, 50); // 50% brightness
    delay(1000);
    setColor(COLOR_OFF);
    delay(1000);
}
```

## Customization

- The `LED_PIN` is set to `8` for the built-in LED. **Do not change** this unless you're using an external LED.
- Add new color definitions in the `RGB` struct format
- Adjust brightness by passing a value (0-100) to setColor()
- Create new light patterns by combining `setColor()` and `blinkColor()` functions
- Modify the `BLINK_DURATION` to change the speed of the blinking pattern
- Customize the brightness level in `blinkColor()` by modifying the hardcoded 50% value

## Contributing

Contributions to improve the code or add new features are welcome. Please feel free to submit a pull request or open an issue.