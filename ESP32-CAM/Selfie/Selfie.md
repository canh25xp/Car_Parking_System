# ESP32-CAM taking selfie
> Borrowing from [RandomNerdTutorials](https://RandomNerdTutorials.com/esp32-cam-take-photo-save-microsd-card)
## What does it do ?
This sketch taking photos with the ESP32-CAM and save it to MicroSD card.

## How does it work ?
When you press the reset button, it wakes up, takes a photo, saves it in the microSD card and go back to sleep mode.

IMPORTANT :
- Select Board "AI Thinker ESP32-CAM"
- GPIO 0 must be connected to GND to upload a sketch
- After connecting GPIO 0 to GND, press the ESP32-CAM on-board RESET button to put your board in flashing mode
## 