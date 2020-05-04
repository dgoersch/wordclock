#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <Arduino.h>

#ifndef _WIFIFUNCTIONS_H_
#define _WIFIFUNCTIONS_H_

#include "ledFunctions.h"
#include "words.h"

void setupWifi();
void wifimanagerConfigModeCallback(WiFiManager *myWiFiManager);

#endif