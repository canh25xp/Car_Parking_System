# Notes about the nodeMCU

## [About two version of the NodeMCU](https://arduino.stackexchange.com/questions/54640/difference-between-these-two-nodemcu-boards)



## [GPIO6-11 on the NodeMCU](https://arduino.stackexchange.com/a/66477)

The ESP8266 uses an external flash memory chip to store your program. It communicates with this flash chip over a 4 bit SDIO interface, on GPIO6-11. These pins are labeled SDDn, SDCLK and SDCMD.

Usually, the interface uses all 4 data lines (QIO), but you can also configure it to use only 2 of the 4 lines (DIO), giving you access to two more GPIO pins (9 & 10).

The reserved pins are not mentioned in the schematic. They cannot be IO pins, because there simply are no other pins on the ESP8266/ESP-12. It could be pins connected to the USB chip, connected to power lines, or not connected at all. The designers probably wanted to allow for extra pins on next iterations of the board, without changing the form factor. A quick search online didn't yield any results, so your best bet is to trace the connection on the PCB, or measure it with a multimeter. You probably shouldn't be using them anyway, because they are "reserved".
