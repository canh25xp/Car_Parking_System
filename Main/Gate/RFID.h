#include <MFRC522.h>

String RFID_GetUID(const MFRC522& rfid) {
    String content = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
        content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(rfid.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    return content.substring(1);
}