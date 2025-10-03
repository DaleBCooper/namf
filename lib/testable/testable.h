/*
 * Independent code from hardware suitable for unit testing in 'native' platformio env
 */

//check if given hour is inside range
int hourIsInRange(int hour, int start, int stop);
//calculate switch state with hysteresis
bool alarmState(unsigned threshold, unsigned hysteresis, bool previous, long value);