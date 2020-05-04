![PlatformIO CI](https://github.com/dakky/wordclock/workflows/PlatformIO%20CI/badge.svg?branch=master)

# Wordclock
This is my first DIY Wordclock

Instead of single pixels I used a digital LED-stripe (10 pieces of 11 LEDs and 1 piece of 4 LEDs) with WS2812B-LEDs
controlled by a NodeMCU (mini) with an ESP8266 Wifi module for configuration and NTP.

## Features
* NTP 
* WIFIManager


#### Stripe layout

There are two different layouts for two kinds of wireing the stripes. In the layout header files X/Y coords are mapped to the index no. of each LED on the stripes.

##### Layout 1

1st row left to right, 2nd row right to left, 3rd row left to right, ect...

```
  0 X--X--X--X--X--X--X--X--X--X--X 10
                                  |
 21 X--X--X--X--X--X--X--X--X--X--X 11
    |
 22 X--X--X--X--X--X--X--X--X--X--X 32
                                  |
 43 X--X--X--X--X--X--X--X--X--X--X 33
    |
 44 X--X--X--X--X--X--X--X--X--X--X 54 
                                  |
 65 X--X--X--X--X--X--X--X--X--X--X 55
    |
 76 X--X--X--X--X--X--X--X--X--X--X 76
                                  |
 87 X--X--X--X--X--X--X--X--X--X--X 77
    |
 88 X--X--X--X--X--X--X--X--X--X--X 98
                                  |
109 X--X--X--X--X--X--X--X--X--X--X 99
    |
    `---------X--X--X--X 
             110      113
```

##### Layout 2

Every row left to right.

```
   0 X--X--X--X--X--X--X--X--X--X--X 10
     ,-----------------------------´                              
  11 X--X--X--X--X--X--X--X--X--X--X 21
     ,-----------------------------´                              
  22 X--X--X--X--X--X--X--X--X--X--X 32
     ,-----------------------------´                              
  33 X--X--X--X--X--X--X--X--X--X--X 43
     ,-----------------------------´                              
  44 X--X--X--X--X--X--X--X--X--X--X 54 
     ,-----------------------------´                              
  55 X--X--X--X--X--X--X--X--X--X--X 65
     ,-----------------------------´                              
  66 X--X--X--X--X--X--X--X--X--X--X 76
     ,-----------------------------´                              
  77 X--X--X--X--X--X--X--X--X--X--X 87
     ,-----------------------------´                              
  88 X--X--X--X--X--X--X--X--X--X--X 98
     ,-----------------------------´                              
  99 X--X--X--X--X--X--X--X--X--X--X 109
     |
     `---------X--X--X--X 
              110      113
```


##### Words

The matrix shows 10x11 letters to represent the time in german words. An array for each word, containing the coords of the letters, are in the words header file.

|Y\X|1|2|3|4|5|6|7|8|9|10|11|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|**1**|E|S|K|I|S|T|A|F|Ü|N|F|
|**2**|Z|E|H|N|Z|W|A|N|Z|I|G|
|**3**|D|R|E|I|V|I|E|R|T|E|L|
|**4**|V|O|R|F|U|N|K|N|A|C|H|
|**5**|H|A|L|B|A|E|L|F|Ü|N|F|
|**6**|K|E|I|N|S|L|M|Z|W|E|I|
|**7**|D|R|E|I|A|U|J|V|I|E|R|
|**8**|S|E|C|H|S|N|L|A|C|H|T|
|**9**|S|I|E|B|E|N|Z|W|Ö|L|F|
|**10**|Z|E|H|N|E|U|N|K|U|H|R|

Four more pixels shows additional minutes. In the original WordClock, they are in the corners but I prefered to place them under the last row.

#### Reading the clock
##### 03:01
||||||||||||
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|***E***|***S***|K|***I***|***S***|***T***|A|F|Ü|N|F|
|Z|E|H|N|Z|W|A|N|Z|I|G|
|D|R|E|I|V|I|E|R|T|E|L|
|V|O|R|F|U|N|K|N|A|C|H|
|H|A|L|B|A|E|L|F|Ü|N|F|
|K|E|I|N|S|L|M|Z|W|E|I|
|***D***|***R***|***E***|***I***|A|U|J|V|I|E|R|
|S|E|C|H|S|N|L|A|C|H|T|
|S|I|E|B|E|N|Z|W|Ö|L|F|
|Z|E|H|N|E|U|N|K|***U***|***H***|***R***|
|||***X***||X||X||X|||

##### 07:52
||||||||||||
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|***E***|***S***|K|***I***|***S***|***T***|A|F|Ü|N|F|
|***Z***|***E***|***H***|***N***|Z|W|A|N|Z|I|G|
|D|R|E|I|V|I|E|R|T|E|L|
|***V***|***O***|***R***|F|U|N|K|N|A|C|H|
|H|A|L|B|A|E|L|F|Ü|N|F|
|K|E|I|N|S|L|M|Z|W|E|I|
|D|R|E|I|A|U|J|V|I|E|R|
|S|E|C|H|S|N|L|***A***|***C***|***H***|***T***|
|S|I|E|B|E|N|Z|W|Ö|L|F|
|Z|E|H|N|E|U|N|K|U|H|R|
|||***X***||***X***||X||X|||

##### 06:34
||||||||||||
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|***E***|***S***|K|***I***|***S***|***T***|A|F|Ü|N|F|
|Z|E|H|N|Z|W|A|N|Z|I|G|
|D|R|E|I|V|I|E|R|T|E|L|
|V|O|R|F|U|N|K|N|A|C|H|
|***H***|***A***|***L***|***B***|A|E|L|F|Ü|N|F|
|K|E|I|N|S|L|M|Z|W|E|I|
|D|R|E|I|A|U|J|V|I|E|R|
|S|E|C|H|S|N|L|A|C|H|T|
|***S***|***I***|***E***|***B***|***E***|***N***|Z|W|Ö|L|F|
|Z|E|H|N|E|U|N|K|U|H|R|
|||***X***||***X***||***X***||***X***|||

#### BOM
Article | Source | Price
---|---|---:|
WS2812B LED Stripes (30 LEDs/m, RGB) | [BangGood.com](http://www.banggood.com/5M-45W-150SMD-WS2812B-LED-RGB-Colorful-Strip-Light-Waterproof-IP65-WhiteBlack-PCB-DC5V-p-1035640.html) | 20,40 €
Mini NodeMCU | [BangGood.com](http://www.banggood.com/Mini-NodeMCU-ESP8266-WIFI-Development-Board-Based-On-ESP-12F-p-1054209.html) | 4,85 €
3A Micro-USB Supply | [BangGood.com](http://www.banggood.com/USUKEU-DC-5V-4A-AC-Adapter-Charger-Power-Supply-For-LED-Strip-Light-p-953473.html) | 4,49 €
Some wires|bargain bin|
