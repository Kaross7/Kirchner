


void changeSchedule() {

  if((wifiMulti.run() == WL_CONNECTED)) {

    HTTPClient http;

    http.begin("http://project.local:8888/planning");

    int httpCode = http.GET();

    // httpCode will be negative on error
    if(httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {

        // file found at server
        String payload = http.getString();
        Serial.println(payload);
        Serial.println("===");

        const char* newMessage = payload.c_str();
        changeMessage(newMessage);
      }
    } else {
      Serial.println("Failed to connect");
    }
    http.end();
  }
}