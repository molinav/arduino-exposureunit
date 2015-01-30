#include "Controller.h"


Controller::Controller() {
  pinMode(pinBtnMin, INPUT);
  pinMode(pinBtnSec, INPUT);
  pinMode(pinBtnLed, INPUT);
  pinMode(pinBtnRun, INPUT);
  pinMode(pinRelayU, OUTPUT);
  pinMode(pinRelayD, OUTPUT);
};

void Controller::start(Model& mdl, Display& lcd) {
  // Force initial states for relays and start display.
  updatePinRelays(LOW, LOW);
  lcd.start();
  lcd.showWelcomeWindow();
  lcd.showMainWindow(mdl);
};

void Controller::onBtnMinPressed(Model& mdl, Display& lcd) {
  delay(WAITLAG);
  // Short-press case.
  if (digitalRead(pinBtnMin)) {
    mdl.addCountdown(60);
  }
  // Long-press case.
  else {
    mdl.clrCountdownMinutes();
  }
  lcd.updateCountdown(mdl);
  waitUntilBtnReleased(pinBtnMin);
};

void Controller::onBtnSecPressed(Model& mdl, Display& lcd) {
  delay(WAITLAG);
  // Short-press case.
  if (digitalRead(pinBtnSec)) {
    mdl.addCountdown(1);
  }
  // Long-press case.
  else {
    mdl.clrCountdownSeconds();
  }
  lcd.updateCountdown(mdl);
  waitUntilBtnReleased(pinBtnSec);
};

void Controller::onBtnLedPressed(Model& mdl, Display& lcd) {
  waitUntilBtnReleased(pinBtnLed);
  mdl.switchRelays();
  lcd.updateLed(mdl);
};

void Controller::onBtnRunPressed(Model& mdl, Display& lcd) {
  waitUntilBtnReleased(pinBtnRun);
  updatePinRelays(mdl.valRelayU, mdl.valRelayD);
  // Manual case.
  if (mdl.countdown == 0) {
    while (1) {
      if (!digitalRead(pinBtnRun)) {
        break;
      }
    }
  }
  // Automated case.
  else {
    while (mdl.countdown > 0) {
      delay(1000);
      mdl.subCountdown(1);
      lcd.updateCountdown(mdl);
      if (!digitalRead(pinBtnRun)) {
        break;
      }
    }
  }
  // Return to main window.
  mdl.subCountdown(mdl.countdown);
  lcd.updateCountdown(mdl);
  updatePinRelays(LOW, LOW);
  waitUntilBtnReleased(pinBtnRun);
};

void Controller::updatePinRelays(boolean valU, boolean valD) {
  // Set voltage levels for pins connected to relays.
  digitalWrite(pinRelayU, valU);
  digitalWrite(pinRelayD, valD);
};

void Controller::waitUntilBtnReleased(byte pinBtn) {
  // Stop process until pinBtn is released.
  while (!digitalRead(pinBtn)) {
    delay(WAITLAG);
  }
};
