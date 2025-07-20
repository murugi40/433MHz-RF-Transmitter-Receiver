# 433MHz RF Transmitter and Receiver using Arduino

This project demonstrates how to use 433MHz RF modules for wireless communication between two Arduino boards. It uses the RadioHead ASK library to implement Amplitude Shift Keying (ASK) data transmission and reception.

## 📡 Project Overview

* **Transmitter**: Sends a predefined message every second.
* **Receiver**: Listens for incoming messages, prints them on the Serial Monitor, and checks for specific content.

The system is useful for simple wireless control, sensor data transmission, or basic signaling over short distances.

---

## 🔧 Hardware Requirements

| Component             | Quantity |
| --------------------- | -------- |
| Arduino Uno/Nano/MEGA | 2        |
| 433MHz RF Transmitter | 1        |
| 433MHz RF Receiver    | 1        |
| Breadboard            | 1        |
| Jumper wires          | Several  |

---

## 📦 Library Dependency

This project uses the [RadioHead Library](http://www.airspayce.com/mikem/arduino/RadioHead/):

* Download: [RadioHead v1.121 ZIP](http://www.airspayce.com/mikem/arduino/RadioHead/RadioHead-1.121.zip)
* Install via Arduino IDE:

  * `Sketch → Include Library → Add .ZIP Library`

---

## 📝 Transmitter Code

```cpp
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

void setup() {
    rf_driver.init();
}

void loop() {
    const char *msg = "Mazda Axela";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
}
```

---

## 📝 Receiver Code

```cpp
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

void setup() {
    rf_driver.init();
    Serial.begin(9600);
}

void loop() {
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    if (rf_driver.recv(buf, &buflen)) {
        Serial.print("Message Received: ");
        Serial.println((char*)buf);

        if (strstr((char*)buf, "Hell") != NULL) {
            Serial.println("Yes");
        } else {
            Serial.println("No");
        }
    }
}
```

---

## 🖇️ Wiring Overview

### Transmitter

* VCC → 5V
* GND → GND
* DATA → D12 (default in RadioHead)

### Receiver

* VCC → 5V
* GND → GND
* DATA → D11 (default in RadioHead)

*(You may need to experiment with pins or use software SPI depending on board.)*

---

## 📟 Serial Monitor Output

```
Message Received: Mazda Axela
No
Message Received: Hello
Yes
```

---

## 📁 Repository Structure

```
433MHz-RF-Transmitter-Receiver/
├── transmitter/
│   └── transmitter.ino
├── receiver/
│   └── receiver.ino
└── README.md
```

---

## 🧪 How to Test

1. Flash `transmitter.ino` to the first Arduino.
2. Flash `receiver.ino` to the second Arduino.
3. Power both systems and open Serial Monitor on the receiver.
4. Observe messages being received once per second.

---

## 📌 Notes

* Typical range: 5–30 meters depending on environment and antenna.
* For best results, use antennas (\~17 cm wire) on both transmitter and receiver.
* Ensure no pin conflicts with other libraries/hardware on your board.

---

> *Simple RF communication is a great foundation for building remote control systems, wireless sensors, and more.*
