//
// Created by viciu on 2/8/25.
//

#ifndef NAMF_DNMS_H
#define NAMF_DNMS_H

#include <Arduino.h>
#include "system/scheduler.h"
#include "helpers.h"
#include "html-content.h"
#include "sending.h"


namespace DNMS {
    extern const char KEY[] PROGMEM;
    extern bool enabled;

    JsonObject &parseHTTPRequest();
    String getConfigJSON();
    void getStatusReport(String &res);
    void readConfigJSON(JsonObject &json);
    unsigned long process(SimpleScheduler::LoopEventType);
    int16_t readVersion(char *);
}

#endif //NAMF_DNMS_H
