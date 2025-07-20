//433Mhz TRANSMITTER CODE
// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h> //instal this library from the link http://www.airspayce.com/mikem/arduino/RadioHead/RadioHead-1.121.zip
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
{
    // Initialize ASK Object
    rf_driver.init();
}
 
void loop()
{
    const char *msg = "Mazda Axela"; //Keep count of number of words plus spaces to indicate on receiver code.
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
}