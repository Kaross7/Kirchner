class Timer {
  private:
    unsigned long initStamp;
    unsigned long duration;

  public:
    Timer(int durationMS) {
      duration = durationMS;
      initStamp = millis();
    }

    void reset() {
      initStamp = millis();
    }

    void setDuration(unsigned long newDuration) {
      duration = newDuration;
    }

    bool isActive() {
      if (millis() - initStamp >= duration) {
        return false;
      }
      return true;
    }
};

class Button {
  private:
    int buttonPIN;
    bool pressed = false;
    bool flag = false;

    unsigned long updateStamp = 0;

    bool hasPressure() {
      return !digitalRead(buttonPIN);
    }

  public:
    Button(int PINnumber) {
      buttonPIN = PINnumber;
      pinMode(buttonPIN, INPUT_PULLUP);
    }
    
    void setFlag(bool newFlag) {
      flag = newFlag;}

    bool getFlag() {
      return flag;}

    bool isPressed() {
      return pressed;}

    void update() {
      if ((millis() - updateStamp) > 20) {
        
        updateStamp = millis();

        if (hasPressure() != pressed) {
          pressed = !pressed;}
      }
    }
};

class RotaryEncoder  {
  private:
    int position = 0;
    int trendStart = 0;
    int trendEnd = 0;
    bool stable = true;

    byte CLK_PIN;
    byte DT_PIN;
    
  public:
    RotaryEncoder(byte CLK, byte DT) {
      CLK_PIN = CLK;
      DT_PIN = DT;

      pinMode(CLK_PIN, INPUT_PULLUP);
      pinMode(DT_PIN, INPUT_PULLUP);
    }

    int getPosition() {
      return position;}

    void reset() {
      position = 0;}

    void update() {

      bool CLK = digitalRead(CLK_PIN);
      bool DT = digitalRead(DT_PIN);

      int direction = CLK ^ DT ? (CLK ? 1 : -1) : 0;
      int stateSum = CLK + DT;

      if (stateSum == 2) {
        stable = true;
        if (trendStart != trendEnd) {
          position += trendStart * pow(trendEnd, 2);
        }
        trendStart = trendEnd = 0;
      }
      else if (stateSum == 1 && stable) {
        trendStart = direction;
        stable = false;
      }
      else if (stateSum == 1 && !stable) {
        trendEnd = direction;
      }
    }
};

class RotaryButton: public Button, public RotaryEncoder {
  public:
    RotaryButton(byte CLK, byte DT, byte SW): Button(SW), RotaryEncoder(CLK, DT) {}

    void update() {
      RotaryEncoder::update();
      Button::update();
    }
};

#include <LedControl.h> 

#define DIN_PIN 27
#define CS_PIN 26
#define CLK_PIN 25

const byte numDevices = 5;      
byte intensity = 8;
bool scrollMode = true;

LedControl lc(DIN_PIN, CLK_PIN, CS_PIN, numDevices);
Timer switchTimer(20000);
RotaryButton rotor(35, 32, 33);


#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

WiFiMulti wifiMulti;


// Text settings
extern const unsigned char font3x5 [] PROGMEM;
extern const unsigned char font3x6 [] PROGMEM;
extern const unsigned char fontAnime [] PROGMEM;
const unsigned char *activeFont;
byte fontY;

unsigned char scrollText[2048] = {""};

unsigned int scrollDelay = 100;
unsigned long bufferLong [14] = {0};


void changeMessage(const char *newText) {
  strncpy((char*)scrollText, newText, sizeof(scrollText) - 1);
}

void callUpdates() {
  rotor.update();

  scrollDelay = (rotor.getPosition() * 10 % 1000 + 1000) % 1000;
}

void setup()
{
  for (byte i = 0; i < numDevices; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, intensity);
    lc.clearDisplay(i);
  }

  wifiMulti.addAP("iPhone van Karos", "karos123");

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(35), callUpdates, CHANGE);
  attachInterrupt(digitalPinToInterrupt(32), callUpdates, CHANGE);
  attachInterrupt(digitalPinToInterrupt(33), callUpdates, CHANGE);
}
 
void loop() {

  changeSchedule();

  while (switchTimer.isActive()) {
    scrollMessage(scrollText, font3x6, 6);
  }
  switchTimer.reset();


  // changeMessage("Hello :)");
  // scrollMode = false;
  // while (switchTimer.isActive()) {
  //   scrollMessage(scrollText, font3x5, 5);
  // }
  // switchTimer.reset();

  // while (switchTimer.isActive()) {
  //    animate("sinus");
  // }
  // switchTimer.reset();

  // while (switchTimer.isActive()) {
  //   animate("pyramids");
  // }
  // switchTimer.reset();

  // while (switchTimer.isActive()) {
  //   animate("turtle");
  // }
  // switchTimer.reset();

  // while (switchTimer.isActive()) {
  //   animate("pacMan");
  // }
  // switchTimer.reset();

  // while (switchTimer.isActive()) {
  //   animate("arrowsLeft");
  // }
  // switchTimer.reset();

  // while (switchTimer.isActive()) {
  //   animate("arrowsRight");
  // }
  // switchTimer.reset();
}
