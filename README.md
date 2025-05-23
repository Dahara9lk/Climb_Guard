# ClimbGuard - IoT Smart Climbing Glove
Second Year IOT project
ClimbGuard is an IoT-based wearable glove designed to ensure the safety of high-altitude mountain climbers. It monitors health vitals and environmental conditions, enables offline communication, and supports emergency alerting even in the absence of internet or cellular coverage.

## Project Overview

- **Real-time health monitoring** (SpO2, heart rate)
- **Environmental sensing** (altitude, temperature, humidity)
- **Offline communication** (LoRa and ESP-NOW)
- **Emergency alerts** (fall detection, SOS messaging)
- **Live feedback** (OLED display)
- **GPS tracking**
- **Optional mobile app for data visualization and cloud sync**

## Hardware Components

| Component              | Purpose                                |
|------------------------|----------------------------------------|
| ESP32                  | Main microcontroller with Wi-Fi/BLE    |
| MAX30102               | SpO2 and heart rate sensor             |
| BME280                 | Altitude, temperature, humidity sensor |
| NEO-6M GPS             | GPS module                             |
| MPU6050                | Fall detection (accelerometer/gyro)    |
| LoRa SX1278            | Long-range communication               |
| OLED Display (SSD1306) | Real-time vitals feedback              |
| Buzzer + LED           | Emergency alerts                       |
| MicroSD Module         | Local data storage                     |

## Circuit Overview

### I2C Devices (SDA: GPIO 21, SCL: GPIO 22)
- MAX30102
- BME280
- MPU6050
- OLED SSD1306

### UART (TX: GPIO 16, RX: GPIO 17)
- NEO-6M GPS

### SPI (SCK: GPIO 18, MOSI: GPIO 23, MISO: GPIO 19, CS: GPIO 5)
- LoRa SX1278
- MicroSD Card Module

### Digital IO
- Buzzer: GPIO 25
- LED: GPIO 26

## Power Supply

- 3.7V Li-ion battery with voltage regulator (3.3V for ESP32 and sensors)
- Optional: solar panel for charging

## Mobile App (Optional)

- Bluetooth or Wi-Fi syncing
- Historical data logs
- Charts and notifications




