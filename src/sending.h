//
// Created by viciu on 17.02.2021.
//

#ifndef NAMF_SENDING_H
#define NAMF_SENDING_H

#include <Arduino.h>
#if defined(ESP8266)
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#endif

#include "ext_def.h"
#include "helpers.h"
#include "html-content.h"
#include "system/debug.h"
#include "variables.h"
#include "sensors/sds011/sds011.h"  //debugging SDS and sending data to InfluxDB

#include "ca-root.h"
extern void configureCACertTrustAnchor( WiFiClientSecure* client);

/*****************************************************************
 * send data to rest api                                         *
 *****************************************************************/
extern int sendData(const LoggerEntry logger, const String &data, const int pin, const String &host, const int httpPort, const String &url, const bool verify);

/*****************************************************************
 * send single sensor data to luftdaten.info api                 *
 *****************************************************************/
extern int sendLuftdaten(const String& data, const int pin, const char* host, const int httpPort, const char* url, const bool verify, const char* replace_str);

/*****************************************************************
 * send data to LoRa gateway                                     *
 *****************************************************************/
// void send_lora(const String& data) {
// }

/*****************************************************************
 * send data to mqtt api                                         *
 *****************************************************************/
// rejected (see issue #33)

/*****************************************************************
 * send data to influxdb                                         *
 *****************************************************************/
extern String create_influxdb_string(const String& data);

/*****************************************************************
 * send data as csv to serial out                                *
 *****************************************************************/
extern void send_csv(const String& data);

#endif //NAMF_SENDING_H
