/*********************************************************************
This is an example sketch for our Monochrome Nokia 5110 LCD Displays

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/338

These displays use SPI to communicate, 4 or 5 pins are required to
interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

/*************************************************************************
  * Included as an example in the library, GFX_Thaana.
  * This liabrary works alongside with Adafruit GFX library and
  * Adafruit's driver for the particular display.
  * This example is for NOKIA 5110 based display controlled
  * by an ESP8266.
  * 
  * Written by Mohamed Junaidhu.
  *************************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <GFX_Thaana.h>

// Include your font here
#define font elaaf9pt8b
#include <Fonts/elaaf9pt8b.h>

/*
 *      Font name format is FontNameXXpt8b.h
 *      Where XX is font size. Font size are integers from 8 to 24
 *      Avaliable fonts:
 *      dam_kathivalhi , Athuliyun , Faruma , elaaf , LCDThaana , MotaruDhigu
 */

// Declare GFX_Thaana object
GFX_Thaana dhivehiFont;

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(D4, D3, D5, D2, D0);

// Hardware SPI (faster, but must use certain hardware pins):
// SCK is LCD serial clock (SCLK) - this is pin 13 on Arduino Uno
// MOSI is LCD DIN - this is pin 11 on an Arduino Uno
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
// Adafruit_PCD8544 display = Adafruit_PCD8544(5, 4, 3);
// Note with hardware SPI MISO and SS pins aren't used but will still be read
// and written to during SPI transfer.  Be careful sharing these pins!


void setup()   {
  Serial.begin(9600);
Serial.println("PCD test");
  display.begin();
  // init done
  
  //  pass the display object to the liabray
  dhivehiFont.start(display);

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(70);

  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer

  // text display tests
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setFont(&font);                                      // Set the font you want to
  display.setTextWrap(false);
  
  // Use GFX_Thaana object to set cursor position
  // and print text
  dhivehiFont.setCursor(3,-9); 
  dhivehiFont.println(("ީތްސަހ ިިބޯލ ިބޯލ ިމ"));
  
  display.display();
  delay(2000);

}


void loop() {
  
}
