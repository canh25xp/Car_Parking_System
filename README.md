# A Car Parking System in Arduino

Quick Links:
   - [About ESP32-CAM](./ESP32-CAM/ESP32-CAM.md)
   - [About nodeMCU](./nodeMCU/nodeMCU.md)
   - [About RC522](./RC522/RC522.md)

## Tools and Requirements
### Software
1. [VScode](https://code.visualstudio.com/) and [Arduino extension](https://github.com/microsoft/vscode-arduino)
```sh
winget install Microsoft.VisualStudioCode
code --install-extension vsciot-vscode.vscode-arduino
```
2. Arduino command line tools [arduino-cli](https://github.com/arduino/arduino-cli)
The vscode-arduino already bundled with its own arduino-cli, how ever I prefer using a machine-wise executable :
```sh
winget install ArduinoSA.CLI
```
Config arduino extension `%Appdata%/Code/User/settings.json` :
```json
{
   "arduino.useArduinoCli": true,
   "arduino.path": "C:\\Program Files\\Arduino CLI",
}
```
3. ESP8266 NodeMCU Driver. [Download](https://www.silabs.com/documents/public/software/CP210x_Universal_Windows_Driver.zip) for windows 10 and 11
> Download `CP210x Universal Windows Driver.zip` from [oemdrivers.com](https://oemdrivers.com/rs232-esp8266-nodemcu-ndn) or from [silabs.com](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads). Unzip and install the `silabser.inf` file.
### Hardware
1. Arduino Uno R3 Atmega328P. [3M](https://chotroihn.vn/kit-arduino-uno-r3-atmega328p-cam-k1b3-1-33g)
2. Module ESP32-CAM [Shopee](https://shopee.vn/Module-thu-ph%C3%A1t-wifi-camera-ESP32-CAM-t%C3%ADch-h%E1%BB%A3p-wifi-camera-OV2640-OV7670-chuy%C3%AAn-d%E1%BB%A5ng-v%C3%A0-bluetooth-4-i.16504852.4665567596?sp_atk=18127f02-041a-4b08-a5a2-a6b657db24d3&xptdk=18127f02-041a-4b08-a5a2-a6b657db24d3&is_from_login=true)
   - Alternative : Camera Module OV7670 No FIFO. [3M](https://chotroihn.vn/camera-ov7670-no-fifo) | [Shopee](https://shopee.vn/Camera-OV7670-No-FiFo-tr%C3%ADch-xu%E1%BA%A5t-khung-h%C3%ACnh-th%C3%B4ng-minh-i.1048311475.25102172393?sp_atk=398da750-f7fe-402d-91dd-209c5928edf6&xptdk=398da750-f7fe-402d-91dd-209c5928edf6)
3. Module RFID-RC522. [3M](https://chotroihn.vn/module-rfid-rc522-13-56mhz) | [Shopee](https://shopee.vn/Module-RFID-RC522-13.56MHz-i.1048311475.23276547694?sp_atk=302ec86c-8f49-4239-a033-c793717cb7d1&xptdk=302ec86c-8f49-4239-a033-c793717cb7d1)
4. RFID Card FM1108IC. [3M](https://chotroihn.vn/the-rfid-trang-fm1108ic-rc522-13-56mhz-k1a5-1-18g) | [Shopee](https://shopee.vn/Th%E1%BA%BB-RFID-tr%E1%BA%AFng-FM1108IC-RC522-13.56Mhz-gi%E1%BA%A3i-ph%C3%A1p-nh%E1%BA%ADn-di%E1%BB%87n-t%E1%BB%B1-%C4%91%E1%BB%99ng-i.1048311475.22787927981?sp_atk=4c70ab87-60c0-4f02-8a3d-7effe50b5a8f&xptdk=4c70ab87-60c0-4f02-8a3d-7effe50b5a8f)
5. Module ESP32 Node MCU Luanode32 CP2102 [Shopee](https://shopee.vn/Module-ESP32-Node-MCU-Luanode32-CP2102-i.1048311475.22750978527?sp_atk=987cb89b-c2a9-4f13-8d74-1e85bf019716&xptdk=987cb89b-c2a9-4f13-8d74-1e85bf019716)
   - Alternative : ESP8266 NodeMCU Lua V3 CH340 [Shopee](https://shopee.vn/K%C3%ADt-ESP8266-NodeMCU-Lua-V3-CH340-i.16504852.5450769770?sp_atk=608fc654-8cf7-4433-9dfe-d59d97191395&xptdk=608fc654-8cf7-4433-9dfe-d59d97191395)

### Miscellaneous
1. [Arduino library for MFRC522](https://github.com/miguelbalboa/rfid)
2. [Arduino core for the ESP32](https://github.com/espressif/arduino-esp32)
3. [ESP32 Camera Driver](https://github.com/espressif/esp32-camera)
4. [ESP8266 core for Arduino](https://github.com/esp8266/Arduino)

## Documentations and References
1. [Arduino Language References](https://www.arduino.cc/reference/en/)
2. [Arduino UNO R3 datasheet](./Docs/A000066-datasheet.pdf)
3. [Arduino-cli documentations](https://arduino.github.io/arduino-cli)

## Helpful
1. [Instructables](https://www.instructables.com/)
2. [Alldatasheet](https://www.alldatasheet.com/)
3. [Components101](https://components101.com/)
<!-- 4. [ESP32 Examples and Tutorials](https://techtutorialsx.com/category/esp32/) -->