#include "timeFunctions.h"


// push the time (words) to leds array
void timeToStripe(uint8_t hours,uint8_t minutes)
{
  // show "ES IST"
  word2stripe(word_ES,sizeof(word_ES)/sizeof(int));
  word2stripe(word_IST,sizeof(word_IST)/sizeof(int));

  if(minutes >= 5 && minutes < 10) {
    word2stripe(word_FUENF1,sizeof(word_FUENF1)/sizeof(int));
    word2stripe(word_NACH,sizeof(word_NACH)/sizeof(int));
  } else if(minutes >= 10 && minutes < 15) {
    word2stripe(word_ZEHN1,sizeof(word_ZEHN1)/sizeof(int));
    word2stripe(word_NACH,sizeof(word_NACH)/sizeof(int));
  } else if(minutes >= 15 && minutes < 20) {
    word2stripe(word_VIERTEL,sizeof(word_VIERTEL)/sizeof(int));
    word2stripe(word_NACH,sizeof(word_NACH)/sizeof(int));
  } else if(minutes >= 20 && minutes < 25) {
    word2stripe(word_ZWANZIG,sizeof(word_ZWANZIG)/sizeof(int));
    word2stripe(word_NACH,sizeof(word_NACH)/sizeof(int));
  } else if(minutes >= 25 && minutes < 30) {
    word2stripe(word_FUENF1,sizeof(word_FUENF1)/sizeof(int));
    word2stripe(word_VOR,sizeof(word_VOR)/sizeof(int));
    word2stripe(word_HALB,sizeof(word_HALB)/sizeof(int));
  } else if(minutes >= 30 && minutes < 35) {
    word2stripe(word_HALB,sizeof(word_HALB)/sizeof(int));
  } else if(minutes >= 35 && minutes < 40) {
    word2stripe(word_FUENF1,sizeof(word_FUENF1)/sizeof(int));
    word2stripe(word_NACH,sizeof(word_NACH)/sizeof(int));
    word2stripe(word_HALB,sizeof(word_HALB)/sizeof(int));
  } else if(minutes >= 40 && minutes < 45) {
    word2stripe(word_ZWANZIG,sizeof(word_ZWANZIG)/sizeof(int));
    word2stripe(word_VOR,sizeof(word_VOR)/sizeof(int));
  } else if(minutes >= 45 && minutes < 50) {
    word2stripe(word_VIERTEL,sizeof(word_VIERTEL)/sizeof(int));
    word2stripe(word_VOR,sizeof(word_VOR)/sizeof(int));
  } else if(minutes >= 50 && minutes < 55) {
    word2stripe(word_ZEHN1,sizeof(word_ZEHN1)/sizeof(int));
    word2stripe(word_VOR,sizeof(word_VOR)/sizeof(int));
  } else if(minutes >= 55 && minutes < 60) {
    word2stripe(word_FUENF1,sizeof(word_FUENF1)/sizeof(int));
    word2stripe(word_VOR,sizeof(word_VOR)/sizeof(int));
  }
  
  int singleMinutes = minutes % 5;
  switch(singleMinutes) {
    case 1:
      word2stripe(min_ONE,sizeof(min_ONE)/sizeof(int),CRGB::Blue);
      break;
    case 2:
      word2stripe(min_ONE,sizeof(min_ONE)/sizeof(int),CRGB::Green);
      word2stripe(min_TWO,sizeof(min_TWO)/sizeof(int),CRGB::Blue);
      break;
    case 3:
      word2stripe(min_ONE,sizeof(min_ONE)/sizeof(int),CRGB::Yellow);
      word2stripe(min_TWO,sizeof(min_TWO)/sizeof(int),CRGB::Green);
      word2stripe(min_THREE,sizeof(min_THREE)/sizeof(int),CRGB::Blue);
      break;
    case 4:
      word2stripe(min_ONE,sizeof(min_ONE)/sizeof(int),CRGB::DarkOrange);
      word2stripe(min_TWO,sizeof(min_TWO)/sizeof(int),CRGB::Yellow);
      word2stripe(min_THREE,sizeof(min_THREE)/sizeof(int),CRGB::Green);
      word2stripe(min_FOUR,sizeof(min_FOUR)/sizeof(int),CRGB::Blue);
    break;
  }

  if(minutes >= 25) {
    hours++;
  }

  if(hours >= 12) {
    hours -= 12;
  }

  switch(hours) {
    case 0:
      word2stripe(word_ZWOELF,sizeof(word_ZWOELF)/sizeof(int));
      break;
    case 1:
      if(minutes > 4) {
        word2stripe(word_EINS,sizeof(word_EINS)/sizeof(int));
      } else {
        word2stripe(word_EIN,sizeof(word_EIN)/sizeof(int));
      }
      break;
    case 2:
      word2stripe(word_ZWEI,sizeof(word_ZWEI)/sizeof(int));
      break;
    case 3:
      word2stripe(word_DREI,sizeof(word_DREI)/sizeof(int));
      break;
    case 4:
      word2stripe(word_VIER,sizeof(word_VIER)/sizeof(int));
      break;
    case 5:
      word2stripe(word_FUENF2,sizeof(word_FUENF2)/sizeof(int));
      break;
    case 6:
      word2stripe(word_SECHS,sizeof(word_SECHS)/sizeof(int));
      break;
    case 7:
      word2stripe(word_SIEBEN,sizeof(word_SIEBEN)/sizeof(int));
      break;
    case 8:
      word2stripe(word_ACHT,sizeof(word_ACHT)/sizeof(int));
      break;
    case 9:
      word2stripe(word_NEUN,sizeof(word_NEUN)/sizeof(int));
      break;
    case 10:
      word2stripe(word_ZEHN2,sizeof(word_ZEHN2)/sizeof(int));
      break;
    case 11:
      word2stripe(word_ELF,sizeof(word_ELF)/sizeof(int));
      break;
  }
  
  // show "UHR" if full hour
  if(minutes < 5) { word2stripe(word_UHR,sizeof(word_UHR)/sizeof(int)); }
}