#include "PSM.h"
PSM::PSM(unsigned char sensePin, unsigned char controlPin, unsigned int range, int mode, unsigned char divider, unsigned char interruptMinTimeDiff) {
}
void PSM::set(unsigned int value) {
}
long PSM::getCounter() {
  return 1;
}
void PSM::resetCounter() {
}
void PSM::stopAfter(long counter) {
}
unsigned int PSM::cps() {
  return 50u;
}
unsigned long PSM::getLastMillis() {
  return 1ul;
}

unsigned char PSM::getDivider(void) {
  return 1;
}

void PSM::setDivider(unsigned char divider) {
}

void PSM::shiftDividerCounter(char value) {
}

void PSM::initTimer(unsigned int freq, int timerInstance) {
}
