//
// Created by viciu on 13.01.2020.
//

#ifndef NAMF_SENSORS_SDS011
#define NAMF_SENSORS_SDS011

#include "Arduino.h"
#include "variables.h"
#include "helpers.h"
#include "sending.h"
#include "system/debug.h"
#include "html-content.h"   //just for sensor name, to be removed later
#include "webserver.h"  //HTML functions
//#include "PCF8574.h"
#include "SerialSDS.h"
#include "wifi.h"

namespace SDS011 {

    extern const char KEY[] PROGMEM;

    void readSingleSDSPacket(int *pm10_serial, int *pm25_serial);

    extern bool enabled;

    extern unsigned readings;
    extern SerialSDS channelSDS;
    extern unsigned failedReadings;
    extern bool hardwareWatchdog;
    extern byte hwWtdgCycles; //how many times watchdog took action
    extern unsigned long hwWtdgErrors;



    /*****************************************************************
 * send SDS011 command (start, stop, continuous mode, version    *
 *****************************************************************/

    void setDefaults();

    void SDS_rawcmd(const uint8_t cmd_head1, const uint8_t cmd_head2, const uint8_t cmd_head3);

    bool SDS_cmd(PmSensorCmd cmd);

    bool SDS_checksum_valid(const uint8_t (&data)[8]);

    JsonObject &parseHTTPRequest();

    bool getDisplaySetting();

    bool display(byte rows, byte minor, String lines[]);

    String getConfigJSON();

    void readConfigJSON(JsonObject &json);

    unsigned long process(SimpleScheduler::LoopEventType e);

    String getConfigHTML(void);

    void resultsAsHTML(String &page_content);

    void results(String &res);

    void sendToLD();

    void getStatusReport(String &);

    void afterSend(bool);

    /*****************************************************************
 * read SDS011 sensor serial and firmware date                   *
 *****************************************************************/
    String SDS_version_date();


/*****************************************************************
 * read SDS011 sensor values                                     *
 *****************************************************************/
    void sensorSDS(String &s);
}

#endif //NAMF_SENSORS_SDS011
