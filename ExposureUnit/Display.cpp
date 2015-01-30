#include "Display.h"


void Display::start() {
  // Start LiquidCrystal_I2C, clear display and set backlight on.
  init();
  clear();
  backlight();
};

void Display::showWelcomeWindow() {
  // Build welcome window and show during WELCOMEWINDOWLAG milliseconds.
  clear();
  setCursor(1, 0);
  print("Exposure unit");
  setCursor(1, 1);
  print("by EA4BNQ");
  delay(WELCOMEWINDOWLAG);
};

void Display::showMainWindow(Model& mdl) {
  // Build main window and show the initial values in model.
  clear();
  setCursor(0, 0);
  print("Countdown");
  updateCountdown(mdl);
  updateLed(mdl);
};

void Display::updateLed(Model& mdl) {
  // Refresh valRelayU and valRelayD values shown in display.
  setCursor(14, 0);
  if (mdl.valRelayU) {
    print("Up");
  }
  else {
    print("  ");
  }
  setCursor(12, 1);
  if (mdl.valRelayD) {
    print("Down");
  }
  else {
    print("    ");
  }
};

void Display::updateCountdown(Model& mdl) {
  // Refresh countdown's value shown in display.
  char strCountdown[6];
  sprintf(strCountdown, "%02d:%02d", mdl.countdown / 60, mdl.countdown % 60);
  setCursor(0, 1);
  print(strCountdown);
};
