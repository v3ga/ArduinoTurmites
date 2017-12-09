/*
  ArduinoTermites

  —
  http://mathworld.wolfram.com/Turmite.html

  —
  Developped and tested on : 
    - Arduino 1.6.5 on MacOSX (10.12.5)
    - Arduino Uno Rev3
    - Adafruit NeoPixel NeoMatrix 8x8 - 64 RGB LED Pixel Matrix ( https://www.adafruit.com/product/1487 )
  
  —
  Uses : 
    - https://github.com/adafruit/Adafruit_NeoPixel
  
  —
  Julien @v3ga Gachadoat
  www.v3ga.net
  www.2roqs.com
*/

// --------------------------------------------------------
#include <Adafruit_NeoPixel.h>
#include "Turmite.h"

// --------------------------------------------------------
// Pixels
#define WIDTH          8
#define HEIGHT         8
#define PIN            6
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(WIDTH*HEIGHT, PIN, NEO_GRB + NEO_KHZ800);

// --------------------------------------------------------
// Turmite
Turmite* turmite;

// --------------------------------------------------------
void setup()
{
  pixels.begin();
  turmite = new Turmite(&pixels, 8, 8);
  turmite->setRule(0);
  turmite->setColorBackground(0, 0, 0);
  turmite->setColor(0, 50, 100);
  turmite->setPeriodNext(25);
}

// --------------------------------------------------------
void loop()
{
  turmite->run();
}
