#include "Arduino.h"
#include "Sequencer.h"

Sequence::Sequence() {}
void Sequence::setTime(int Time) {
_Time = Time;
}
void Sequence::start(int Steps, int Iterations) {
if (Complete == false) {
unsigned long TimeCurrent = millis();
if(Iteration == Iterations && Iterations != 0) {
Complete = true;
Iteration = 0;
} else {
if (paused == false) {
if(TimeCurrent - TimeLast >= _Time) {
TimeLast = TimeCurrent;
Step++;
if (Step > Steps) {
Step = 1;
Iteration++;
   }
  }
 } else {
 TimePaused = TimeCurrent - TimeLast;
 }
 }
 } else {
 Step = 0;
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
void Sequence::reset() {
Complete = false;
Step = 1;
}
bool Sequence::getComplete() {
return Complete;
}
int Sequence::getIteration() {
return Iteration;
}
int Sequence::getStep() {
return Step;
}

}
int Sequence::getStep() {
return Step;
}
