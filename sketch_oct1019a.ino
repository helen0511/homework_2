//110419044楊琬婷
//110413013黃筱涵
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_MOSI 11
#define OLED_CLK 12
#define OLED_DC 9
#define OLED_CS 8
#define OLED_RESET 10
#define Light_PIN A0
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

static const unsigned char PROGMEM Logo1[]={
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x7f,0xf0,0x00,0x3f,0xfc,0x00,0x00,
	0x07,0xff,0xff,0x03,0xff,0xff,0x80,0x00,
	0x1f,0xe0,0x3f,0xcf,0xf0,0x1f,0xe0,0x00,
	0x3f,0x00,0x07,0xff,0x80,0x03,0xf0,0x00,
	0x7c,0x00,0x00,0xfe,0x00,0x00,0xf8,0x00,
	0x78,0x00,0x00,0x78,0x00,0x00,0x7c,0x00,
	0xf8,0x00,0x00,0x00,0x00,0x00,0x7c,0x00,
	0xf8,0x00,0x00,0x00,0x3f,0x80,0x7c,0x00,
	0xf8,0x00,0x00,0x01,0xff,0xf0,0x7c,0x00,
	0x7c,0x00,0x00,0x07,0xff,0xfc,0x7c,0x00,
	0x7e,0x00,0x00,0x0f,0xff,0xfe,0xff,0xc0,
	0x3f,0x00,0x00,0x0f,0xff,0xff,0xff,0xf8,
	0x1f,0x80,0x00,0x1f,0xff,0xff,0xff,0xfe,
	0x07,0xe0,0x00,0x0f,0xff,0xff,0xff,0xfe,
	0x01,0xf8,0x00,0x0f,0xff,0xff,0xff,0xff,
	0x00,0x7f,0x00,0x07,0xff,0xff,0xff,0xff,
	0x00,0x1f,0xc0,0x03,0xff,0xff,0xff,0xfe,
	0x00,0x07,0xf8,0x01,0xff,0xff,0xff,0xfc,
	0x00,0x00,0xfe,0x01,0xff,0xff,0xff,0xf8,
	0x00,0x00,0x3f,0x87,0xff,0xff,0xff,0xe0,
	0x00,0x00,0x0f,0xff,0xff,0xff,0xff,0x00,
	0x00,0x00,0x01,0xff,0x1f,0xff,0xf0,0x00,
	0x00,0x00,0x00,0xfc,0x07,0xfc,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0xc0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

void splash() {
  int light = analogRead(Light_PIN);
  display.clearDisplay();
  display.drawBitmap(23,0,Logo1,64,32,WHITE);
  delay(10000);
  display.display();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(50,10);
  display.print("Heart");
  delay(10000);
  display.display();
}


void setup() {
  Serial.begin(9600);
  pinMode(Light_PIN, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  
  display.setTextWrap(false);
  // put your setup code here, to run once:

}

void loop() {
  splash();
  // put your main code here, to run repeatedly:

}
