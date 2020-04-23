#include <HTTPClient.h>
#include <WiFi.h>
#include <Servo.h>
#include <SPI.h>
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include "infar.h"
#include "rfid.h"
#include "servo.h"
#include "Post.h"

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

const char* ssid = "MOOK1532_2.4G";
const char* password =  "22042204";

void setup() {
  // put your setup code here, to run once:
  //infar
  pinMode(Infar_1, INPUT);
  pinMode(Infar_2, INPUT);
  pinMode(Infar_3, INPUT);
  pinMode(Infar_4, INPUT);
  pinMode(Infar_5, INPUT);
  pinMode(Infar_6, INPUT);
  Serial.begin(9600);
  //rfid
  SPI.begin();
  rfid.PCD_Init();
  servo_setup();
  //wifi
  WiFi.begin(ssid, password);

}

String tag = "";
int car_spot =0;
 
void loop() {
 
 
 car_spot =0;
 tag = RfidRead();
 //Serial.println ("main loop");
 //Serial.println (tag);
 String reserve_slot = Post_Rfid(tag);
 //Serial.print(reserve_slot);

 if (reserve_slot.toInt()>0){
    car_spot = reserve_slot.toInt();
  }
 
 if( car_spot > 0){
  //Serial.println(car_spot);
  Serial.println("Open gate " + String(car_spot));
  servo_open(car_spot);
  delay(7000);
 }
 Slot_status();
}


void Slot_status () {
  if(infar(1)==1 && infar_old1 ==0 ){
    Serial.println("Car 1 out");
    delay(5000);
    servo_close(1);
    Post_OutSlot(1);
    } 
    //else {Serial.println("Car 1 in");}
  infar_old1 = infar(1);
  
  if(infar(2)==1 && infar_old2 ==0 ){
    Serial.println("Car 2 out");
    delay(5000);
    servo_close(2);
    Post_OutSlot(2);
    } 
    //else {Serial.println("Car 2 in");}
  infar_old2 = infar(2);
  
 if(infar(3)==1 && infar_old3 ==0 ){
    Serial.println("Car 3 out");
    delay(5000);
    servo_close(3);
    Post_OutSlot(3);
    } 
    //else {Serial.println("Car 3 in");}
 infar_old3 = infar(3);
 
 if(infar(4)==1 && infar_old4==0 ){
    Serial.println("Car 4 out");
    delay(5000);
    servo_close(4);
    Post_OutSlot(4);
    } 
    //else {Serial.println("Car 4 in");}
 infar_old4 = infar(4);
 
 if(infar(5)==1 && infar_old5 ==0){
    Serial.println("Car 5 out");
    delay(5000);
    servo_close(5);
    Post_OutSlot(5);
    } 
    //else {Serial.println("Car 5 in");}
 infar_old5 = infar(5);

 if(infar(6)==1 && infar_old6 ==0 ){
    Serial.println("Car 6 out");
    delay(5000);
    servo_close(6);
    Post_OutSlot(6);
    } 
    //else {Serial.println("Car 6 in");}
 infar_old6 = infar(6);
}
