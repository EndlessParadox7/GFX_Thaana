/*



*/

#ifndef GFX_Thaana_h
#define GFX_Thaana_h

#include <Adafruit_GFX.h>

#include <Arduino.h>


struct _thaana_writer {
  Adafruit_GFX * gfx;

};
typedef struct _thaana_writer thaana_writer;

class GFX_Thaana: public Print {
  public: thaana_writer writer;
  int16_t tx, ty; // current position for the print command
  int16_t dx; 	  // current position for the print command
  int16_t x1,y1; // current position for the print command
  uint16_t w, h; // current position for the print command

  void home(void) {
    tx = 0;
    ty = 0;
    Serial.begin(9600);
  }

  void setCursor(int16_t x, int16_t y) {
    tx = x;
    ty = y;
    writer.gfx -> setCursor(x, y);
    //Serial.println(writer.gfx-> getCursorX());
    //Serial.println(writer.gfx-> getCursorY());
  }

  int16_t getCursorX(void) {
    return tx;
  }

  int16_t getCursorY(void) {
    return ty;
  }

  void start(Adafruit_GFX & gfx) {
    writer.gfx = & gfx;
  }

  size_t write(uint8_t v) {
    if (v != 222) {
      //Serial.println(v);
      writer.gfx -> write(v);
      return 1;
    }
  }

  // Catches print and write calls from main file
  size_t write(const uint8_t * buffer, size_t size) {
    const uint8_t * input;
    input = buffer;
    size_t cnt = 0;
    uint16_t width = writer.gfx -> width(); // Get display width
    bool first_try = true;
    uint8_t prev_line_break = size;
    uint8_t prev_test_point;
    uint16_t width_temp = 0;
    uint16_t ht;
    uint8_t blank_char = 222;
    uint8_t offset = 28;

    writer.gfx -> getTextBounds((const char*)input, tx, ty, & x1, & y1, & w, & h); // Get text bounds
    h = h + ty;
    width = width - tx; // Writable width
    dx = width - w; // If dx is a negative number text wrapping can happen

    for (int8_t n = prev_line_break; n >= 0; n--) { // Test each character in input starting backwards

      if (input[n] == 32 || n == 0) { // If we encounter a space or reach the end of the array

        char temp[prev_line_break - n + 1];
        bool lastLine = (n == 0);

        for (uint8_t n1 = n; n1 <= prev_line_break; n1++) { // Get text in a temporary char array
          // This is where character decoding should occur
          // Decoding some Dhivehi symbols like question mark
          if (input[n1] == 194) {
            temp[n1 - n] = blank_char;
            n1 += 1;
            temp[n1 - n] = input[n1] - 1;
          } else if (input[n1] == 216) {
            temp[n1 - n] = blank_char;
            n1 += 1;
            temp[n1 - n] = input[n1] + offset;
          } else if (input[n1] == 226) {
            temp[n1 - n] = blank_char;
            n1 += 1;
            temp[n1 - n] = blank_char;
            n1 += 1;
            if(input[n1] > 154){
            	temp[n1 - n] = input[n1] + 29;
            }else{
            	temp[n1 - n] = input[n1] + offset;
            }
          } else if (input[n1] == 239) {
            Serial.println("A hit found");
            temp[n1 - n] = blank_char;
            n1 += 1;
            temp[n1 - n] = blank_char;
            n1 += 1;
            temp[n1 - n] = input[n1] + 1;
          } else {
            temp[n1 - n] = input[n1];
          }
        }

        writer.gfx -> getTextBounds(temp, tx, ty, & x1, & y1, & w, & ht); // Get the bounds of the temporary char array

        if ((w < width) && (n != 0)) { // Width less than screen width and not last line
          prev_test_point = n; // Record current position as a valid test point
          width_temp = w; // Record the width at current point
        }

        if ((w > width) && (width_temp != 0)) { // Greater than screen width 
          int16_t temp_width = width - width_temp;
          writer.gfx -> setCursor(temp_width, h);
          // Should be done only on the first iteration
          first_try = false;

          /*Print the characters one by one starting from prev test point
          till the line break point.*/
          for (uint8_t n2 = prev_test_point; n2 <= prev_line_break; n2++) {
            
            // Decoding some Dhivehi symbols like question mark
            if (input[n2] == 194) {
              n2 += 1;
              cnt += write((uint8_t) input[n2] - 1);
            } else if (input[n2] == 216) {
              n2 += 1;
              cnt += write((uint8_t) input[n2] + offset);
            } else if (input[n2] == 226) {
              n2 += 2;
              if(input[n2] > 154){
            	cnt += write((uint8_t) input[n2] + 29);
              }else{
                cnt += write((uint8_t) input[n2] + offset);
              }
            } else if (input[n2] == 239) {
              n2 += 2;
              cnt += write((uint8_t) input[n2] + 1);
            } else {
              cnt += write((uint8_t) input[n2]);
            }
          }

          h += ht + 3;
          prev_line_break = prev_test_point; // Make it the previous line break point
          prev_test_point = n;
          width_temp = w - width_temp;
        }

        if (lastLine) { // If it is the last line
          int16_t temp_width = width - width_temp;
          if (first_try) {
            temp_width = width - w;
          }
          writer.gfx -> setCursor(temp_width, h); //Set Cursor considering the width of the text

          for (uint8_t n2 = 0; n2 <= prev_line_break; n2++) {
            cnt += write(temp[n2]);
          }

          // Move Cursor
          ty = h + ht + 3;
        }
      }
    }
    return cnt;
  }
};

#endif /* */
