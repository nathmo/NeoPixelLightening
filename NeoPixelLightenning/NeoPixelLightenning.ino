#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#define NUM_LEDS 300
#define PIN 3
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);
int address = 0;
void setup() {
  // put your setup code here, to run once:
  strip.setBrightness(100);
  strip.begin();
  strip.show();
  
  EEPROM.write(address,(EEPROM.read(address)+1));
  if(EEPROM.read(address)==6)
  {
    EEPROM.write(address,0);
  }
}

void loop()
{
  if(EEPROM.read(address)==0)
  {
    vaporwave();
  }
  if(EEPROM.read(address)==1)
  {
    white();
  }
  if(EEPROM.read(address)==2)
  {
    whitest();
  }
  if(EEPROM.read(address)==3)
  {
    blue();
  }
  if(EEPROM.read(address)==4)
  {
    red();
  }
  if(EEPROM.read(address)==5)
  {
    green();
  }
}

void vaporwave()
{
    for(int i=0;i<NUM_LEDS;i++)
  {
    strip.setPixelColor(i, 255, 0, 255,0);
    strip.show();
    delay(25);
  }
  for(int i=0;i<NUM_LEDS;i++)
  {
    strip.setPixelColor(i, 0, 206, 209,0);
    strip.show();
    delay(25);
  }
}

void white()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
    strip.setPixelColor(i, 0, 0, 0,255);
  }
  strip.show();
}

void whitest()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
    strip.setPixelColor(i, 255, 255, 255,255);
  }
  strip.show();
}

void blue()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
    strip.setPixelColor(i, 0, 0, 255,0);
  }
  strip.show();
}

void red()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
    strip.setPixelColor(i, 255, 0, 0,0);
  }
  strip.show();
}

void green()
{
  for(int i=0;i<NUM_LEDS;i++)
  {
    strip.setPixelColor(i, 0, 255, 0,0);
  }
  strip.show();
}

