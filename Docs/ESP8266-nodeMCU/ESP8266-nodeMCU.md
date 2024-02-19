# NodeMCU ESP8266

## Notes
### GPIO6-11
> https://arduino.stackexchange.com/a/66477

The ESP8266 uses an external flash memory chip to store your program. It communicates with this flash chip over a 4 bit SDIO interface, on GPIO6-11. These pins are labeled SDDn, SDCLK and SDCMD.

Usually, the interface uses all 4 data lines (QIO), but you can also configure it to use only 2 of the 4 lines (DIO), giving you access to two more GPIO pins (9 & 10).

The reserved pins are not mentioned in the schematic. They cannot be IO pins, because there simply are no other pins on the ESP8266/ESP-12. It could be pins connected to the USB chip, connected to power lines, or not connected at all. The designers probably wanted to allow for extra pins on next iterations of the board, without changing the form factor. A quick search online didn't yield any results, so your best bet is to trace the connection on the PCB, or measure it with a multimeter. You probably shouldn't be using them anyway, because they are "reserved".

## Documents and References
- [NodeMCU documenation](https://nodemcu.readthedocs.io/)
- [NodeMCU firmware](https://github.com/nodemcu/nodemcu-firmware)
- [NodeMCU datasheet](https://components101.com/development-boards/nodemcu-esp8266-pinout-features-and-datasheet)

## Tutorials
- [Installing ESP8266 NodeMCU Board in Arduino IDE 2.0 (Windows, Mac OS X, Linux)](https://randomnerdtutorials.com/installing-esp8266-nodemcu-arduino-ide-2-0/)
- [Getting Started with ESP8266 NodeMCU Development Board](https://randomnerdtutorials.com/getting-started-with-esp8266-wifi-transceiver-review/)
- [ESP8266 Pinout Reference: Which GPIO pins should you use?](https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/)