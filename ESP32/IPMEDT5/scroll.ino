

void scrollMessage(const unsigned char *messageString, const unsigned char *font, byte fontSize) {

  for (byte i = 0; i < numDevices; i++) {
    lc.clearDisplay(i);
  }

  activeFont = font;
  fontY = fontSize;

  int counter = 0;
  byte currentChar = 0;

  do {                                                    // read all chars from pgm
    currentChar = messageString[counter];  // read a char from pgm  
    loadBufferLong(currentChar);
    counter++;
  }
  while (currentChar != 0);

  if (!scrollMode) {
    printBufferLong();
    memset(bufferLong, 0, sizeof(bufferLong));
    delay(scrollDelay * 10);
  }
}

// Load character into scroll buffer
void loadBufferLong(byte ascii) {
  if (ascii >= 32 && ascii <= 127) {

    for (int rowIdx = 0; rowIdx < fontY; rowIdx++) {                                      
      unsigned long rowData = pgm_read_byte_near(activeFont + ((ascii - 32) * (fontY + 1)) + rowIdx);      // Index into character table to get row data
      
      unsigned long x = bufferLong[rowIdx * 2];                                     // Load current scroll buffer
      x = x | rowData;                                                                        // OR the new character onto end of current
      bufferLong[rowIdx * 2] = x;                                                      // Store in buffer
    }

    byte count = pgm_read_byte_near(activeFont + ((ascii - 32) * (fontY + 1)) + fontY);     // Index into character table for kerning data

    for (byte i = 0; i < count; i++) {
      rotateBufferLong();

      if (scrollMode) {
        printBufferLong();
        delay(scrollDelay);
      }
    }
  }
}

// Rotate the buffer
void rotateBufferLong() {

  for (int rowIdx = 0; rowIdx < fontY; rowIdx++){                      
    unsigned long x = bufferLong[rowIdx * 2];     // Get low buffer entry
    byte b = bitRead(x, 31);                      // Copy high order bit that gets lost in rotation
    x = x << 1;                                   // Rotate left one bit
    bufferLong[rowIdx * 2] = x;                  // Store new low buffer
    x = bufferLong[rowIdx * 2 + 1];               // Get high buffer entry
    x = x << 1;                                   // Rotate left one bit
    bitWrite(x, 0, b);                             // Store saved bit
    bufferLong[rowIdx * 2 + 1] = x;               // Store new high buffer
  }
}


// Display Buffer on LED matrix
void printBufferLong(){
  for (int rowIdx = 0; rowIdx < fontY; rowIdx++) {             
    unsigned long x = bufferLong[rowIdx * 2 + 1];   // Get high buffer entry

    byte y = x;                             // Mask off first character
    lc.setRow(3, rowIdx, y);
                                              // Send row to relevent MAX7219 chip
    x = bufferLong [rowIdx * 2];                   // Get low buffer entry
    y = (x >> 24);                            // Mask off second character
    lc.setRow(2, rowIdx, y);
                                          // Send row to relevent MAX7219 chip
    y = (x >> 16);                          // Mask off third character
    lc.setRow(1, rowIdx, y);
                                          // Send row to relevent MAX7219 chip
    y = (x >> 8);                           // Mask off forth character
    lc.setRow(0, rowIdx, y);                       // Send row to relevent MAX7219 chip
  }
}
