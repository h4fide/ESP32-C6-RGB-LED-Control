# ESP32-C6 RGB LED Control

This repository contains Arduino code for controlling the built-in RGB LED on the ESP32-C6 microcontroller. It provides a simple and flexible way to manage LED colors.

## Important Note

The built-in RGB LED on the ESP32-C6 is connected to `GPIO 8`. This is already configured in the code, but it's crucial to know if you're working with other components or modifying the pin configuration.

## Features

- Easy control of the built-in RGB LED on GPIO 8
- Predefined color constants for common colors
- Simple function to set any RGB color
- Easily expandable to include more colors and patterns


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

...

## Customization

- The `LED_PIN` is set to `8` for the built-in LED. Do not change this unless you're using an external LED.
- Add new color definitions in the `RGB` struct format
- Create new light patterns by combining `setColor()` function with different delays
- Modify the `BLINK_DURATION` to change the speed of the blinking pattern
- Create new light patterns by combining setColor() and blinkColor() function

...

## Usage

1. Download the `esp32_c6_rgb_led_control.ino` file
2. Open the `.ino` file in Arduino IDE
3. Select your ESP32-C6 board from Tools > Board menu
4. Select the appropriate port from Tools > Port menu
5. Click the Upload button to flash the code to your ESP32-C6

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

void setup() {
    rgbLed.begin(); 
    rgbLed.show(); 
}
void setColor(const RGB& color) {
    rgbLed.setPixelColor(0, rgbLed.Color(color.r, color.g, color.b));
    rgbLed.show();
}
void loop() {
    setColor(CUSTOM_COLOR);
    delay(500);
    setColor(COLOR_OFF);
    delay(500);
}
```

## Contributing

Contributions to improve the code or add new features are welcome. Please feel free to submit a pull request or open an issue.

## License

This project is released under the MIT License. See the `LICENSE` file for details.
