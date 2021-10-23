/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x64 pixel oledDisp using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!
file:///home/assasin/Arduino/DhivehiFontTest/GFX_Thaana.cpp

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must befile:///home/assasin/Arduino/DhivehiFontTest/GFX_Thaana.h

 included in any redistribution.
 **************************************************************************/

 /*************************************************************************
  * Included as an example in the library, GFX_Thaana.
  * This liabrary works alongside with Adafruit GFX library and
  * Adafruit's driver for the particular display.
  * This example is for an SSD1306 based display controlled
  * by an 8-bit Arduino AVR board..
  * 
  * Written by Mohamed Junaidhu.
  *************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <GFX_Thaana.h>

// Include your font here
#define font elaaf9pt8b
#include <Fonts/elaaf9pt8b.h>



#define SCREEN_WIDTH 128 // OLED oledDisp width, in pixels
#define SCREEN_HEIGHT 32 // OLED oledDisp height, in pixels

// Declaration for an SSD1306 oledDisp connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 oledDisp(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Declare GFX_Thaana object
GFX_Thaana dhivehiFont;


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate oledDisp voltage from 3.3V internally
  if(!oledDisp.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  //  pass the display object to the liabray
  dhivehiFont.start(oledDisp);
  
  oledDisp.drawPixel(10, 10, SSD1306_WHITE);
  oledDisp.display();
  delay(100);

  testwrite();    // Draw some' characters

}

void loop() {
}

void testwrite(void) {
  oledDisp.clearDisplay();

  oledDisp.setTextSize(1);                                      // Normal 1:1 pixel scale
  oledDisp.setTextColor(SSD1306_WHITE);         // Draw white text
  oledDisp.setFont(&font);                                      // Set the font you want to
  oledDisp.setTextWrap(false);

  // Use GFX_Thaana object to set cursor position
  // and print text
  dhivehiFont.setCursor(0,0); 
  dhivehiFont.println(("ީތްސަހ ިިބޯލ ިބޯލ ިމ"));
  
  oledDisp.display();
  delay(2000);
}
