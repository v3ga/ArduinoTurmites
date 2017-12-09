#ifndef _Turmite_h_
#define _Turmite_h_
#include <Adafruit_NeoPixel.h>

class Turmite
{
    private: 
      int offset;
      int x, y;
      int state = 0;
      int direction = 0;
      int ruleIndex = 0;
      int iteration = 0;
      Adafruit_NeoPixel* pixels = 0;
      int width = 0;
      int height = 0;
      int nbPixels = 0;
      byte rBg,gBg,bBg;
      byte r,g,b;

      // timing
      unsigned long periodNext = 20;
      unsigned long now = 0;
      unsigned long before = 0;

      // Constructor
    public:
      Turmite   (Adafruit_NeoPixel* pixels, int width, int height);

      // run
      void      reset();
      void      setPeriodNext(unsigned long periodNext);
      void      setColorBackground(byte r, byte g, byte b);
      void      setColor(byte r, byte g, byte b);
      void      setRule(int ruleIndex);
      void      setRuleNext();
      void      run();

    private: 
      void      clearBackground();
      void      move();
      void      setTurn(int which);
      void      setState(int state);
      void      setPixelColorWithIndex(int colorIndex);
      int       convertColorToIndex(uint32_t color);

      static int turns[][4];
      static byte rules[][3][2][3];
      static int nbRules;
};

#endif

