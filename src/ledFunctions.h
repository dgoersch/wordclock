#ifndef _LEDFUNCTIONS_H_
#define _LEDFUNCTIONS_H_

#include "config.h"

// push word to leds array
void word2stripe(const int[],int, CRGB color = CRGB::DeepPink);
void word2stripe(const int word[],int len, CRGB color);

// switching all led off
void blankscreen(CRGB color = CRGB::Black, bool commit = false);
void blankscreen(CRGB color, bool commit);

void setupLeds();

#endif