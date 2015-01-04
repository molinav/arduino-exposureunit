#ifndef Display_h
#define Display_h

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Model.h"


class Display : public LiquidCrystal_I2C {
  public:
    // Define initializer and methods.
    Display() : LiquidCrystal_I2C(ADDR, COLS, ROWS) {};
    void start();
    void showWelcomeWindow();
    void showMainWindow(Model& mdl);
    void updateLed(Model& mdl);
    void updateCountdown(Model& mdl);
  private:
    // Define display constants.
    static const unsigned short ADDR = 0x3F;
    static const unsigned short COLS = 16;
    static const unsigned short ROWS = 2;
    static const unsigned short WELCOMEWINDOWLAG = 3000;
};

#endif
