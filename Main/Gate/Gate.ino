#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#include "Barrier.h" // Handle the servo 

// Set the LCD number of columns and rows
#define LCD_COLS        16
#define LCD_ROWS        2

// Pins connections
#define LCD_SDA         SDA     // D2
#define LCD_SCL         SCL     // D1

#define RFID_RST_PIN    D4
#define RFID_SDA_PIN    SS      // D8
#define RFID_SCK_PIN    SCK     // D5
#define RFID_MOSI_PIN   MOSI    // D7
#define RFID_MISO_PIN   MISO    // D6

#define SERVO_PIN       D3

// Create LCD instance
LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);

// Create RFID instance
MFRC522 rfid(RFID_SDA_PIN, RFID_RST_PIN);

// Create Servo instance
Barrier barrier(SERVO_PIN);

void setup() {
    // Initialize Serial Communication
    Serial.begin(9600);

    // Test the servo (Sweep from 0 to 180 degree)
    barrier.Test();

    // Initialize LCD
    lcd.init();
    lcd.backlight();
    Test_LCD();

    // Initialize SPI bus
    SPI.begin();

    // Initialize MFRC522 RFID
    rfid.PCD_Init();

    Serial.println();
    Serial.println("Approximate your card to the reader...");
}

void loop() {
    // Look for new cards
    if (!rfid.PICC_IsNewCardPresent()) {
        return;
    }
    // Select one of the cards
    if (!rfid.PICC_ReadCardSerial()) {
        return;
    }

    String UID = RFID_GetUID();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(UID);
}

String RFID_GetUID() {
    String content = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
        content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(rfid.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    return content.substring(1);
}

void Test_LCD() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PARKING SYSTEM");
    lcd.setCursor(0, 1);
    lcd.print("HUST PRODUCTION");
    delay(1000);
}