#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>


// set the LCD number of columns and rows
#define LCDCOLUMNS 16
#define LCDROWS 2

// Pins definition
#define RST_PIN         D4
#define SS_PIN          D8
#define SERVO_PIN       D3

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, LCDCOLUMNS, LCDROWS);

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

Servo barrie;  // create servo object to control a servo

void setup() {
    Serial.begin(9600);   // Initiate a serial communication

    barrie.attach(SERVO_PIN);  // attaches the servo on GIO2 to the servo object

    // initialize LCD
    lcd.init();
    lcd.backlight(); // turn on LCD backlight


    SPI.begin();      // Initiate  SPI bus
    mfrc522.PCD_Init();   // Initiate MFRC522
    Serial.println("Approximate your card to the reader...");
    Serial.println();

    TestServo(barrie);
}

void loop() {
    // set cursor to first column, first row
    lcd.setCursor(0, 0);
    // print message
    lcd.print("Hello, World!");
    Close(barrie);
    delay(1000);
    // clears the display to print new message
    lcd.clear();
    // set cursor to first column, second row
    lcd.setCursor(0, 1);
    lcd.print("Hello, World!");
    delay(1000);
    Open(barrie);
    lcd.clear();
}

void TestServo(Servo _servo) {
    for (int i = 0; i <= 180; i++) {
        _servo.write(i);
        delay(10);
    }
}

void Close(Servo _servo) {
    _servo.write(0);
}

void Open(Servo _servo) {
    _servo.write(90);
}