# ESP32-CAM taking selfie
> borrowed from [RandomNerdTutorials](https://RandomNerdTutorials.com/esp32-cam-take-photo-save-microsd-card)
## What does it do ?
This sketch taking photos with the ESP32-CAM and save it to MicroSD card.

## How does it work ?
When you press the reset button, it wakes up, takes a photo, saves it in the microSD card and go back to sleep mode.

IMPORTANT :
- Select Board "AI Thinker ESP32-CAM"
- GPIO 0 must be connected to GND to upload a sketch
- After connecting GPIO 0 to GND, press the ESP32-CAM on-board RESET button to put your board in flashing mode
## Demo
Serial Output
```
---- Opened the serial port COM15 ----
ets Jul 29 2019 12:21:46

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0030,len:1344
load:0x40078000,len:13964
load:0x40080400,len:3600
entry 0x400805f0
Found PSRAM
Starting SD Card
Picture file name: /picture17.jpg
Saved file to path: /picture17.jpg
Going to sleep now
---- Closed the serial port COM15 ----
```

## Troubleshooting : common problems
> https://randomnerdtutorials.com/esp32-cam-troubleshooting-guide/