// scroll.ino
// Simple example of Scrolling text down and up
// on the RA8876. The method used is kind of slow
// and needs to be optimized.
#include "Arduino.h"
#include "Ra8876_Lite.h"
#include "RA8876_t3.h"

//#include "vt100.h"
#include <math.h>

#define RA8876_CS 10
#define RA8876_RESET 8
#define BACKLITE 7 //External backlight control connected to this Arduino pin
RA8876_t3 tft = RA8876_t3(RA8876_CS, RA8876_RESET); //Using standard SPI pins


// Array of RA8876 Basic Colors
PROGMEM uint16_t myColors[] = {
	0x0000,
	0xffff,
	0xf800,
	0xfc10,
	0x8000,
	0x07e0,
	0x87f0,
	0x0400,
	0x001f,
	0x051f,
	0x841f,
	0x0010,
	0xffe0,
	0xfff0,
	0x8400,
	0x07ff,
	0x87ff,
	0x0410,
	0xf81f,
	0xfc1f,
	0x8010,
	0xA145
};

int i = 0, j = 0;
int color = 1;
void setup() {
  //I'm guessing most copies of this display are using external PWM
  //backlight control instead of the internal RA8876 PWM.
  //Connect a Teensy pin to pin 14 on the display.
  //Can use analogWrite() but I suggest you increase the PWM frequency first so it doesn't sing.
  pinMode(BACKLITE, OUTPUT);
  digitalWrite(BACKLITE, HIGH);
  
  tft.begin();
	//initVT100();
	tft.setTextAt(0,0);
	tft.fillStatusLine(myColors[11]);
	tft.setFontSize(1,false);
	tft.setMargins(0, 0, tft.width(), tft.height()); //so scroll doesn't erase the status bar
}

void loop() {

	tft.fillStatusLine(myColors[0]);
	tft.printStatusLine(0,myColors[13],myColors[0],"scroll_down(), scroll_up()");
	//tft.setFontSource(0);
	tft.setFontSize(1,true);
	tft.setTextAt(0,0);
	for(i = 32; i < 256; i++) {
		if(color == 22) color = 1;
		tft.setTextColorFG(myColors[color++] , myColors[0]);
		tft.print(i);
	}
	tft.setTextColorFG(myColors[1] , myColors[0]);
	//while(j++ < 10) {
		for(i = 0; i < 42; i++) {
			tft.scrollDown();
		}
   delay(2000);
   
  for(i = 32; i < 256; i++) {
    if(color == 22) color = 1;
    tft.setTextColorFG(myColors[color++] , myColors[0]);
    tft.print(i);
  }
		for(i = 0; i < 42; i++) {
			tft.scrollUp();
		}
	//}
	j = 0;
	delay(2000);
}
