int ballX = 0;
int ballY = 0;
int ballUp = 1;
int ballLeft = 1;


void animate(String animation) {

  for (byte i = 0; i < numDevices; i++) {
    lc.clearDisplay(i);
  }

  scrollMode = true;

  if (animation == "sinus") {
    const unsigned char animation[] PROGMEM = {"#$#$#$"};
    scrollMessage(animation, fontAnime, 6);
  }
  else if (animation == "pyramids") {
    const unsigned char animation[] PROGMEM = {"%&\'()%&\'()%&\'()"};
    scrollMessage(animation, fontAnime, 6);
  }
  else if (animation == "turtle") {
    turtle();
  }
  else if (animation == "pacMan") {
    pacMan();
  }
  else if (animation == "arrowsLeft") {
    arrows(1);
  }
  else if (animation == "arrowsRight") {
    arrows(0);
  }
}

void turtle() {
  
  for (byte i = 0; i < 145; i++) {

    lc.setLed(ballX / 8, ballY, (ballX % 8) * -1 + 7, true);
    delay(scrollDelay);

    ballX += ballLeft;
    ballY += ballUp;

    if (ballX == 29 || ballX == 0) {
      ballLeft *= -1;
    }
    if (ballY == 5 || ballY == 0) {
      ballUp *= -1;
    }
  }
}

void pacMan() {
  
  for (byte i = 0; i < 5; i++) {
    for (int rowIdx = 0; rowIdx < 6; rowIdx++) { 
      lc.setRow(0, rowIdx, pgm_read_byte_near(fontAnime + ((10 + i) * 7) + rowIdx));
    }
    for (byte deviceIdx = 1; deviceIdx < numDevices; deviceIdx++) {
      lc.setRow(deviceIdx, 3, (B10001000 >> i));
    }

    delay(scrollDelay / 2);
  }
}

void arrows(byte direction) {

  // Dit is kutcode maar het is laat en ik heb nog andere deadlines
  for (byte i = 0; i < 8; i++) {

    for (byte deviceIdx = 0; deviceIdx < numDevices; deviceIdx++) {
      for (int rowIdx = 0; rowIdx < 6; rowIdx++) { 

        byte rowData = (0, rowIdx, pgm_read_byte_near(fontAnime + ((15 + direction) * 7) + rowIdx));
        if (direction) {
          lc.setRow(deviceIdx, rowIdx, (rowData << i) | (rowData >> 8 - i));
        } else {
          lc.setRow(deviceIdx, rowIdx, (rowData >> i) | (rowData << 8 - i));
        }
      }
    }
    delay(scrollDelay);
  }
}





