## Important!!
 - KNOWN ISSUE: Text will wrap even if text wrapping is disabled. Enabling text wrapping may cause the library to behave unexpectedly.
 - KNOWN ISSUE: Using F() macro to print to the display does not work.
 - KNOWN ISSUE: It seems like you will have to write backwards under windows OS. This will be fixed soon.
 - Requires Adafruit GFX library.
 - Requires a compatible Adafruit driver for your display.
 - The library was tested with Arduino IDE 1.8.16 running on Ubuntu 20.04.3 LTS. Other combinations of software/OS might not work.
 - Thaana letters will appear as blocks in Arduino IDE 1.8.16 under windows.
 - Fonts are stored in your MCUs program memory. Make sure your chosen MCU has enough memory to hold the font file and the program you are writing.

## What is GFX_Thaana?
 - An Arduino Library.
 - Adds a Thaana character formatter/decoder to all Adafruit GFX based Arduino libraries.
 - Bundles mainstream Thaana 8-Bit GFXfonts compatible with Afadruit GFX library.

## How to install
1. Use arduino library manager to install and update the library.
2. Use the following manual method:
 - Download and extract the library to your Arduino IDE libraries folder. (in Windows: C:\Program Files (x86)\Arduino\libraries)
 - Rename the folder from "GFX_Thaana-main" to "GFX_Thaana"
 - Restrat Arduino IDE software, the library should now be there and examples should appear in the IDE.

## Compatibility
All libraries based on the Adafruit GFX engine are supported. This is an incomplete
list of such libraries. Probably many more are supported:

 - [https://github.com/adafruit/Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306) (tested) 
 - [https://github.com/adafruit/Adafruit-ST7735-Library](https://github.com/adafruit/Adafruit-ST7735-Library) (tested)
 - [https://github.com/adafruit/Adafruit-Graphic-VFD-Display-Library](https://github.com/adafruit/Adafruit-Graphic-VFD-Display-Library) (not tested)
 - [https://github.com/adafruit/Adafruit-HX8340B](https://github.com/adafruit/Adafruit-HX8340B) (not tested)
 - [https://github.com/adafruit/Adafruit_HX8357_Library](https://github.com/adafruit/Adafruit_HX8357_Library) (not tested)
 - [https://github.com/adafruit/Adafruit_ILI9340](https://github.com/adafruit/Adafruit_ILI9340) (not tested)
 - [https://github.com/adafruit/Adafruit_ILI9341](https://github.com/adafruit/Adafruit_ILI9341)  (not tested)
 - [https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library](https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library) (tested)

## Pictures
<img src="/images/st7789.jpg" width="220"/> <img src="/images/ssd1306-64.jpg" width="220"/> <img src="/images/Nokia5110.jpg" width="220"/> 

### Inquiries
You can reach me at mail.junaidhu@gmail.com
