#pragma once

#ifndef tinyLED_H
#define tinyLED_H

#include "configs.h"
#include "settings.h"

#include "UMS3.h"

extern Settings settings_obj;

class tinyLED : public UMS3 {

    private:
        uint32_t initTime = 0;
        uint8_t scan_mode = 0;
        uint8_t currentScanMode = 0;
        uint32_t PIXEL_BLACK = 0x000000;
        uint32_t PIXEL_WHITE = 0xFFFFFF;
        uint32_t PIXEL_RED = 0xFF0000;
        uint32_t PIXEL_BLUE = 0x0000FF;
        uint32_t PIXEL_GREEN= 0x00FF00;
        uint32_t PIXEL_YELLOW = 0xFFFF00;
        uint32_t PIXEL_MAGENTA = 0xFF00FF;
        uint32_t PIXEL_VIOLET = 0x7B00FF;
        uint32_t PIXEL_ORANGE = 0xFFA500;

    public:
        void RunSetup();
        void main(uint32_t currentTime, uint8_t currentScanMode);
        void attackLED(uint8_t scan_mode);
        void sniffLED(uint8_t scan_mode);
        void offLED();
        void flashLED();
        void setScanMode(uint8_t mode) { currentScanMode = mode; }
};

#endif  /* tinyLED_H */