#define FASTLED_ESP8266_RAW_PIN_ORDER

#include <FastLED.h>
#include <TimeLib.h>
// #include <EEPROM.h>
#include "eeprom.h"
#include "timeFunctions.h"
#include "ntpFunctions.h"
#include "wifiFunctions.h"

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
	// serial port
	Serial.begin(115200);
	Serial.println();
	Serial.println();
	Serial.println("ESP8266 WordClock setup() begin");

  setupWifi();
  setupLeds();

  blankscreen(true);
//  EEPROM_read(0, conf);
//  current_mode = conf.default_mode;

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