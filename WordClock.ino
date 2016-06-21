#define FASTLED_ESP8266_RAW_PIN_ORDER

#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
// #include <EEPROM.h>
#include "wordclock_words.h"
#include "wordclock_eeprom.h"

#define NUM_LEDS 114
#define DATA_PIN 3
#define WLAN_SSID ""
#define WLAN_KEY ""

static const char ntpServerName[] = "de.pool.ntp.org";
const int timeZone = 2;
unsigned int localPort = 8888;
time_t getNtpTime();
const int NTP_PACKET_SIZE = 48;
byte packetBuffer[NTP_PACKET_SIZE];



WiFiUDP Udp;
CRGB leds[NUM_LEDS];

void sendNTPpacket(IPAddress &address);
void word2stripe(const int[],int, CRGB color = CRGB::DeepPink);
void blankscreen(CRGB color = CRGB::Black, bool commit = false);

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
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
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

  // get time via NTP
  Udp.begin(localPort);
  setSyncProvider(getNtpTime);
  setSyncInterval(300);

  blankscreen();
  FastLED.show();
}

void loop() {
  blankscreen();                    // all pixels to black
  timeToStripe(hour(),minute());    // calculate time and fill leds array
  FastLED.show();                   // show it on the matix
  delay(500);                       // wait half a second
}

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

// recieve NTP answer
time_t getNtpTime() {
  IPAddress ntpServerIP; // NTP server's ip address

  while (Udp.parsePacket() > 0) ; // discard any previously received packets
  // get a random server from the pool
  WiFi.hostByName(ntpServerName, ntpServerIP);
  sendNTPpacket(ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
    }
  }
  return 0; // return 0 if unable to get the time
}

// send an NTP request to the time server at the given address
void sendNTPpacket(IPAddress &address) {
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}
