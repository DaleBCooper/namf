//
// Created by viciu on 25.01.2020.
//

#ifndef NAMF_UPDATE_H
#define NAMF_UPDATE_H

#include "defines.h"
#include "variables.h"
#include "helpers.h"
#include "sending.h"
#include "sensors/sds011/sds011.h"

#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h> /// FOR ESP32
#include <HTTPClient.h> /// FOR ESP32 HTTP FOTA UPDATE ///
#include <HTTPUpdate.h> /// FOR ESP32 HTTP FOTA UPDATE ///
#include <WiFiClient.h> /// FOR ESP32 HTTP FOTA UPDATE ///
WiFiClient *client;
t_httpUpdate_return tryUpdate(const String& host, const String& path, const String& ver, const bool SSL_only) {
    unsigned int port = SECURE_UPDATE_PORT;
    client = new WiFiClientSecure;
    configureCACertTrustAnchor(static_cast<WiFiClientSecure *>(client));
    t_httpUpdate_return ret = httpUpdate.update(*client, host, port, path, ver);
//    t_httpUpdate_return ret = httpUpdate.update(*client, "192.168.1.228", 9080, path, ver);
    if (ret == HTTP_UPDATE_FAILED && httpUpdate.getLastError() == -1 && !SSL_only) { //connection refused, maybe problem with SSL, try port 80
        delete client;
        client = new WiFiClient;
        port = UPDATE_PORT;
        ret = httpUpdate.update(*client, host, port, path, ver);
    }
//no OTA for now
    return ret;
}
#else

#include <ESP8266WiFi.h>
#include <ESP8266httpUpdate.h>
#include "helpers.h"
t_httpUpdate_return tryUpdate(const String host, const String port, const String path, const String ver) {
    WiFiClient client;
    Serial.println(ver);
    t_httpUpdate_return ret = ESPhttpUpdate.update(client, host, port.toInt(), path, ver);
    return ret;
};
#endif

t_httpUpdate_return tryUpdate(String const& ver, boolean SSL_only = false) {
    String host;
    String url;
    switch(cfg::update_channel) {
        case UPDATE_CHANNEL_ALFA:
            host = String(UPDATE_HOST_ALFA);
            url = String(UPDATE_URL_ALFA);
            break;
        case UPDATE_CHANNEL_BETA:
            host = String(UPDATE_HOST_BETA);
            url = String(UPDATE_URL_BETA);
            break;
        default:
            host = String(UPDATE_HOST);
            url = String(UPDATE_URL);
            break;
    }
    debug_out(F("Update checked:"), DEBUG_MIN_INFO,true);
    debug_out(host, DEBUG_MIN_INFO,true);
    debug_out(url, DEBUG_MIN_INFO,true);
    return tryUpdate(host, url, ver, SSL_only);
};

void verifyUpdate (t_httpUpdate_return result) {
    last_update_attempt = millis();
    switch (result) {
        case HTTP_UPDATE_FAILED:
            display_debug(F("[update] Update failed."),"");
            Serial.println(F("[update] Update failed."));
            break;
        case HTTP_UPDATE_NO_UPDATES:
            display_debug(F("[update] no Update."), String(SOFTWARE_VERSION));
            Serial.println(F("[update] no Update."));
            Serial.print(F("Still running version: "));
            Serial.println(SOFTWARE_VERSION);
            break;
        case HTTP_UPDATE_OK:
            Serial.println(F("[update] Update ok.")); // may not called we reboot the ESP
            break;
    }


}


String sds_report() {
    String ret = F("");
    if (SDS011::enabled || cfg::sds_read) {
        ret += String(SDS011::failedReadings) + String(F("-")) + String(SDS011::readings);
//        SDS011::failedReadings = SDS011::readings = 0;
    } else {
        ret += F("na-na");
    }
    return ret;
}



void updateFW() {
    Serial.print(F("Check for update with default URL"));
    Serial.println(SOFTWARE_VERSION);
    display_debug(F("Update - check"), F(""));

    String sensorPM = F("");
    if (SDS011::enabled) { sensorPM = F("SDS");}
    else if (cfg::pms_read) {sensorPM = F("PMSx");}
    else if (SPS30::started) {sensorPM = F("SPS");}

    String ver = String(SOFTWARE_VERSION);
    ver.concat(String(F(" ")));
    ver.concat(esp_chipid());
    ver.concat(String(F(" ")));
    ver.concat(sensorPM);
    ver.concat(String(F(" ")));
    ver.concat(String(cfg::current_lang));
    ver.concat(String(F(" ")));
    ver.concat(String(FPSTR(INTL_LANG)));
    ver.concat(String(F(" ")));
    ver.concat(sds_report());

    t_httpUpdate_return ret = tryUpdate(ver);
    verifyUpdate(ret);
};

#endif //NAMF_UPDATE_H
