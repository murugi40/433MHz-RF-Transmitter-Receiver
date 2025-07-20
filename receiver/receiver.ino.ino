//433Mhz RECEIVER CODE
// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h> //instal this library from the link http://www.airspayce.com/mikem/arduino/RadioHead/RadioHead-1.121.zip
// Include dependant SPI Library
#include <SPI.h>

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup() {
  // Initialize ASK Object
  rf_driver.init();
  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Set buffer to size of expected message
  uint8_t buf[11];
  uint8_t buflen = sizeof(buf);
  // Check if received packet is correct size
  if (rf_driver.recv(buf, &buflen)) {

    // Message received with valid checksum
    Serial.print("Message Received: ");
    Serial.println((char*)buf);

    // Check if the received message contains "Hell"
    if (strstr((char*)buf, "Hell") != NULL) {
      Serial.println("Yes");
    } else {
      Serial.println("No");
    }
  }
}