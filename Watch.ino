#include <Wire.h>
#include <ds3231.h>


#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'Big_1', 28x44px
const unsigned char numBig_1[] PROGMEM = {
  0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x40
};
// 'Big_3', 28x44px
const unsigned char numBig_3[] PROGMEM = {
  0x07, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x03, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x60,
  0x00, 0x00, 0x00, 0x40, 0x3f, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 0x00, 0xff, 0xff, 0xfe, 0x00
};
// 'Big_4', 28x44px
const unsigned char numBig_4[] PROGMEM = {
  0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x70, 0x20, 0x00, 0x00, 0x70,
  0x60, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x40
};
// 'Big_2', 28x44px
const unsigned char numBig_2[] PROGMEM = {
  0x07, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x40,
  0x07, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x20, 0x00, 0x00, 0x00,
  0x60, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0x80
};
// 'Big_8', 28x44px
const unsigned char numBig_8[] PROGMEM = {
  0x07, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf0, 0x20, 0x00, 0x00, 0x70,
  0x60, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xff, 0xff, 0xff, 0x70, 0xff, 0xff, 0xfe, 0x70, 0xff, 0xff, 0xfc, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x60,
  0xe0, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xfe, 0x00
};
// 'Big_7', 28x44px
const unsigned char numBig_7[] PROGMEM = {
  0x3f, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x40
};
// 'Big_0', 28x44px
const unsigned char numBig_0[] PROGMEM = {
  0x07, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf0, 0x20, 0x00, 0x00, 0x70,
  0x60, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x60,
  0xe0, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xfe, 0x00
};
// 'Big_6', 28x44px
const unsigned char numBig_6[] PROGMEM = {
  0x07, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf0, 0x20, 0x00, 0x00, 0x00,
  0x60, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe3, 0xff, 0xff, 0xf0, 0xe7, 0xff, 0xff, 0xf0, 0xef, 0xff, 0xff, 0xf0, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x60,
  0xe0, 0x00, 0x00, 0x40, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xfe, 0x00
};
// 'Big_5', 28x44px
const unsigned char numBig_5[] PROGMEM = {
  0x07, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0x80, 0x20, 0x00, 0x00, 0x00,
  0x60, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x60,
  0x00, 0x00, 0x00, 0x40, 0x1f, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xfe, 0x00
};
// 'Big_9', 28x44px
const unsigned char numBig_9[] PROGMEM = {
  0x07, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf0, 0x20, 0x00, 0x00, 0x70,
  0x60, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70, 0xe0, 0x00, 0x00, 0x70,
  0xff, 0xff, 0xff, 0x70, 0xff, 0xff, 0xfe, 0x70, 0xff, 0xff, 0xfc, 0x70, 0x00, 0x00, 0x00, 0x70,
  0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x60,
  0x00, 0x00, 0x00, 0x40, 0x1f, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xfe, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1920)
const unsigned char* numBig[10] = {
  numBig_0,
  numBig_1,
  numBig_2,
  numBig_3,
  numBig_4,
  numBig_5,
  numBig_6,
  numBig_7,
  numBig_8,
  numBig_9
};



// 'Little_0', 3x16px
const unsigned char numLittle_0[] PROGMEM = {
  0xe0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xe0
};
// 'Little_4', 3x16px
const unsigned char numLittle_4[] PROGMEM = {
  0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xe0, 0x20, 0x20, 0x20, 0x20
};
// 'Little_5', 3x16px
const unsigned char numLittle_5[] PROGMEM = {
  0xe0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xe0, 0x20, 0x20, 0x20, 0xe0
};
// 'Little_6', 3x16px
const unsigned char numLittle_6[] PROGMEM = {
  0xe0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xe0, 0xa0, 0xa0, 0xa0, 0xe0
};
// 'Little_8', 3x16px
const unsigned char numLittle_8[] PROGMEM = {
  0xe0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xe0, 0xa0, 0xa0, 0xa0, 0xe0
};
// 'Little_1', 3x16px
const unsigned char numLittle_1[] PROGMEM = {
  0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40
};
// 'Little_7', 3x16px
const unsigned char numLittle_7[] PROGMEM = {
  0xe0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
};
// 'Little_9', 3x16px
const unsigned char numLittle_9[] PROGMEM = {
  0xe0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xe0, 0x20, 0x20, 0x20, 0xe0
};
// 'Little_2', 3x16px
const unsigned char numLittle_2[] PROGMEM = {
  0xe0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xe0, 0x80, 0x80, 0x80, 0xe0
};
// 'Little_3', 3x16px
const unsigned char numLittle_3[] PROGMEM = {
  0xe0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xe0, 0x20, 0x20, 0x20, 0xe0
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 320)
const unsigned char* numLittle[10] = {
  numLittle_0,
  numLittle_1,
  numLittle_2,
  numLittle_3,
  numLittle_4,
  numLittle_5,
  numLittle_6,
  numLittle_7,
  numLittle_8,
  numLittle_9
};


long _lastChecked = -10000;
long _buttonTimer;
const int holdLimit = 1500;

struct ts timeToShow;
int editing = -1;
int lastPressedBtn;

int btnU = 10;
int btnC = 11;
int btnD = 12;

void setup() {
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  display.clearDisplay();
  display.display();
  display.setTextColor(SSD1306_WHITE);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(btnU, INPUT);
  pinMode(btnC, INPUT);
  pinMode(btnD, INPUT);


  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
}

void loop() {
  if (editing < 0) {
    if (millis() - _lastChecked > 1000) {
      _lastChecked = millis();
      DS3231_get(&timeToShow);
      ShowTime();
    }
  }

  display.fillRect(115, 0, 13, 8, SSD1306_BLACK);
  if (!digitalRead(btnU) && !digitalRead(btnC) && !digitalRead(btnD)) {
    if (_buttonTimer > 150) {
      buttonPressed();
    }

    _buttonTimer = millis();
    lastPressedBtn = -1;
  } else {
    if (digitalRead(btnU)) {
      lastPressedBtn = btnU;
    } else if (digitalRead(btnC)) {
      lastPressedBtn = btnC;
    } else if (digitalRead(btnD)) {
      lastPressedBtn = btnD;
    }
  }

  if (editing >= 0 != (lastPressedBtn == btnC && millis() - _buttonTimer > holdLimit)) {
    display.fillCircle(60, 4, 3, SSD1306_WHITE);
  } else {
    display.fillCircle(60, 4, 3, SSD1306_BLACK);
  }

  display.display();
}

void buttonPressed() {
  if (lastPressedBtn == btnC) {
    if (millis() - _buttonTimer > holdLimit) {
      if (editing < 0) {
        editing = 0;
      } else {
        editing = -1;
        DS3231_set(timeToShow);
      }
    } else {
      editing++;
      editing %= 4;
    }
  } else if (lastPressedBtn == btnU) {
    if (editing == 0) {
      timeToShow.min++;
    } else if (editing == 1) {
      timeToShow.hour++;
    } else if (editing == 2) {
      timeToShow.mday++;
    } else if (editing == 3) {
      timeToShow.mon++;
    }
  } else if (lastPressedBtn == btnD) {
    if (editing == 0) {
      if (timeToShow.min == 0) {
        timeToShow.min = 60;
      }
      timeToShow.min--;
    } else if (editing == 1) {
      if (timeToShow.hour == 0) {
        timeToShow.hour = 24;
      }
      timeToShow.hour--;
    } else if (editing == 2) {
      if (timeToShow.mday == 0) {
        timeToShow.mday = 32;
      }
      timeToShow.mday--;
    } else if (editing == 3) {
      if (timeToShow.mon == 0) {
        timeToShow.mon = 13;
      }
      timeToShow.mon--;
    }
  }
  ShowTime();
}

void ShowTime() {
  timeToShow.min %= 60;
  timeToShow.hour %= 24;
  timeToShow.mday %= 32;
  timeToShow.mon %= 13;

  display.setCursor(68, 0);
  display.fillRect(68, 0, 32, 8, SSD1306_BLACK);
  if (editing == 0) {
    display.print("min");
  } else if (editing == 1) {
    display.print("hour");
  } else if (editing == 2) {
    display.print("day");
  } else if (editing == 3) {
    display.print("mon");
  }

  display.fillRect(0, 20, 128, 44, SSD1306_BLACK);

  display.drawBitmap(0, 20, numBig[timeToShow.hour / 10], 28, 44, SSD1306_WHITE);
  display.drawBitmap(32, 20, numBig[timeToShow.hour % 10], 28, 44, SSD1306_WHITE);
  display.drawBitmap(68, 20, numBig[timeToShow.min / 10], 28, 44, SSD1306_WHITE);
  display.drawBitmap(100, 20, numBig[timeToShow.min % 10], 28, 44, SSD1306_WHITE);

  display.drawBitmap(63, 24, numLittle[timeToShow.sec / 10], 3, 16, SSD1306_WHITE);
  display.drawBitmap(63, 44, numLittle[timeToShow.sec % 10], 3, 16, SSD1306_WHITE);

  display.drawBitmap(10, 30, numLittle[timeToShow.mon / 10], 3, 16, SSD1306_WHITE);
  display.drawBitmap(15, 30, numLittle[timeToShow.mon % 10], 3, 16, SSD1306_WHITE);

  display.drawBitmap(42, 30, numLittle[timeToShow.mday / 10], 3, 16, SSD1306_WHITE);
  display.drawBitmap(47, 30, numLittle[timeToShow.mday % 10], 3, 16, SSD1306_WHITE);

  display.fillRect(100, 8, 28, 8, SSD1306_BLACK);
  display.setCursor(100, 8);
  display.print((int)DS3231_get_treg());
  display.print(" C");
}
