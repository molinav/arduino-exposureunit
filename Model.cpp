#include "Model.h"


Model::Model() {
  valRelayU = LOW;
  valRelayD = HIGH;
  countdown = 0;
};

void Model::switchRelays() {
  // Switch among states (LOW, HIGH), (HIGH, LOW) and (HIGH, HIGH).
  valRelayU = (valRelayU ^ valRelayD);
  valRelayD = (valRelayU ^ valRelayD);
};

void Model::addCountdown(unsigned short delta) {
  // Add delta seconds to countdown.
  countdown += delta;
  countdown %= MAXTIME;
};

void Model::subCountdown(unsigned short delta) {
  // Subtract delta seconds from countdown.
  countdown -= min(delta, countdown);
  countdown %= MAXTIME;
};

void Model::clrCountdownMinutes() {
  // Leave the seconds from non-complete minute in countdown.
  countdown %= 60;
};

void Model::clrCountdownSeconds() {
  // Leave the seconds from complete minutes in countdown.
  countdown -= countdown % 60;
};
