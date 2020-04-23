


int infar (int CheckPark){

// CheckPark > Found / not found for each park spot 

# define Infar_1  21  //36
# define Infar_2  17  //39
# define Infar_3  16  //34
# define Infar_4  36  //21 
# define Infar_5  39  //17 
# define Infar_6  34  //16 


  int val_1=0;
  int val_2=0;
  int val_3=0;
  int val_4=0;
  int val_5=0;
  int val_6=0;
  
  //not found val = 1
  //found val = 0
  
  if(CheckPark==1){
    val_1 = digitalRead(Infar_1);
    //Serial.print("val_1 = ");
    //Serial.println(val_1);
    delay(100);
    return val_1;
  }
  if(CheckPark==2){
    val_2 = digitalRead(Infar_2);
    //Serial.print("val_2 = ");
    //Serial.println(val_2);  
    delay(100);
    return val_2;
  }
  if(CheckPark==3){
    val_3 = digitalRead(Infar_3);
   // Serial.print("val_3 = ");
    //Serial.println(val_3);
    delay(100);
    return val_3;
  }
  if(CheckPark==4){
    val_4 = digitalRead(Infar_4);
    //Serial.print("val_4 = ");
    //Serial.println(val_4);
    delay(100);
    return val_4;
  }
  if(CheckPark==5){
    val_5 = digitalRead(Infar_5);
    //Serial.print("val_5 = ");
    //Serial.println(val_5);
    delay(100);
    return val_5;
  }
  if(CheckPark==6){
    val_6 = digitalRead(Infar_6);
    //Serial.print("val_6 = ");
    //Serial.println(val_6);
    delay(100);
    return val_6;
  }

  return -1;
  
}

int infar_old1 =1;
int infar_old2 =1;
int infar_old3 =1;
int infar_old4 =1;
int infar_old5 =1;
int infar_old6 =1;
