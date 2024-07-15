# ESP32-C6-RGB-LED-Control
This repository contains Arduino code for controlling the built-in RGB LED on the ESP32-C6 microcontroller. It provides a simple and flexible way to manage LED colors and create blinking patterns.

## Features

- Easy control of the built-in RGB LED
- Predefined color constants for common colors
- Simple function to set any RGB color
- Flexible blinking function with customizable timing
- Example usage demonstrating various light patterns

## Hardware Requirements

- ESP32-C6 board (ensure your board has a built-in RGB LED)

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

1. Clone this repository or download the `esp32_c6_rgb_led_control.ino` file
2. Open the `.ino` file in Arduino IDE
3. Select your ESP32-C6 board from Tools > Board menu
4. Select the appropriate port from Tools > Port menu
5. Click the Upload button to flash the code to your ESP32-C6

## Customization

- Modify the `LED_PIN` constant if your built-in LED uses a different GPIO pin
- Add new color definitions in the `RGB` struct format
- Create new light patterns by combining `setColor()` and `blinkColor()` functions

## Example

The provided example in the `loop()` function demonstrates blinking the LED in red, green, and blue:

```cpp
void loop() {
    blinkColor(COLOR_RED, 3, 500, 500);    // Blink red 3 times
    delay(1000);
    blinkColor(COLOR_GREEN, 3, 500, 500);  // Blink green 3 times
    delay(1000);
    blinkColor(COLOR_BLUE, 3, 500, 500);   // Blink blue 3 times
    delay(1000);
}
```

## Contributing

Contributions to improve the code or add new features are welcome. Please feel free to submit a pull request or open an issue.

## License

This project is released under the MIT License. See the `LICENSE` file for details.

## Acknowledgments

- Thanks to Adafruit for their NeoPixel library
- Inspired by the ESP32 community and various LED control projects
