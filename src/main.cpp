#define FASTLED_ESP8266_RAW_PIN_ORDER

#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <TimeLib.h>
// #include <EEPROM.h>
#include "eeprom.h"
#include "timeFunctions.h"
#include "ntpFunctions.h"
#include "config.h"

#define WLAN_SSID ""
#define WLAN_KEY ""

/*
int current_mode;
struct config_t
{
    char wlan_essid[32];
    char wlan_key[64];
    char update_ip[15];
    int default_mode;
} conf;
*/

void setup() {
  ledSetup();
  blankscreen(true);
//  EEPROM_read(0, conf);
//  current_mode = conf.default_mode;

  // show "KEIN FUNK"
  word2stripe(word_KEIN,sizeof(word_KEIN)/sizeof(int), CRGB::Red);
  word2stripe(word_FUNK,sizeof(word_FUNK)/sizeof(int), CRGB::Red);
  FastLED.show();
  
  // connect to wifi
  WiFi.hostname("WordClock");
  WiFi.begin(WLAN_SSID,WLAN_KEY);
  // wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  doNTPsync();

  blankscreen();
  FastLED.show();
}

void loop() {
  blankscreen();                    // all pixels to black
  timeToStripe(hour(),minute());    // calculate time and fill leds array
  FastLED.show();                   // show it on the matix
  delay(500);                       // wait half a second
}