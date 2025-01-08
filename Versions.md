NAMF-47rc1 ()
- disable WiFi when reading data from SDS011. It seems to resolve problems with checksum errors of SDS011 
- ESP32 version changed to work with Heltec Wireless Stick Lite V3 (ESP32-S3)
- Update server works with ESP8266 & ESP32
- Updates are downloaded via SSL with fallback over unsecure connection (fully working for ESP32, not finished for ESP8266)

NAMF-2020-46rc13 (2024-09-12 rev e79b03f2a5e7cdd64b98cd100914383860f39b44)
- returning with setting continuous mode for SDS

NAMF-2020-46rc12 (2024-09-10 rev b028bb217b91f130c220685189ece4c52989a5bb)
- longer reading time (more packets processed) should help in case higher checksum error ratio will be present in stable release 

NAMF-2020-46rc11 (rev 297359cf46db17449de4b3f313c8098d5774b418)
- completely disabled power on SDS settings from 46rc6

NAMF-2020-46rc10 (rev 74a5c5716e1b62b9d9306d504f51c4b4b0abfd66)
- testing other power on command on SDS011

NAMF-2020-46rc9 (2024-09-08 rev 55d4573558174662fce128cc98a42e0eaf7ef994)
- added info (help) to DS18B20 about resistor needed for the sensor to work
- test only one continuous mode command on SDS011 poweron (it looks like change in 46rc6 made checksum error rate vary high)
- fixed missing one translation in PL fw

NAMF-2020-46rc8 (2024-08-19 rev 75e6b449a2e9ea9be574612a92255e6511dc4233)
- fixed typo preventing using authentication data for Influx 1.x

NAMF-2020-46rc7 (2024-07-30 rev e8e81ddced0ac2849c8d6a761f326c5105c1f01f)
- update request string has info about PM sensor encoded (SDS/PMS/SPS)
- in case sensor can not connect to WiFi on boot and have WiFi configured then it will try to reconnect every hour after config AP has been shut down
- CO2 sensor - don't report on LCD last value of CO2 if sensor stop sending data
- debug level setting will be restored after reboot. Until now, it was always sent to DEBUG_MIN_INFO
- GPS library updated
- Provide some help in sensor config (as external site via GitHub pages)

NAMF-2020-46rc6 (2024-04-11 rev  576e930e78a681a322386ade3f6afa03a8e703bb)
- send both continuous commands to SDS011 on power on

NAMF-2020-46rc5 (2024-03-27 rev c241c37af68aef29e3a06a76925e9070f2ae3fb7)
- support for BH1750 ambient lux sensor [(product page on Nettigo)](https://nettigo.eu/products/ambient-light-sensor-bh1750fvi-i2c)
- track API performance (last HTTP response code and time to send data). For now does not track Sensor Community (many HTTP requests)
 
NAMF-2020-46rc4 (2023-03-14 rev 1d846210d6c6171cc96d4fc9bc48ce8eb8dc27e9)
- Platformio espressif8266 platform upgraded to 4.2.1
- New Let's Encrypt root CA certificate

NAMF-2020-46rc3 (2023-12-13 rev 4c918cc89eedcedcb03579811293d1e5818150bd)
- LoRaWAN support (with Heltec Wireless Stick Lite v3 board)
- changes in WiFi mode, now it allow for running sensor in AP mode
- for English language use 0.pool.ntp.org as NTP source
- in config mode, WiFi list is updated periodically
- simplified LCD selector in config
- autodetect I2C address for LCD
- BME280 display code moved to new scheduler
- allow to disable LCD backlight during night hours (hours configurable)
- fix for issue #68 - BME will not send data to API when failure with communication results in no readings
- "progress bar" on 4x20 LCD showing time to send data

NAMF-2020-46rc2 (2023-09-04 rev 202f8c1ccad2626e2e0cd8bce108a2d5920e7b33)
- Factory Reset procedure 3 x RST, each in first 5 seconds

NAMF-2020-46rc1 (2023-03-07 rev b6414d61f89b433deee09ae5bbe7a582eb1b0ea7)
- Arduino core updated to 3.1.1
- Interface to SDS011 updated to changed ESP Software Serial

NAMF-2020-45 (2023-01-07 rev 1e7d1aac0cdf06b48bcd51614b02cb9b6efae678)
- based on NAMF-2020-45rc3

NAMF-2020-45rc3 (2022-12-23 rev d026921c25dd8f46299e4bfe023970679e988148)
- removed -ggdb3 from build options
- fixes for JS/CSS to show/hide advanced options
- SDS011 uses advanced options CSS
- Displaying device info on LCD can be disabled

NAMF-2020-45rc1 (2022-11-28 rev 4ec6023c1419f40825da12f8118685a8f33f8ab6)
- some CSS/JS for advanced configuration options for sensors (to be hidden by default)
- /rollback method allow to downgrade sensor
- report HTTP code in log when sending data to API fails
- display info what is current logging level

NAMF-2020-44 (2020-10-06 rev b36d65f7acda9739dd43e5990c161eb55baa0d58)
- merged all changes from 44rc5
- fixed subsystem names on /status page. After changing order of sensors on config page matching names was not sorted in /status page

NAMF-2020-44rc5 ()
- increase safe time between ending SDS011 measurement and sending to API 5 sec (was 2 sec)

NAMF-2020-44rc4 (2022-09-08 rev ceabe601ee16457e752bf39c720f8697a1f116c7)
- more descriptive message when saving config (sensors managed by new scheduler)
- sensor order (config page) is updated - SDS, HECA & BME are first ones

NAMF-2020-44rc3 (2022-07-24 rev 72832ed93b3e4898bef3b35c539f9280c66b3bec)
- use 'nettigo.pl' as password for WiFi network in setup mode
- make sure that when data was sent to APi SDS011 is put into sleep, not left running until next measurement

NAMF-2020-44rc2 (2022-07-09 rev 292cf2049d3e6d2ee6dcb302556abe5f3fe1e333)
- When change in old form was made display warning during saving config from new scheduler (they are in separate forms)
- Fixed bug - BMP280 was sending data to APIs as BMP180
- https://AQI.eco is now treated as separate API. Can be configured old way as third party API, or directly.
- debug logs are stored in buffer - can be retrieved by WWW interface. Since there is a lot of messages during startup, there is no chance to get all of them stored before webserver is ready, so boot messages are always not complete. This feature is mostly for debug when sensor is up & running.
- When saving config, even in verbose mode JSON string is displayed only on UART, not in web serial (passwords)

NAMF-2020-44rc1 (2022-06-25 rev 375f766f48ec64f6901bebd11d77f11558dfea1f)
- merged changes from alpha version 42a2:
  - not allocating memory for unused variables
  - fallback WiFi - secondary WiFi network to connect by NAM if no primary network. Useful when You have many sensors managed by single organization. You can provide secondary WiFi credentials to work with when NAM is in lab/service.
- New config page layout, much more readable
- **IMPORTANT** now sensor in config mode does not start with unencrypted network. Uses _nettigo123_ as password, SSID NAM-XXXXXX or other if set in config


NAMF-2020-43 (2021-12-31 rev 5c2012c8d7d9f8358873ebb1478ff4dcd69c2c44)
- based on 43rc1
- sensors on stable software send diagnostic data each 12h not 24h

NAMF-2020-43rc1 (2021-12-29 rev6b574fa5b8cbae67f3f33153dc8e752c1e5324f2)
- save opt-out for sending data to Nettigo
- added link to homepage from each sensor page

NAMF-2020-42 (2021-12-29 rev )
- merged all changes from 42rcX line

NAMF-2020-42rc7 (2021-12-08 rev f848b44f34d24ad104280d0dcf22f7b4c974c79d)
- do not collect WiFi stats when no connection...

NAMF-2020-42rc6 (2021-12-07 rev 6522bc7facf6c58b68ac2f6a53c90952cf8a2cd7)
- updated JSON sent to Nettigo on boot time

NAMF-2020-42rc5 (2021-11-29 rev 8d2848fa82aad63817deec9dd187e901d1ee1b99)
- just version bump to get new beta diagnostic data endpoint URL

NAMF-2020-42rc4 (2021-11-25 rev 1155d420d0b9139cfa646ac92d7276ac462136a5)
- added some missing translations
- updated diagnostic data upload URL 

NAMF-2020-42rc3 (2021-11-25 rev )
- make sure to request EN language file if somehow value from config file is on not supported list

NAMF-2020-42rc2 (2021-11-25 rev )
- fixed SDS reporting to Nettigo
- Romanian translation

NAMF-2020-41 (2021-11-08 rev )
- Release based on NAMF-2020-41rc4
- Fixed typo in JavaScript - fetching available WiFi networks did not work correctly
  
NAMF-2020-41rc4 (2021-10-22 rev 5cef0c51c14b4f6ed808df84df222f415e895b04)
* BMP180 has checkbox to indicate that it is inside of NAM case. NAM wont send temperature from that sensor to APIs, since it will higher
* Fixed LED BAR (used old SDS enable variable)
* opt out for diagnostic data 

NAMF-2020-41rc3 (2021-10-13 rev bda18bbc218ae723c61bc3d909504ab5c8d8642a)
* going back to Espressif 2.6.2 - memory problems when building /config page
* fixed interval in reporting diagnostic data
* fix for Winsen MHZ14A - does now send data

NAMF-2020-41rc2 (2021-10-12 rev 0102e07f4cb2f087c3cb0f6e9e4ae520d62642cd)
* more diagnostic data is sent to Nettigo
* probably regression on Winsen sensor should be fixed

NAMF-2020-41rc1 (2021-10-11 rev d14fcf4f4708e383e1aef072631061fa2d6ab34b)
* we start with diagnostic data collection, opt-out will be possible, now just sending data on sensor boot
* new Platformio Espressif Core (3.2.0) with Arduino Core 3.0.2

NAMF-2020-40 (2021-09-09 rev 2e2b1058652885059ca7f0b205fb1bbbfa4ba977)
* this is release based on 40rc3 

NAMF-2020-40rc3 (2021-09-08 rev bca0cddde30475881515ed46b054543f95cf7e65)
* make sure all sensors are enabled by default for fresh sensor

NAMF-2020-40rc2 (2021-08-27 rev 52a7388b8f17a4ca54271ce8901959fe837d78bd)
* fixed measurements reading from SDS when NAM is not sending data to SensorCommunity
* new way to set enabled sensors when no config file. Will allow to run PMS sensor.
  
* NAMF-2020-40rc1 (2021-08-23)
* Why 40 not 39? 39 was used in alpha fw line and uses different SDS library. We have decided to use code from 38 branch. To avoid confusion 39 is skipped
* Bigger SerialSDS buffer to fit PMS sensor response

NAMF-2020-38 (2021-08-20 rev 7fd0940d7453374cd59bf138edfebd840179a224)
* 38rc18 only with changed version number

NAMF-2020-38rc18 (2021-08-13 rev 9a35fdcdec50b2d84e13c0b1b70b1dccf6f45998)
* this is true pre-stable release. Since there are a lot of changes compared to NAMF-2020-37 this build is test before release (debug settings are identical as in stable, to get 100% there are no problems with fw) 

NAMF-2020-38rc17 (2021-08-06 rev a3233a0ad6292fa76d9246f99ad2b211aa0d2f01)
* BME280 support moved into new scheduler
* do not send data when no measurements

NAMF-2020-38rc16 (2021-08-04 rev 2bb1a84e9122198727466b2f739a712a2edc4694)
* support for older BMP sensors (BMP180/SHT31 will be used as BME280 replacement)
* changes to String handling in many places (concat instead of operator +=)

NAMF-2020-38rc15 (2021-07-31)
* tweaks with timings of SoftwareSerial
* SDS hardware watchdog - count total number of hw cycles

NAMF-2020-38rc14 (2021-06-19)
* display total and failed number of SDS readings
* display time from last update check
* corrected counting SDS failed/successful readings

NAMF-2020-38rc13 (2021-06-18)
* lucky thirteen (?)
* processing SDS packet using onReceive
* SDS serial buffer 20 bytes - should fit 2 responses
* disable interrupts on SDS serial TX

NAMF-2020-38rc12 (2021-06-17)
* good measurement SDS resets failed measurements counter 
* smaller buffer in SDS Serial
* compact timestamp when logging to console

NAMF-2020-38rc11 (2021-06-15)
* fixed version number in binary  
* hardware SDS restart after 3 missing measurements, not after first 

NAMF-2020-38rc10 (2021-06-15) (typo in version number, binary built with 39 not 38...)
* new SDS code, moved some functionality to separate class, work in progress 
  to get nonblocking full implementation SDS communication protocol, not just toss
  some commands to SDS...
* support for hardware watchdog/restarter for SDS

NAMF-2020-38rc9 (2021-06-07)
* old (2019 line) code for sending SDS commands (diagnosing SDS problems)

NAMF-2020-37a (2021-06-04)
* collect SDS statistics when checking for an update

* NAMF-2020-38rc8 (2021-06-04)
* fixed update check interval for beta channel

NAMF-2020-38rc7 (2021-05-26)
* add mDNS TXT field 'manufacturer'
* when checking for update report number of SDS readings

NAMF-2020-38rc6 (2021-05-20)
* send TXT record with ID key (NAM-XXXX), to allow Home Assistant to discover NAM if host name is set to different than NAM-XXXX
* SHT3x sensor used as temp/humidity sensor (not in HECA) can display measurements on LCD
* rewrite display interface in new scheduler - more simple code, new scheduler displays now both on LCD and OLED
* SPS30 FW version displayed on /status page

NAMF-2020-38rc5 (2021-05-17)

* with new SDS code result -1 (no data from SDS) is being reported to Influx (not to other APIs) like it was with old code in 37rc3 

NAMF-2020-38rc4 (2021-05-16)

* old HECA/SDS011 enable checkbox enables both sensor and LCD display - to mimic old behaviour
* subsystem list on /values page is now complete (SDS011 name was missing)

NAMF-2020-38rc3 (2021-05-14)

* if HECA old_style was enabled - force enabling new HECA subsystem. No reconfiguration need after upgrade

NAMF-2020-38rc2 (2021-05-14)

* HECA is now under new scheduler
* HECA reports duty cycle (how long heater was enabled during current measurement period)
* SDS011 now display header on LCD 20x4
* sending hostname to Influx was lost during merge - reenabled

NAMF-2020-38rc1 (2021-05-10)

* aim to finish SDS readings 2 sec before sending time - should not catch SDS during collecting data on sending time
* log when procedure takes longer than 1s
* use SoftwareSerial library bundled with Arduino Core
* added uptime to data.json (in seconds)
* on /values page there is a link to graphs for given sensor on madavi.de

NAMF-2020-37 (2021-04-27)

* Merged all beta releases (37rcX)

NAMF-2020-37rc5 (2021-04-15)
* better translation on config page (new scheduler)
* use subsystem names on /status pages
* fixed Network Watchdog - do not toggle status when saving config on enabled WTD

NAMF-2020-37rc4 (2021-04-14)
- send to influx hostname (fs_ssid) 

NAMF-2020-37rc3 (2021-03-30)
- when sending to Infux send also firmware version and update channel
- if SDS is enabled always send result to influx. This will send -1 instead skipping reading - but **only** for influx. Other APIs won't get -1 (behavior won't change)
- due to misconfiguration of build environment this release will use proper SoftwareSerial version (previous binaries were built against older version)

NAMF-2020-37rc2 (2021-03-28)
- support for NAM LED BAR with brightness regulation
- status/debug info moved from /values to new page /status
- dump seen I2C addresses on status page
- NTP server is selected based on firmware language

NAMF-2020-37rc1 (2021-03-22)
- do not send wrong data when WINSEN MHZ14A is enabled, but not present
- getting time from NTP fixed

NAMF-2020-36 (2021-03-22)

Merged NAMF-2020-36rc3 and previous

NAMF-2020-36rc3 (2021-02-20)
- new names for JSON variables in SHT3x

NAMF-2020-36rc2 (2021-02-17)
- Sending data to LuftDaten/SensorCommunity from SPS30 and SHT3x

NAMF-2020-36rc1
- Espressif8266 platform upgrade (2.6.2) - Arduino Core 2.7.4

NAMF-2020-35 (2021-01-25)

Merged NAMF-2020-35rc5:

* Winsen MHZ14A support moved to new scheduler
* SPS30 and MHZ14A can now display results on LCD
* fixes to config pages (new scheduler)
* `upload_config.ini` allows to setup custom Platformio options for developers and not interfere with main .ini file

NAMF-2020-35rc5 (2021-01-20)
- fix for two or more sensors having access to display 

NAMF-2020-35rc4 (2021-01-19)
- enabling/disabling LCDs for Winsen and SPS30 should now work
- changed  SPS30 20x4 screens layout a bit

NAMF-2020-35rc3 (2021-01-16)
- MHZ14A support moved to new scheduler
- display CO2 concentration on LCD

NAMF-2020-35rc2 (2021-01-08)
- display data on LCD for sensors managed by new scheduler
- support for custom upload options like OTA password (see platformio.ini, search for uplaod_options.ini)
- fixed error when enabling sensors managed by new scheduler (it was toggle more than enable)
- more readable sensors description on config page (new scheduler)

NAMF-2020-35rc1 ()
- Dont broadcast OTA service, until it is not enabled via /ota
- You can use upload_opts.txt file to provide upload password (see `platformio.ini`)

NAMF-2020-34 (2020-12-18)
- new stable release, includes all 34rcx from beta

NAMF-2020-34rc5 (2020-10-08)
- bigger memory buffer for JSON data
- send GPS_date and GPS_time to influx as strings

NAMF-2020-34rc4 (2020-10-08)
- fix for core dump when enabling Network Watchdog

NAMF-2020-34rc3 (2020-09-12)
- don't show empty SHT3x results when sensor is not enabled

NAMF-2020-34rc2 (2020-09-12)
- support for SHT3x sensor as temperature/humidity (fixed 0x45 I2C address, since 0x44 is being used by HECA)
- a bit more separation between forms on config page

NAMF-2020-34rc1 (2020-08-31)
* merged PR#16 - allows upload code via OTA, for dev purposes, requires to have password

NAMF-2020-33 (2020-08-22)
* stable relase based on rc3

NAMF-2020-33rc3 (2020-08-21)
* SPS30 - added missing 0.5 particles count reading 

NAMF-2020-33rc2 (2020-08-14)
* version bump to check autoupdate software option
* increased update check interval from 1h to 6h
* enabling SPS30 w/o connected hardware should not stop whole sensor
* use UTF-8 explict when open language files (required on Windows to compile) 

NAMF-2020-33rc1 (2020-08-13)
* respect autoupdate option

NAMF 2020-32 (2020-08-01)
* Updated missing translations in Polish

NAMF 2020-31 (2020-07-08)
* new scheduler
* SPS30 support (high precision particular matter sensor from Sensirion)
* network watchdog - restart sensor if can not ping given IP for three times in row (10 pings each time)

NAMF 2020-30 (2020-06-02)
* CPU clock boosted to 160 MHz
* display info about free SPIFFS and CPU freq on start (Serial)
* First green LED on LED bar now starts from 0.1 instead 1.
* Option to set WiFi PHY Mode to extend range

NAMF 2020-29 (2020-05-18)
* in case of crash, stack dump will be saved in /stack_dump file on SPIFFS
* new url /stack_dump shows latest stack dump

NAMF 2020-28 (2020-04-24)
* option to disable displaying WiFi SSID/IP addr
* code cleanup - moved some display functions to separate files

NAMF 2020-27 (2020-04-05)
* fixed malformed JSON in /data.json (merged PR#5)

NAMF 2020-26 (2020-03-17)
* added I2C RGB LED Bar support

NAMF 2020-25 (2020-03-09)
* merged PR#4 with Logger differentiation based on Luftdaten code
 
NAMF 2020-24 (2020-03-08)
* added Content-Length to headers when sending data to API. Should fix issue #3 

NAMF 2020-23 (2020-03-3)
* technical release to make sure binaries on update server correspond to code in GH

NAMF 2020-22 (2020-03-3)
* check for updates every hour
* don't check for update every time when sending data 

NAMF 2020-21 (2020-02-27)
* default Winsen MH-Z14A CO2 range set to 2000 ppm
* Winsens averaging function should not lower result in first measurement
* polish fw can be built with build timestamp in page header (create .add_build_time empty file in root directory)

NAMF 2020-20 (2020-02-22)
* bugfix in Winsen CO2 averaging function

NAMF 2020-19 (2020-02-22)
* both BME280 and HECA should not send to API results when communication error (still -128°C as temperature in WWW intreface)
* changed BME280 library to fork with fixed hangs. Waiting for AF to include changes
* (almost) all logs on Serial are with timestamps
* don't send HECA logs to Luftdaten API
* support for CO2 sensor - Winsen MH-Z14A, connect it to D6/D5 instead of GPS. So CO2 sensor or GPS no both  

NAMF 2020-18 (2020-02-21)
* we return to 80MHz on ESP8266
* VTables in DRAM
* bugfixes, hope to get more reliable

NAMF 2020-17 (2020-02-19)
* uptime is nice formatted not just seconds
* outputPower can be adjusted also in AP mode

NAMF 2020-16 (2020-02-19)
* hostname for DHCP server
* interface changes: removed map link, utf-8 icons in main menu
* interface changes: removeConfig moved to bottom, save & restart is now red, more icons
* config AP SSID is now mDNS and DHCP hostname. Using UTF-8 special chars and dot (".") may mess with propper mDNS resolving.
* disabled HTTP 1.1 support in HTTP client
* removed unused links /generate_204 & /fwlink
* readme update
* lang files update
* sensor name based on AP SSID visible in header
* removed int_templ.h 

NAMF 2020-15 (2020-02-18)
* /forceUpdate will now work with custom URL, until now it worked only with default
* new config option - WiFi TX output power

NAMF 2020-14 (2020-02-17)
* HECA support moved to src/sensors/heca
* started move webserver functions to separate file
* stopped software version spoofing

NAMF 2020-13 (2020.02.17)
* fix for garbage auth data when sending to Luftdaten/Madavi

NAMF 2020-12 (2020.02.17)
* allow to disable character LCD
* remove config button is now orange to avoid confusion with restart button
* fixed basic auth when sending to influx and custom API

NAMF 2020-11 (2020.02.16)
* moved to dynamic definition of LCDs (both character and graphical) Less code, less memory
* since only one char LCD is supported in given config HTML was changed to dropdown on config page
* memory stats are being collected in more logic way (max/min values measured at end of each loop)
* WiFi password is visible in input field when sensor is being first time configured. When already configured sensor is booted in AP mode, password is not shown (thus saving form with empty field will remove password from config)  

NAMF 2020-10 (2020.02.14)
* new core 2.6.3
* added Core & SDK version to measurements page
* more internal parameters (heap frag, free mem etc) is being sent to Influx
* a lots love with st Valentine's day!

NAMF 2020-9 (2020.02.13)
* /data.json now returns also measurements count
* added MaxFreeBlockSize and HeapFragmentation to influx and diagnostics (on current values pages)
* added Uptime, Reset Reason, Free Memory and Heap Fragmentation to measurements page

NAMF 2020-8 (2020.02.11)
* mDNS brought back
* to influx sensor sends also amount of free memory
    
NAMF 2020-7 (2020.02.10)
* memory leak in sendData fixed
* new target with stage boot firmware (migration from old firmware with Flash 1:3)

NAMF 2020-6
* SSL/plain connection fixes

NAMF 2020-5
* updating libraries and core to most recent
* SSL seems to be working 

NAMF 2020-4
* forceUpdate - page to force update from custom URL
* provide way to display current config as JSON and upload it later to sensor (/configSave.json)

NAMF 2020-3
* display on webpage first reading from SDS011 (collected on POST)

NAMF 2020-2 (2020-01-25)
* OTA update working

NAMF 2020-1
* Firmware separated from Luftdaten project structure
* New flash layout (2m for code, 2m for SPIFFS). 

