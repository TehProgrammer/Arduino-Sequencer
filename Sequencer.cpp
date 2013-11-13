#include "Arduino.h"
#include "Sequencer.h"

Sequence::Sequence() {}
void Sequence::setFuse(int Time) {
_Time = Time;
}
void Sequence::start(int Steps) {
unsigned long TimeCurrent = millis();
if (paused == false) {
if(TimeCurrent - TimeLast >= _Time) {
TimeLast = TimeCurrent;
Step++;
if (Step > Steps) {
Step = 1;
   }
  }
 } else {
 TimePaused = TimeCurrent - TimeLast;
 }
}
void Sequence::pause() {
paused = true;
}
void Sequence::unpause() {
TimeLast = TimePaused;
paused = false;
}
void Sequence::gotoStep(int StepNum) {
Step = StepNum;
}
int Sequence::getStep() {
return Step;
}
