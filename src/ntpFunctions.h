#include <TimeLib.h>
#include <ESP8266WiFi.h>

#ifndef _NTPFUNCTIONS_H_
#define _NTPFUNCTIONS_H_

#include "config.h"

void doNTPsync();
time_t getNtpTime();
void sendNTPpacket(IPAddress &address);

#endif