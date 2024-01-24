# A Car Parking System in Arduino

## Tools and Requirements
### Software
1. Arduino command line tools [arduino-cli](https://github.com/arduino/arduino-cli)
```sh
winget install ArduinoSA.CLI
```
2. IDE [VScode](https://code.visualstudio.com/) and [Arduino extension](https://github.com/microsoft/vscode-arduino)
```sh
winget install Microsoft.VisualStudioCode
code --install-extension vsciot-vscode.vscode-arduino
```
3. ESP8266 NodeMCU Driver. [Download](https://www.silabs.com/documents/public/software/CP210x_Universal_Windows_Driver.zip) for windows 10 and 11
> Download `CP210x Universal Windows Driver.zip` from [oemdrivers.com](https://oemdrivers.com/rs232-esp8266-nodemcu-ndn) or from [silabs.com](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads). Unzip and install the `silabser.inf` file.
### Hardware
1. Arduino Uno R3 Atmega328P. [buy link](https://chotroihn.vn/kit-arduino-uno-r3-atmega328p-cam-k1b3-1-33g)
2. Camera Module OV7670 CMOS VGA. [buy link](https://chotroihn.vn/camera-ov7670-no-fifo)
3. Module RFID-RC522. [buy link](https://chotroihn.vn/module-rfid-rc522-13-56mhz) 

## Documentations and References
1. [arduino-cli documentations](https://arduino.github.io/arduino-cli)
2. [How to Use OV7670](https://circuitdigest.com/microcontroller-projects/how-to-use-ov7670-camera-module-with-arduino)