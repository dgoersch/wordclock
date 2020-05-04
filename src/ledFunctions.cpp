#include "ledFunctions.h"

CRGB leds[NUM_LEDS];

// push word to leds array
void word2stripe(const int word[],int len, CRGB color) {
  for (int letter = 0; letter < len; letter++) {
      leds[word[letter]] = color;
  }
}

// blank screen (to specific color if given, and put it on the matrix if set)
void blankscreen(CRGB color, bool commit) {
  for (int led = 0; led<NUM_LEDS; led++) {
    leds[led] = color;
    if(commit) { FastLED.show(); }
  }
}

void setupLeds() {
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}