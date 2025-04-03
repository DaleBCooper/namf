# SDS011 a WiFi

ESP8266, który jest używany w NAM 0.3 ma swoje ograniczenia. Dlatego do komunikacji z SDS011 używany jest oprogramowanie SoftwareSerial.
Jest ono bardzo podatne na ewentualne opóźnienia po stronie ESP8266. Gdy sprawdzisz kartę katalogową ESP8266 możesz przeczytać,
że dla programów użytkownika przeznaczone jest ok 80% mocy procesora. Co z pozostałymi 20%? Są one używane do obsługi stosu WiFi.
To znaczy, że jeżeli nawet nasz program _nic nie robi_ procesor może być chwilowo zajęty.

Zauważyliśmy, że mimo naszych licznych prób zaradzeniu temu, przy włączonym WiFi komunikacja z SDS011 jest zawodna. Dlatego od NAMF-47, kiedy dokonywany jest
pomiar przez SDS011 sensor wyłącza WiFi. Czas zatrzymania to mniej więcej _czas w jakim jest dokonywany pomiar_ + ~2 sekundy na ponowne połączenie. W tym czasie sensor
nie jest dostępny online.

To jest domyślne zachowanie, ale możesz wyłączyć to (zostawiając sensor cały czas on-line)
