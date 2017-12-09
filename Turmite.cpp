#include "Turmite.h"

int Turmite::turns[][4] =
{
  // 0 (//)
  { -1, -1, -1, -1},
  // 1 (No turn)
  { 0, 1, 2, 3},
  // 2  (Right)
  { 1, 2, 3, 0},
  // 3  (//)
  { -1, -1, -1, -1},
  // 4  (U-turn)
  { 2, 3, 0, 1},
  // 5  (//)
  { -1, -1, -1, -1},
  // 6  (//)
  { -1, -1, -1, -1},
  // 7  (//)
  { -1, -1, -1, -1},
  // 8  (Left)
  { 3, 0, 1, 2}
};

// {0, 0, 0} for padding
// Can't find the sauce of this crazy array.
byte Turmite::rules[][3][2][3]  = 
{
{{{1, 2, 0}, {0, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}}},  // 1: Langton's ant
{{{1, 2, 0}, {0, 1, 0}}, {{0, 0, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 0, 0}}},  // 2: binary counter
{{{0, 8, 1}, {1, 2, 1}}, {{1, 1, 0}, {1, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 3: (filled triangle)
{{{0, 1, 1}, {0, 8, 1}}, {{1, 2, 0}, {0, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 4: spiral in a box
{{{0, 2, 1}, {0, 8, 0}}, {{1, 8, 1}, {0, 2, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 5: stripe-filled spiral
{{{0, 2, 1}, {0, 8, 0}}, {{1, 8, 1}, {1, 1, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 6: stepped pyramid
{{{0, 2, 1}, {0, 1, 1}}, {{1, 2, 1}, {1, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 7: contoured island
{{{0, 2, 1}, {0, 2, 1}}, {{1, 1, 0}, {0, 2, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 8: woven placemat
{{{0, 2, 1}, {1, 2, 1}}, {{1, 8, 1}, {1, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 9: snowflake-ish
{{{1, 8, 0}, {0, 1, 1}}, {{0, 8, 0}, {0, 8, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 10: slow city builder
{{{1, 8, 0}, {1, 2, 1}}, {{0, 2, 0}, {0, 8, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 11: framed computer art
{{{1, 8, 0}, {1, 2, 1}}, {{0, 2, 1}, {1, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 12: balloon bursting (makes a spreading highway) 
{{{1, 8, 1}, {0, 8, 0}}, {{1, 1, 0}, {0, 1, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 13: makes a horizontal highway
{{{1, 8, 1}, {0, 8, 0}}, {{1, 2, 1}, {1, 2, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 14: makes a 45 degree highway
{{{1, 8, 1}, {0, 8, 1}}, {{1, 2, 1}, {0, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 15: makes a 45 degree highway
{{{1, 8, 1}, {0, 1, 0}}, {{1, 1, 0}, {1, 2, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 16: spiral in a filled box
{{{1, 8, 1}, {0, 2, 0}}, {{0, 8, 0}, {0, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 17: glaciers
{{{1, 8, 1}, {1, 8, 1}}, {{1, 2, 1}, {0, 1, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 18: golden rectangle!
{{{1, 8, 1}, {1, 2, 0}}, {{0, 8, 0}, {0, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 19: fizzy spill
{{{1, 8, 1}, {1, 2, 1}}, {{1, 1, 0}, {0, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 20: nested cabinets
{{{1, 1, 1}, {0, 8, 1}}, {{1, 2, 0}, {1, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 21: (cross)
{{{1, 1, 1}, {0, 1, 0}}, {{0, 2, 0}, {1, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 22: saw-tipped growth
{{{1, 1, 1}, {0, 1, 1}}, {{1, 2, 1}, {0, 1, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 23: curves in blocks growth
{{{1, 1, 1}, {0, 2, 0}}, {{0, 8, 0}, {0, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 24: textured growth
{{{1, 1, 1}, {0, 2, 1}}, {{1, 8, 0}, {1, 2, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 25: (diamond growth)
{{{1, 1, 1}, {1, 8, 0}}, {{1, 2, 1}, {0, 1, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 26: coiled rope
{{{1, 2, 0}, {0, 8, 1}}, {{1, 8, 0}, {0, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 27: (growth)
{{{1, 2, 0}, {0, 8, 1}}, {{1, 8, 0}, {0, 2, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 28: (square spiral)
{{{1, 2, 0}, {1, 2, 1}}, {{0, 1, 0}, {0, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 29: loopy growth with holes
{{{1, 2, 1}, {0, 8, 1}}, {{1, 1, 0}, {0, 1, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 30: Lanton's Ant drawn with squares};
{{{1, 2, 1}, {0, 2, 0}}, {{0, 8, 1}, {1, 8, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 31: growth with curves and blocks
{{{1, 2, 1}, {0, 2, 0}}, {{0, 1, 0}, {1, 2, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 32: distracted spiral builder
{{{1, 2, 1}, {0, 2, 1}}, {{1, 1, 0}, {1, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 33: cauliflower stalk (45 deg highway)
{{{1, 2, 1}, {1, 8, 1}}, {{1, 2, 1}, {0, 2, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 34: worm trails (eventually turns cyclic!)
{{{1, 2, 1}, {1, 1, 0}}, {{1, 1, 0}, {0, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 35: eventually makes a two-way highway!
{{{1, 2, 1}, {1, 2, 0}}, {{0, 1, 0}, {0, 1, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 36: almost symmetric mould bloom
{{{1, 2, 1}, {1, 2, 0}}, {{0, 2, 0}, {1, 1, 1}}, {{0, 0, 0}, {0, 0, 0}}}, // 37: makes a 1 in 2 gradient highway
{{{1, 2, 1}, {1, 2, 1}}, {{1, 8, 1}, {0, 2, 0}}, {{0, 0, 0}, {0, 0, 0}}}, // 38: immediately makes a 1 in 3 highway
{{{0, 2, 1}, {1, 2, 1}}, {{0, 8, 2}, {0, 8, 0}}, {{1, 2, 2}, {1, 8, 0}}}, // 39: squares and diagonals growth
{{{1, 8, 1}, {0, 1, 0}}, {{0, 2, 2}, {1, 8, 0}}, {{1, 2, 1}, {1, 1, 0}}}, // 40: streak at approx. an 8.1 in 1 gradient
{{{1, 8, 1}, {0, 1, 2}}, {{0, 2, 2}, {1, 1, 1}}, {{1, 2, 1}, {1, 1, 0}}}, // 41: streak at approx. a 1.14 in 1 gradient
{{{1, 8, 1}, {1, 8, 1}}, {{1, 1, 0}, {0, 1, 2}}, {{0, 8, 1}, {1, 1, 1}}}, // 42: maze-like growth
{{{1, 8, 2}, {0, 2, 0}}, {{1, 8, 0}, {0, 2, 0}}, {{0, 8, 0}, {0, 8, 1}}}, // 43: growth by cornices 
{{{1, 2, 0}, {0, 2, 2}}, {{0, 8, 0}, {0, 2, 0}}, {{0, 1, 1}, {1, 8, 0}}}, // 44: makes a 1 in 7 highway
{{{1, 2, 1}, {0, 8, 0}}, {{1, 2, 2}, {0, 1, 0}}, {{1, 8, 0}, {0, 8, 0}}} // 45: makes a 4 in 1 highway
};

int Turmite::nbRules = 45;

Turmite::Turmite(Adafruit_NeoPixel* pixels, int width, int height)
{
  this->pixels = pixels;
  this->width = width;
  this->height = height;
  this->nbPixels = this->width * this->height;
  this->setRule(0);
  this->setColorBackground(0,0,0);
  this->setColor(30,30,30);
  this->setPeriodNext(20);

  this->before = millis() - this->periodNext;
}

void Turmite::clearBackground()
{
  for (int i = 0; i < this->nbPixels; i++)
    pixels->setPixelColor(i, pixels->Color(this->rBg, this->gBg, this->bBg));
}

void Turmite::reset()
{
  this->clearBackground();

  this->state = 0;
  this->x = this->width/2;
  this->y = this->height/2;
}

void Turmite::setPeriodNext(unsigned long periodNext)
{
  this->periodNext = periodNext;  
}

void Turmite::setColorBackground(byte r, byte g, byte b)
{
  this->rBg = r;
  this->gBg = g;
  this->bBg = b;

  this->reset();
}


void Turmite::setColor(byte r, byte g, byte b)
{
  this->r = r;
  this->g = g;
  this->b = b;
}

void Turmite::run()
{
  this->now = millis();
  unsigned long dt = this->now - this->before;
  if (dt >= this->periodNext)
  {
    this->before = this->now;
  
    int colorIndex = this->convertColorToIndex( pixels->getPixelColor(this->x + this->width*this->y) );
    byte* next = Turmite::rules[this->ruleIndex][this->state][colorIndex];
    
    setPixelColorWithIndex((int)*(next+0));
    setTurn((int)*(next+1));
    setState((int)*(next+2));
    this->iteration++;

    this->move();
    pixels->show();
  }
}

void Turmite::move()
{
  switch (this->direction)
  {
    case 0:
      y = y - 1;
      if (y<0) this->setRuleNext();
      break;
    case 1:
      x = x+1;
      if (x>=this->width) this->setRuleNext();
      break;
    case 2:
      y = y+1;
      if (y>=this->height) this->setRuleNext();
      break;
    case 3:
      x = x - 1;
      if (x < 0) this->setRuleNext();
      break;
  }
}


void Turmite::setRule(int ruleIndex)
{
  this->ruleIndex = ruleIndex;
  this->reset();
}

void Turmite::setRuleNext()
{
  setRule( (this->ruleIndex+1) % nbRules );
}

void Turmite::setPixelColorWithIndex(int colorIndex)
{
    pixels->setPixelColor(this->x+this->width*this->y, colorIndex == 0 ? pixels->Color(this->rBg, this->gBg, this->bBg) : pixels->Color(this->r, this->g, this->b));
}

void Turmite::setTurn(int which)
{
    this->direction = turns[which][this->direction];
}

void Turmite::setState(int state)
{
  this->state = state;
}


int Turmite::convertColorToIndex(uint32_t color)
{
  uint8_t r = (uint8_t)(color >> 16);
  uint8_t g = (uint8_t)(color >> 8);
  uint8_t b = (uint8_t)(color);

  // Black -> 0
  if (r == this->rBg && g == this->gBg && b == this->bBg)
    return 0;
  // Other color -> 1
  return 1;
}





