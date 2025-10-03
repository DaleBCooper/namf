//
// Created by viciu on 2/23/25.
//
#include "expander.h"

namespace EXPANDER {
    byte portState = 0x7F;  //pin 7 used for alarm. so we start with off
    bool present = false;

    bool isPresent() {return present;}

    bool init() {
        Wire.beginTransmission(0x26);
        Wire.write(portState);
        present = (Wire.endTransmission() == 0);
        return present;
    }

    bool setPin( byte pin, bool val) {
        if (!present || pin > 7) return false;
        if (val)
            portState |= (1 << pin);
        else
            portState &= ~(1 << pin);
        Wire.beginTransmission(0x26);
        Wire.write(portState);
        present = (Wire.endTransmission() == 0);
        return present;
    }

}