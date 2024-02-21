#include <SPI.h>
#include <MFRC522.h>

const int ledPin = D4; // The built-in led on the nodeMCU board

#define RST_PIN         D3
#define SS_PIN          D8

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup() {
    Serial.begin(9600);     // Initiate a serial communication
    SPI.begin();            // Initiate  SPI bus
    mfrc522.PCD_Init();     // Initiate MFRC522
    delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
    Serial.println("Approximate your card to the reader...");
    Serial.println();
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Look for new cards
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }
    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }
    //Show UID on serial monitor
    Serial.print("UID tag :");
    String content = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message : ");
    content.toUpperCase();
    if (content.substring(1) == "84 4F D7 DE") { //change here the UID of the card/cards that you want to give access
        Serial.println("Authorized access");
        Serial.println();
        digitalWrite(ledPin, LOW);
        delay(3000);
    }

    else {
        Serial.println(" Access denied");
        digitalWrite(ledPin, HIGH);
        delay(3000);
    }
}