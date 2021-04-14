#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        32 //ESP32 board

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32 // Neopixel Featherwing 8x4

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 100 // Time (in milliseconds) to pause between pixels

void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'


  pixels.fill(pixels.Color(10,10,0),0,32);
  pixels.show();
  delay(300);
  pixels.fill(pixels.Color(10,0,10),0,32);
  pixels.show();
  delay(300);
  pixels.fill(pixels.Color(10,10,0),0,32);
  pixels.show();
  delay(300);
  pixels.fill(pixels.Color(10,0,10),0,32);
  pixels.show();
  delay(300);
  pixels.clear();
  pixels.show();
  delay(300);


  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS/4; i++) { // For each pixel...
   //remove the lit leds to create a stripe effect
    if (i>0){
    pixels.setPixelColor(i-1, pixels.Color(0, 2, 0));
    pixels.setPixelColor(i+7, pixels.Color(0, 2, 0));
    pixels.setPixelColor(i+15, pixels.Color(0, 2, 0));
    pixels.setPixelColor(i+23, pixels.Color(0, 2, 0));
      // Send the updated pixel colors to the hardware.
    }

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Light the leds in a vertical strip from the left
    pixels.setPixelColor(i, pixels.Color(0, 10, 0));
    pixels.setPixelColor(i+8, pixels.Color(0, 10, 0));
    pixels.setPixelColor(i+16, pixels.Color(0, 10,0 ));
    pixels.setPixelColor(i+24, pixels.Color(0, 10, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop

  }

delay(1000);

pixels.clear();
pixels.show();

delay(1000);


  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=31; i>=24; i--) { // For each pixel...
   //remove the lit leds to create a stripe effect
    if (i<31){
    pixels.setPixelColor(i+1, pixels.Color(2, 0, 0));
    pixels.setPixelColor(i-7, pixels.Color(2, 0, 0));
    pixels.setPixelColor(i-15, pixels.Color(2, 0, 0));
    pixels.setPixelColor(i-23, pixels.Color(2, 0, 0));
      // Send the updated pixel colors to the hardware.
    }

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Light the leds in a vertical strip from the left
    pixels.setPixelColor(i, pixels.Color(10, 0, 0));
    pixels.setPixelColor(i-8, pixels.Color(10, 0, 0));
    pixels.setPixelColor(i-16, pixels.Color(10, 0,0 ));
    pixels.setPixelColor(i-24, pixels.Color(10, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop

  }
  delay(1000);

pixels.clear();
pixels.show();

delay(1000);
}