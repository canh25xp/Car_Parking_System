#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>


// set the LCD number of columns and rows
#define LCD_COLS        16
#define LCD_ROWS        2

// Pins definition
#define RFID_RST_PIN    D4
#define RFID_SDA_PIN    SS      // D8
#define RFID_SCK_PIN    SCK     // D5
#define RFID_MOSI_PIN   MOSI    // D7
#define RFID_MISO_PIN   MISO    // D6

#define SERVO_PIN       D3

// Create LCD instance
LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);

// Create MFRC522 instance.
MFRC522 mfrc522(RFID_SDA_PIN, RFID_RST_PIN);

// Create Servo instance
Servo servo;

void setup() {
    // Initialize Serial Communication
    Serial.begin(9600);

    // Initialize servo
    servo.attach(SERVO_PIN, 500, 2400); // The nodeMCU need to config the min and max value
    ServoTest();

    // Initialize LCD
    lcd.init();
    lcd.backlight();

    // Initialize SPI bus
    SPI.begin();

    // Initialize MFRC522 RFID
    mfrc522.PCD_Init();


    Serial.println();
    Serial.println("Approximate your card to the reader...");
}

void loop() {
    // set cursor to first column, first row
    lcd.setCursor(0, 0);
    // print message
    lcd.print("Close");
    ServoClose();
    servo.write(0);
    delay(1000);
    // clears the display to print new message
    lcd.clear();
    // set cursor to first column, second row
    lcd.setCursor(0, 1);
    lcd.print("Open");
    ServoOpen();
    servo.write(90);
    delay(1000);
    lcd.clear();
}

void ServoTest() {
    for (int i = 0; i <= 180; i++) {
        servo.write(i);
        delay(10);
    }
}

void ServoClose() {
    servo.write(0);
}

void ServoOpen() {
    servo.write(90);
}