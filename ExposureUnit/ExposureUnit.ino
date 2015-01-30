/*
  ExposureUnit
  
  Control an exposure unit with four buttons and one display LCD.
  The code structure is object-oriented:
  - Model
    - Countdown.
    - Boolean states which will be passed to relays.
  - Display
    - 16x2 LiquidCrystal_I2C display (modify ADDR if necessary).
    - Methods for showing model variables in display.
  - Controller
    - Pin ids for input buttons and output relays.
    - Call methods when buttons are pressed.
  The circuit is consisted of:
  - Arduino board.
  - Button attached to input pin from ground (x4).
  - 10k resistor attached to input pin from +5V (x4).
  - LCD_I2C with VCC to +5V, GND to ground and SDA/SCL to proper SDA/SCL pins.
  - Ultraviolet LED strip lights to output pin from ground (x2).
  The project requires the following libraries:
  - LiquidCrystal_I2C.
  - Wire.
  
  created 2014
  by Victor Molina
  modified 4 Jan 2015
  by Victor Molina
  
  This example code is licensed under the GNU GPLv3.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Model.h"
#include "Display.h"
#include "Controller.h"

Model mdl;
Display lcd;
Controller ctrl;

void setup() {
  ctrl.start(mdl, lcd);
};

void loop() {
  if (!digitalRead(ctrl.pinBtnMin)) {
    ctrl.onBtnMinPressed(mdl, lcd);
  }
  if (!digitalRead(ctrl.pinBtnSec)) {
    ctrl.onBtnSecPressed(mdl, lcd);
  }
  if (!digitalRead(ctrl.pinBtnLed)) {
    ctrl.onBtnLedPressed(mdl, lcd);
  }
  if (!digitalRead(ctrl.pinBtnRun)) {
    ctrl.onBtnRunPressed(mdl, lcd);
  }
};
