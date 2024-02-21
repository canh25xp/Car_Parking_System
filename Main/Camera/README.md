# WifiCam: WiFi camera HTTP server
> Borrow from [yoursunny/esp32cam](https://github.com/yoursunny/esp32cam/blob/main/examples/WifiCam)

This example runs on ESP32-CAM board.
It provides an HTTP server where you can access BMP, JPG, and MJPEG formats in various resolutions.
To use this example, modify WiFi SSID+password, then upload to ESP32.

ESP32 `WebServer` can only serve one TCP connection at a time.
If you have accessed an MJPEG stream in a browser, you need to click *Stop* button to terminate the connection.
Otherwise, you won't be able to open another page or picture.

Due to memory constraints, it's not recommended to access BMP format in high resolution.

## Library Download
```bash
arduino-cli config set library.enable_unsafe_install true # Enable the use of the --git-url and --zip-file
arduino-cli lib install --git-url https://github.com/yoursunny/esp32cam
```