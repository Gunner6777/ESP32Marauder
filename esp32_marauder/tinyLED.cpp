#include "tinyLED.h"

void tinyLED::RunSetup() {
  
  UMS3::begin();

  this->initTime = millis();

  // Brightness is 0-255. We set it to 1/5th brightness here
  this->setPixelBrightness(255 / 15);
  // Set color, R 0-255, G 0-255, B 0-255
  this->setPixelColor(PIXEL_VIOLET);

  if (!settings_obj.loadSetting<bool>("EnableLED")) {
    this->setPixelPower(false);
    return;
  } else {
    // Enable the power to the RGB LED.
    // Off by default so it doesn't use current when the LED is not required.
    this->setPixelPower(true);
  }

  delay(50);

  this->setPixelBrightness(255 / 15);
  delay(150);
  this->setPixelBrightness(0);
  delay(100);
  this->setPixelBrightness(255 / 15);
  delay(150);
  this->setPixelBrightness(0);
  delay(100);
  this->setPixelBrightness(255 / 15);
  delay(150);
  this->setPixelBrightness(0);
  delay(100);
  this->setPixelBrightness(255 / 15);
  delay(150);
  this->setPixelBrightness(0);
  delay(350);
  this->setPixelBrightness(255 / 15);
  delay(150);
  this->setPixelBrightness(0);
  delay(100);
  this->setPixelBrightness(255 / 15);
  delay(150);
  this->setPixelBrightness(0);
}

void tinyLED::attackLED(uint8_t scan_mode) {
  if (!settings_obj.loadSetting<bool>("EnableLED"))
    return;
  
  this->setPixelBrightness(0);
  this->setPixelColor(PIXEL_RED);
  delay(300);
  this->setPixelBrightness(255 / 51);
}

void tinyLED::sniffLED(uint8_t scan_mode) {
  if (!settings_obj.loadSetting<bool>("EnableLED"))
    return;
  
  this->setPixelBrightness(0);
  if (scan_mode == 45) {
    this->setPixelColor(PIXEL_ORANGE);
  } else if (scan_mode == 10 || scan_mode == 11 || scan_mode == 34 || scan_mode == 35 || scan_mode == 43 || scan_mode == 44 || scan_mode == 47 || 
        scan_mode == 70 || scan_mode == 72 || scan_mode == 73 || scan_mode == 74 || scan_mode == 75) {
    this->setPixelColor(PIXEL_BLUE);
  } else {
    this->setPixelColor(PIXEL_MAGENTA);
  }
  delay(300);
  this->setPixelBrightness(255 / 51);
}

void tinyLED::offLED() {
  if (!settings_obj.loadSetting<bool>("EnableLED"))
    return;
    
  this->setPixelBrightness(0);
}

void tinyLED::flashLED() {
  if (!settings_obj.loadSetting<bool>("EnableLED"))
    return;
  
  this->setPixelBrightness(255 / 15);
  delay(100);
  this->setPixelBrightness(0);
}

void tinyLED::main(uint32_t currentTime, uint8_t currentscan_mode) {
  if (!settings_obj.loadSetting<bool>("EnableLED")) {
    this->setPixelPower(false);
    return;
  }

  if (currentTime != 0) {
    // Flash LED every 30 seconds
    if ((currentTime - initTime >= 60000) && (currentscan_mode == 0)) {
      this->initTime = millis();
      this->setPixelColor(PIXEL_VIOLET);
      this->flashLED();
    }
  }
}