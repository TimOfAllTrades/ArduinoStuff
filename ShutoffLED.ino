//Let's see what we can do with these RGB LEDs
//Note that these LEDs are connected individually so you can't use them as if the 2 leds are an led "strip"

//include AdaFruit's RGB Library
#include <Adafruit_NeoPixel.h>

//These are the arduino pins that contain those 2 RGB leds..
//We are only going to use the second one in this example
#define RGB1 12
#define RGB2 13

//Now we have to set them up!
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(1, RGB2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(1, RGB1, NEO_GRB + NEO_KHZ800);

void setup(){
  //Let's use the serial monitor.
  Serial.begin(9600);
  //we are going to loop through the pins and make them all outputs
  for (int i = 2; i < 14; i++) {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }

  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'

  Serial.println("RGBDuino Booted");
  colorWipe(strip2.Color(0, 0, 0), 50);
  colorWipe(strip1.Color(0, 0, 0), 50);
}

void loop(){
  
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
      strip2.setPixelColor(i, c);
      strip2.show();
      delay(wait);
  }
}
