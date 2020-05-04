#include "wifiFunctions.h"

void setupWifi() {
    // WiFi Setup 
	Serial.println("Wifi: Initializing ...");
    wifi_station_set_hostname("WordClock");
	WiFiManager wifiManager;
	wifiManager.setAPCallback(wifimanagerConfigModeCallback);
	if (!wifiManager.autoConnect("WordClock"))
	{
		Serial.println("Wifi: Failed to connect, timeout");
		delay(1000);
		ESP.reset();
	}
    Serial.println("Wifi: Connected successfully.");
}

//---------------------------------------------------------------------------------------
// wifimanagerConfigModeCallback
//
//  callback that gets called when connecting to previous WiFi fails
//  and WIFIManager enters Access Point mode
//
// ->
// <- --
//---------------------------------------------------------------------------------------
void wifimanagerConfigModeCallback(WiFiManager *myWiFiManager)
{
    // show "wifimanager word (words.h)"
    word2stripe(word_WIFIMANAGER,sizeof(word_WIFIMANAGER)/sizeof(int), CRGB::Red);
    FastLED.show();
	Serial.println("Entered WIFIManager config mode");
	Serial.println(WiFi.softAPIP());
	Serial.println(myWiFiManager->getConfigPortalSSID());
}