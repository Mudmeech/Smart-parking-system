String old_tag ="";
String Correct1;
String Correct2;

String Post_Rfid(String Rfid_tag){
  
   if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
        HTTPClient http;
       //Serial.print("connect -> old tag : ");
      // Serial.println(old_tag);
      // Serial.print("connect -> new tag : ");
      // Serial.println(Rfid_tag);
        
        if(Rfid_tag != old_tag && Rfid_tag!="" ){
          //Serial.println("not equal");
          http.begin("https://reservation-272207.appspot.com/esp/parking"); //Specify the URL
          http.addHeader("Content-Type", " text/plain");        
          int httpResponseCode = http.POST(Rfid_tag);   //Send the actual POST request
          old_tag = "";
         // Serial.println("assign old tag to RFID Tag , and send POST ");
          
          if (httpResponseCode > 0) {
              // get
              String response = http.getString(); //Get the response to the request
              //Serial.println(httpResponseCode);
  
              if(httpResponseCode<=250){
                //Serial.println(response);
                Correct1 = response.substring(0,response.lastIndexOf("\""));
                Correct2 = Correct1.substring(Correct1.lastIndexOf("\"")+1);
                Serial.println("license:" + Correct2);
                Serial.println("Reserve slot"+ response.substring(14,15));
                // {"slotNumber":4,"slot":"B1","license":"FF 1111"}
                return(response.substring(14,15));
              }

                return "-1";//">0 , <=250"
          }
          else {
            Serial.println("Error on HTTP request");
            return "-2";//error on http
          }
        }
        http.end(); //Free the resources
    }else {return "-3"; }//network not connect
  delay(1000);
  
}

void Post_OutSlot(int slot){
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
    http.begin("https://reservation-272207.appspot.com/esp/driveout"); //Specify the URL
    
    //post
    http.addHeader("Content-Type", " text/plain"); 
    int httpResponseCode = http.POST(String(slot));   //Send the actual POST 
 
    http.end(); //Free the resources
  }
    delay(100);
}
