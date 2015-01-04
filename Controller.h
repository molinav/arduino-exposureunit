#ifndef Controller_h
#define Controller_h

#include <Arduino.h>
#include "Model.h"
#include "Display.h"


class Controller {
  public:
    // Define pin values for buttons and relays.
    static const byte pinBtnMin = 6;
    static const byte pinBtnSec = 7;
    static const byte pinBtnLed = 8;
    static const byte pinBtnRun = 9;
    static const byte pinRelayU = 2;
    static const byte pinRelayD = 3;
    // Define initializer and methods.
    Controller();
    void start(Model& mdl, Display& lcd);
    void onBtnMinPressed(Model& mdl, Display& lcd);
    void onBtnSecPressed(Model& mdl, Display& lcd);
    void onBtnLedPressed(Model& mdl, Display& lcd);
    void onBtnRunPressed(Model& mdl, Display& lcd);
  private:
    // Define private methods.
    void updatePinRelays(boolean valU, boolean valD);
    void waitUntilBtnReleased(byte pinBtn);
    // Define control constants.
    static const unsigned short WAITLAG = 300;
};

#endif
