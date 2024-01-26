# Module ESP32-CAM + OV2640

![ESP32-CAM](ESP32-CAM-Camera-Module.jpg)

The ESP32-CAM is a small-size, low-power camera module based on ESP32. It comes with an OV2640 camera and provides an onboard TF card slot. This board has 4MB PSRAM which is used for buffering images from the camera into video streaming or other tasks and allows you to use higher quality in your pictures without crashing the ESP32. It also comes with an onboard LED for flash and several GPIOs to connect peripherals.

## Specification
> [Datasheet](./ESP32-CAM_datasheet.pdf)

Name | Value
-|-
Package | DIP 16
Dimensions | 27 x 40,5 x 4,5 (mm x mm x mm)
RAM | 520KB Internal + 2M PSRAM External
Bluetooth Standard | Bluetooth 4.2BR / EDR and BLE
Wifi Standard | IEEE 802.11 b/g/n/e/i
Peripheral interface | UART, SPI, I2C, PWM
External memory | Maximum 4G
IO pins | 9
UART baudrate rate | default 115200 bps
Output image format | JPEG, BMP, GRAYSCALE
Operating frequency | 2412 ~ 2484 MHz
Antenna | Onboard PCB antenna
SPI Flash | 32Mbit
Security | WPA/WPA2/WPA2-Enterprise/WPS
Transmitting power | 802.11b: 17 ±2dBm(@11Mbps)<br>802.11g: 14 ±2dBm(@54Mbps)<br>802.11n: 13 ±2dBm(@HT20,MCS7)
Reception sensitivity | CCK,1Mbps: -90 dBm <br>CCK,11Mbps: -85 dBm<br>6Mbps(1/2 BPSK): -88 dBm<br>54Mbps(3/4 64-QAM): -70 dBm<br>HT20,MCS7(65Mbps, 72.2Mbps): -67 dBm
Power consumption |  Flash off: 180mA@5V<br> Flash on and brightness max: 310mA@5V<br> Deep-Sleep: > 6mA@5V<br> Modern-Sleep: > 20mA@5V<br> Light-Sleep: > 6.7mA@5V

## Pinout Diagram

![Alt text](ESP32-CAM-Pinout.jpg)

## Driver

https://github.com/espressif/esp32-camera

## Documents and References
- https://components101.com/modules/esp32-cam-camera-module
- Dronebotworkshop's Tutorial [Article](https://dronebotworkshop.com/esp32-cam-intro/) | [Youtube](https://www.youtube.com/watch?v=visj0KE5VtY)
- How to setup and use ESP32 Cam with Micro USB WiFi Camera [Youtube](https://www.youtube.com/watch?v=RCtVxZnjPmY)
- RandomNerd's Tutorial [Artical](https://randomnerdtutorials.com/esp32-cam-video-streaming-web-server-camera-home-assistant/) | [Youtube](https://www.youtube.com/watch?v=36p9To2hfak)
- https://www.youtube.com/watch?v=hSr557hppwY
- https://www.youtube.com/watch?v=k_PJLkfqDuI&t=473s
- https://www.youtube.com/watch?v=Sb08leLWOgA
- https://www.youtube.com/watch?v=MKiITEsOwRA