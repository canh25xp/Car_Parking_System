# A Car Parking System in Arduino

Quick Links:
   - [Microsoft Edge's Workspace](https://aka.ms/edge/workspaceslaunch?code=dHlwZT0xJmlkPWFIUjBjSE02THk5b2IyMWxMbTFwWTNKdmMyOW1kSEJsY25OdmJtRnNZMjl1ZEdWdWRDNWpiMjB2T25VNkwyY3ZZMjl1ZEdWdWRITjBiM0poWjJVdk5rTjZibWxvVGpOMk1IVjVNWHBMTlVaeVVrTmlkMlpsWTJKbFpHTmpOV0kyWldJNU1qZDNiM0pyYzNCaFkyVnpMMGxSU1RaMlNHUnBkbkpvZFZOdmIxTlViM3BIYkRaVFZVRmllRXRKY0dKbFZsRmpXSGhVT1VScFF6aENTSEpKJnN0b3JlPTUmc291cmNlPVdvcmtzcGFjZXMmcmVkZWVtQ29kZT1kdW1teV9zZWVkJmFwcElkR3VpZD1iNmQ4MzNjZi1iNTRlLTRjYWItODE0My0xMzE4ZTBiYzUwZTE%3D&source=Workspaces)
   - [About ESP32-CAM](./Docs/ESP32-CAM/ESP32-CAM.md)
   - [About ESP8266-nodeMCU](./Docs/nodeMCU/nodeMCU.md)
   - [About Arduino Uno R3](./Docs/ArduinoUno/ArduinoUno.md)
   - [About RFID-RC522](./Docs/RFID-RC522/RFID-RC522.md)

Structure of this Project:
```bash
Car_Parking_System
    ├─── ...
    ├───Docs            # Documentations for this project
    ├───Main            # The Main source code files for the projects
    ├───Simulation      # Proteus simulation (not up to date with this project)
    └───Test            # Quick test for various parts
```

## Tools and Requirements
### Hardware
1. Arduino Uno R3 Atmega328P. [3M](https://chotroihn.vn/kit-arduino-uno-r3-atmega328p-cam-k1b3-1-33g)
2. Module ESP32-CAM [Shopee](https://shopee.vn/Module-thu-ph%C3%A1t-wifi-camera-ESP32-CAM-t%C3%ADch-h%E1%BB%A3p-wifi-camera-OV2640-OV7670-chuy%C3%AAn-d%E1%BB%A5ng-v%C3%A0-bluetooth-4-i.16504852.4665567596?sp_atk=18127f02-041a-4b08-a5a2-a6b657db24d3&xptdk=18127f02-041a-4b08-a5a2-a6b657db24d3&is_from_login=true)
3. Module ESP32 Node MCU Luanode32 CP2102 [Shopee](https://shopee.vn/Module-ESP32-Node-MCU-Luanode32-CP2102-i.1048311475.22750978527?sp_atk=987cb89b-c2a9-4f13-8d74-1e85bf019716&xptdk=987cb89b-c2a9-4f13-8d74-1e85bf019716)
4. Module RFID-RC522. [3M](https://chotroihn.vn/module-rfid-rc522-13-56mhz) | [Shopee](https://shopee.vn/Module-RFID-RC522-13.56MHz-i.1048311475.23276547694?sp_atk=302ec86c-8f49-4239-a033-c793717cb7d1&xptdk=302ec86c-8f49-4239-a033-c793717cb7d1)
5. RFID Card FM1108IC. [3M](https://chotroihn.vn/the-rfid-trang-fm1108ic-rc522-13-56mhz-k1a5-1-18g) | [Shopee](https://shopee.vn/Th%E1%BA%BB-RFID-tr%E1%BA%AFng-FM1108IC-RC522-13.56Mhz-gi%E1%BA%A3i-ph%C3%A1p-nh%E1%BA%ADn-di%E1%BB%87n-t%E1%BB%B1-%C4%91%E1%BB%99ng-i.1048311475.22787927981?sp_atk=4c70ab87-60c0-4f02-8a3d-7effe50b5a8f&xptdk=4c70ab87-60c0-4f02-8a3d-7effe50b5a8f)
   - Alternative : ESP8266 NodeMCU Lua V3 CH340 [Shopee](https://shopee.vn/K%C3%ADt-ESP8266-NodeMCU-Lua-V3-CH340-i.16504852.5450769770?sp_atk=608fc654-8cf7-4433-9dfe-d59d97191395&xptdk=608fc654-8cf7-4433-9dfe-d59d97191395)
6. SG90 Servo Motor
7. HC-SR04 Ultrasonic Sensor
8. 16x2 Liquid crystal display
9. I2C LCD1602 module

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
4. Fritzing desktop application. [Download](https://www.filehorse.com/download-fritzing-64/) | [Source code](https://github.com/fritzing/fritzing-app)
5. [arduino-littlefs-upload](https://github.com/earlephilhower/arduino-littlefs-upload/tree/main)

### Arduino core and libraries
1. [Arduino core for the ESP32](https://github.com/espressif/arduino-esp32)
2. [ESP32 Camera Driver](https://github.com/espressif/esp32-camera)
3. [ESP8266 core for Arduino](https://github.com/esp8266/Arduino)
4. [Arduino library for MFRC522](https://github.com/miguelbalboa/rfid)
5. [WebSocket Server and Client for Arduino](https://github.com/Links2004/arduinoWebSockets)
6. [Async Web Server for ESP8266 and ESP32](https://github.com/me-no-dev/ESPAsyncWebServer)
7. [Async TCP Library for ESP8266](https://github.com/me-no-dev/ESPAsyncTCP)
8. [Async TCP Library for ESP32](https://github.com/me-no-dev/AsyncTCP)
9. [Arduino_JSON Library for Arduino](https://github.com/arduino-libraries/Arduino_JSON)

## Documentations and References
1. [Arduino Language References](https://www.arduino.cc/reference/en/)
2. [Arduino-cli documentations](https://arduino.github.io/arduino-cli)

## Helpful sites
1. [Instructables](https://www.instructables.com/)
2. [Alldatasheet](https://www.alldatasheet.com/)
3. [Components101](https://components101.com/)
<!-- 4. [ESP32 Examples and Tutorials](https://techtutorialsx.com/category/esp32/) -->