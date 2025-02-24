# Alarm on PM high level

If Your sensor has [NAM SDS restarter](https://nettigo.eu/products/hardware-sds011-restarter-for-nam-0-3) then You can use it
as alarm device. When alarm is triggered then pin state become HIGH (3.3V). You can use this for example to stop
mechanical ventilation in your home when air outside is terrible.

To enable it - enable hardware restarter, select which value should be tracked PM2.5 or PM10 and set threshold value. To avoid
alarm flapping set some hysteresis (5-10% of threshold will be probably ok).
