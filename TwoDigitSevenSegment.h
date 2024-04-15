#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include "SingleDigitSevenSegment.h"
#include "DebugLogger.h"


class TwoDigitSevenSegment
{
private:
    short segmentLength;
    unsigned short dataPin;
    unsigned short number;
    SingleDigitSevenSegment digits[2];
    Adafruit_NeoPixel ledPixels;
    DebugLogger logger = DebugLogger();


public:
    TwoDigitSevenSegment(unsigned short dataPin, short segmentLength);
    void setNumber(unsigned short number);
    void turnOff();
    void turnOn();
    void setLedSettings(
        unsigned short red, 
        unsigned short green, 
        unsigned short blue, 
        unsigned short brightness
        );
    void begin();
    void refreshDisplay();
    short getNumber();
    SingleDigitSevenSegment* getDigits();
};

#endif
