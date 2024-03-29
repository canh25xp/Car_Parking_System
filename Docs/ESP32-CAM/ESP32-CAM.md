# Module ESP32-CAM + OV2640 + ESP32-CAM-MB USB Programmer

<!-- |    ESP32-CAM + OV2640 + ESP32-CAM-MB     |         ESP32-CAM + OV2640         |
| :--------------------------------------: | :--------------------------------: |
| ![](./ESP32-CAM+ESP32-CAM-MB+OV2640.jpg) | ![](./ESP32-CAM-Camera-Module.jpg) | -->

![](./ESP32-CAM+ESP32-CAM-MB+OV2640.jpg) ![](./ESP32-CAM-Camera-Module.jpg)

## Specification
> [Datasheet](./ESP32-CAM_datasheet.pdf) | [Schematic](./ESP32_CAM_Schematic.pdf)

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

## Pinout

![Alt text](./ESP32-CAM-Pinout.jpg)

### Flashlight (GPIO 4)

That GPIO is also connected to the microSD card slot, so you may have troubles when trying to use both at the same time – the flashlight will light up when using the microSD card.

Workaround: this works and that the LED will not make that flash effect. However, the LED remains on with low brightness (not sure why).
```cpp
SD_MMC.begin("/sdcard", true);
```

### Built-in Red LED (GPIO 33)
The LED is active low.

### Camera pins connections 

OV2640 CAMERA|ESP32|Variable name in code
-|-|-
D0|GPIO 5|Y2_GPIO_NUM
D1|GPIO 18|Y3_GPIO_NUM
D2|GPIO 19|Y4_GPIO_NUM
D3|GPIO 21|Y5_GPIO_NUM
D4|GPIO 36|Y6_GPIO_NUM
D5|GPIO 39|Y7_GPIO_NUM
D6|GPIO 34|Y8_GPIO_NUM
D7|GPIO 35|Y9_GPIO_NUM
XCLK|GPIO 0|XCLK_GPIO_NUM
PCLK|GPIO 22|PCLK_GPIO_NUM
VSYNC|GPIO 25|VSYNC_GPIO_NUM
HREF|GPIO 23|HREF_GPIO_NUM
SDA|GPIO 26|SIOD_GPIO_NUM
SCL|GPIO 27|SIOC_GPIO_NUM
POWER PIN|GPIO 32|PWDN_GPIO_NUM

### MicroSD Card Connections

MicroSD card|ESP32
-|-
CLK|GPIO 14
CMD|GPIO 15
DATA0|GPIO 2
DATA1 / flashlight|GPIO 4
DATA2|GPIO 12
DATA3|GPIO 13

## Programmer
There're several ways to upload the code to the ESP32-CAM board : 
- Using an FTDI programmer
- Using ESP32-CAM-MB USB Programmer (The easier one and the one we use)

### FTDI programmer
ESP32-CAM|FTDI Programmer
-|-
GND|GND
5V|VCC (5V)
U0R|TX
U0T|RX
GPIO 0|GND

**Important**: GPIO 0 needs to be connected to able to upload code.

![](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/12/ESP32-CAM-FTDI-programmer-5V-supply.png)

### ESP32-CAM-MB USB Programmer
The ESP32-CAM-MB uses a CH340G USB-to-UART chip and has it wired to RX and TX pins, meaning it is suitable to program any ESP32 chip, not only the ESP32-CAM board.

![](https://www.espboards.dev/img/wpCj00LXoP-600.avif) ![](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/01/ESP32-CAM-MB-Micro-USB-Programmer-CH340G-Serial-Chip-OV2640-Camera.jpg)

The pins marked as green are connected and ready for use, while the ones marked as red are not connected.
## Driver and Framework
- https://github.com/espressif/esp32-camera
- https://github.com/yoursunny/esp32cam
- https://github.com/easytarget/esp32-cam-webserver
- https://github.com/RuiSantosdotme/ESP32-CAM-Arduino-IDE
- https://github.com/espressif/esp-idf

## Documentations and References
- ESP32 datasheet [Downloaded](./esp32_datasheet_en.pdf)
- ESP32-CAM datasheet [Downloaded](./ESP32-CAM_datasheet.pdf) | [Source](https://components101.com/modules/esp32-cam-camera-module)
- [ESP32 Arduino Core’s documentation](https://docs.espressif.com/projects/arduino-esp32)
- [ESP8266 Forum](https://www.esp8266.com/)
- [ESP-IDF Documentations](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)

## Tutorials
- [Getting started with the ESP32-CAM (Article)](https://dronebotworkshop.com/esp32-cam-intro/) | [Youtube](https://www.youtube.com/watch?v=visj0KE5VtY)
- [How to setup and use ESP32 Cam with Micro USB WiFi Camera](https://www.youtube.com/watch?v=RCtVxZnjPmY)
- [RandomNerd's Tutorial (Artical)](https://randomnerdtutorials.com/esp32-cam-video-streaming-web-server-camera-home-assistant/) | [Youtube](https://www.youtube.com/watch?v=36p9To2hfak)
- [ESP32-Cam Complete Guide](https://www.youtube.com/watch?v=hSr557hppwY)
- [ESP32-CAM - Guide to making YOUR first DIY Security Camera](https://www.youtube.com/watch?v=k_PJLkfqDuI&t=473s)
- [ESP32-Cam Quickstart with Arduino Code](https://www.youtube.com/watch?v=Sb08leLWOgA)
- [Cheap Wi-Fi IP Surveillance Camera (Very little DIY needed)](https://www.youtube.com/watch?v=MKiITEsOwRA)
- [Upload Code to ESP32-CAM AI-Thinker using ESP32-CAM-MB USB Programmer (easiest way)](https://randomnerdtutorials.com/upload-code-esp32-cam-mb-usb/)
- [Using the ESP32-CAM-MB programmer to flash any ESP32 board](https://www.espboards.dev/blog/flash-any-esp32-with-esp32-cam-mb/)
- [ESP32-CAM AI-Thinker Pinout Guide: GPIOs Usage Explained](https://randomnerdtutorials.com/esp32-cam-ai-thinker-pinout/)
- [ESP32 Pinout Reference](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/)
- [ESP32 SPI Communication: Set Pins, Multiple SPI Bus Interfaces, and Peripherals (Arduino IDE)](https://randomnerdtutorials.com/esp32-spi-communication-arduino/)