/**************************************************************************
  This is a library for several Adafruit displays based on ST77* drivers.

  Works with the Adafruit 1.8" TFT Breakout w/SD card
    ----> http://www.adafruit.com/products/358
  The 1.8" TFT shield
    ----> https://www.adafruit.com/product/802
  The 1.44" TFT breakout
    ----> https://www.adafruit.com/product/2088
  as well as Adafruit raw 1.8" TFT display
    ----> http://www.adafruit.com/products/618

  Check out the links above for our tutorials and wiring diagrams.
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional).

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 *************************************************************************/
 
 /*************************************************************************
  * Included as an example in the library, GFX_Thaana.
  * This liabrary works alongside with Adafruit GFX library and
  * Adafruit's driver for the particular display.
  * This example is for a 240x240 ST7789 based display controlled
  * by an ESP8266.
  * 
  * Written by Mohamed Junaidhu.
  *************************************************************************/

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <GFX_Thaana.h>

// Include your font here
#define font dam_kathivalhi18pt8b
#include "Fonts/dam_kathivalhi18pt8b.h"

/***************************************************************
 *      Font name format is FontNameXXpt8b.h
 *      Where XX is font size. Font size are integers from 8 to 24
 *      Avaliable fonts:
 *      dam_kathivalhi , Athuliyun , Faruma , elaaf , LCDThaana , MotaruDhigu
 ***************************************************************/

// ST7789 TFT module connections
#define TFT_DC    D2     // TFT DC  pin is connected to NodeMCU pin D1 (GPIO5)
#define TFT_RST  D1     // TFT RST pin is connected to NodeMCU pin D2 (GPIO4)
#define TFT_CS    D8    // TFT CS  pin is connected to NodeMCU pin D8 (GPIO15)
// initialize ST7789 TFT library with hardware SPI module
// SCK (CLK) ---> NodeMCU pin D5 (GPIO14)
// MOSI(DIN) ---> NodeMCU pin D7 (GPIO13)
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

// Declare GFX_Thaana object
GFX_Thaana dhivehiFont;

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));

  // if the display has CS pin try with SPI_MODE0
  tft.init(240, 240, SPI_MODE2);    // Init ST7789 display 240x240 pixel

  // pass the display object to the liabray
  dhivehiFont.start(tft);

  // if the screen is flipped, remove this command
  tft.setRotation(2);

  Serial.println(F("Initialized"));

  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);

  // tft print function!
  tftPrintTest();
}

void loop() {
}


void tftPrintTest() {
  tft.fillScreen(ST77XX_WHITE);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.setFont(&font);
  tft.setTextWrap(false);

  // Use GFX_Thaana object to set cursor position
  // and print text
  dhivehiFont.setCursor(5, 15);
  dhivehiFont.println(("ީތްސަހ ިބޯލ ިބޯލ ިމ"));
}
