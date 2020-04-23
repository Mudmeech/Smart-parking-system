String RfidRead(){
  
#define SS_PIN 5
#define RST_PIN 22

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

  String none;
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return none;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return none;
  }
  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  
  strID.toUpperCase();
  
  
  // เมื่อถึงส่วนนี้ ตัวแปร strID จะเก็บค่า UID ของแท็กไว้แล้ว
  // สามารถนำไปใช้งานได้เลย เช่น นำไปเข้า IF เพื่อให้หลอด
  // LED ติดสว่าง หรือดับได้
  //Serial.print("Tap card key: ");
  //Serial.println(strID);
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  
  return strID;

}