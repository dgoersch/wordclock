#define FASTLED_ESP8266_RAW_PIN_ORDER

#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <TimeLib.h>
#include <WiFiManager.h>
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

//---------------------------------------------------------------------------------------
// configModeCallback
//
//  callback that gets called when connecting to previous WiFi fails
//  and WIFIManager enters Access Point mode
//
// ->
// <- --
//---------------------------------------------------------------------------------------
void configModeCallback(WiFiManager *myWiFiManager)
{
  // show "wifimanager word (words.h)"
  word2stripe(word_WIFIMANAGER,sizeof(word_WIFIMANAGER)/sizeof(int), CRGB::Red);
  FastLED.show();
	Serial.println("Entered WIFIManager config mode");
	Serial.println(WiFi.softAPIP());
	Serial.println(myWiFiManager->getConfigPortalSSID());
}



void setup() {
	// serial port
	Serial.begin(115200);
	Serial.println();
	Serial.println();
	Serial.println("ESP8266 WordClock setup() begin");

  ledSetup();

  blankscreen(true);
//  EEPROM_read(0, conf);
//  current_mode = conf.default_mode;
  
	// WiFi Setup 
	Serial.println("Initializing WiFi");
  wifi_station_set_hostname("WordClock");
	WiFiManager wifiManager;
	wifiManager.setAPCallback(configModeCallback);
	if (!wifiManager.autoConnect("WordClock"))
	{
		Serial.println("failed to connect, timeout");
		delay(1000);
		ESP.reset();
	}
  Serial.println("Connected successfully to WiFi");


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