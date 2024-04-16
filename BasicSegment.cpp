#include "BasicSegment.h"
#include <stdio.h>

BasicSegment::BasicSegment(Adafruit_NeoPixel& ledArray, short startLed, short segmentLength)
{
    this->startLed = startLed;
    this->segmentLength = segmentLength;
    this->ledArray = ledArray;
}

void BasicSegment::turnOff()
{
    state = false;
    for (short i = startLed; i < (startLed + segmentLength); i++)
    {
        ledArray.setPixelColor(i, ledArray.Color(0,0,0));
    }
}

void BasicSegment::turnOn()
{ 
    state = true;
    for (short i = startLed; i < (startLed + segmentLength); i++)
    {
        ledArray.setPixelColor(i, 
            ledArray.Color(
                colors.red,
                colors.green,
                colors.blue
            )
        );
    }
    ledArray.setBrightness(brightness);
}

void BasicSegment::setBrightness(short newBrightness)
{
    brightness = newBrightness;
    if (ledArray.getBrightness() != brightness)
        ledArray.setBrightness(brightness);
}

void BasicSegment::setColors(unsigned short red, unsigned short green, unsigned short blue)
{
    rgbColors newColor = rgbColors(red, green, blue);
    colors = newColor;
    for (short i = startLed; i < (startLed + segmentLength); i++)
    {
        ledArray.setPixelColor(i, 
            ledArray.Color(
                colors.red,
                colors.green,
                colors.blue
            )
        );
    }
}

bool BasicSegment::getState()
{
    return state;
}

int BasicSegment::getBrightness()
{
    return brightness;
}

rgbColors BasicSegment::getColors()
{
    return colors;
}
