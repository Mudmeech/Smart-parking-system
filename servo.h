
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;
Servo servo_6;

void servo_setup () {

  //ฝั่งติดประตู
  servo_1.attach(26);//(32);
  servo_2.attach(4);//(33);
  servo_3.attach(15);//(25);
  
 ///ฝั่งหลัง
  servo_4.attach(32);//(26);
  servo_5.attach(33);//(4);
  servo_6.attach(25);//(15);
  
}

void servo_close(int Num){
  //close
  if(Num == 1){
  servo_1.write(90);
  delay(500);
  }
  if(Num == 2){
  servo_2.write(90);
  delay(500);
  }
  if(Num == 3){
  servo_3.write(90);
  delay(500);
  }
  if(Num == 4){
  servo_4.write(90);
  delay(500);
  }
  if(Num == 5){
  servo_5.write(90);
  delay(500);
  }
  if(Num == 6){
  servo_6.write(90);
  delay(500);
  }
}

void servo_open(int Num){
  //open
  if(Num == 1){
  servo_1.write(0);
  delay(500);
  }
  if(Num == 2){
  servo_2.write(0);
  delay(500);
  }
  if(Num == 3){
  servo_3.write(0);
  delay(500);
  }
  if(Num == 4){
  servo_4.write(0);
  delay(500);
  }
  if(Num == 5){
  servo_5.write(0);
  delay(500);
  }
  if(Num == 6){
  servo_6.write(0);
  delay(500);
  }
}
