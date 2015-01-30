#ifndef Model_h
#define Model_h

#include <Arduino.h>


class Model {
  public:
    // Define model variables.
    boolean valRelayU;
    boolean valRelayD;
    unsigned short countdown;
    // Define initializer and methods.
    Model();
    void switchRelays();
    void addCountdown(unsigned short delta);
    void subCountdown(unsigned short delta);
    void clrCountdownMinutes();
    void clrCountdownSeconds();
  private:
    // Define model constants.
    static const unsigned short MAXTIME = 900;
};

#endif
