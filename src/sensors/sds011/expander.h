//
// Created by viciu on 2/23/25.
//

#ifndef NAMF_EXPANDER_H
#define NAMF_EXPANDER_H

#include <Arduino.h>
#include <Wire.h>

namespace EXPANDER {
    //is PCF present in system
    bool isPresent();
    bool init();
    bool setPin(byte, bool);
}
#endif //NAMF_EXPANDER_H
