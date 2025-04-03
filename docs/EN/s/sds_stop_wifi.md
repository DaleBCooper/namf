# SDS011 and WiFi

ESP8266 (used in NAM 0.3) has its limitations. Communication with SDS011 is done via SoftwareSerial. This communication is very prone to any delays in 
software. When you check datasheet for ESP8266 you can read that for user program is available 80% of CPU power. What with remaining 20%?
It is being used to implement WiFi stack. That means, even if our software _does nothing_ there can be some operation related to
WiFi connectivity done in background.

We have seen that despite our efforts SoftwareSerial communication suffers when WiFi is enabled. So, since NAMF-47 software is
disabling WiFi for few seconds when collecting data from SDS011. Stop time is about SDS011 _measurement time_ + ~2 seconds for reconnect.  During this time sensor is not accessible via WiFi.

Feature is enabled by default, but you can restore old behavior (being all the time on-line).
