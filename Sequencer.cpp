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
bool Sequence::isComplete() {
return Complete;
}
int Sequence::getIteration() {
return Iteration;
}
int Sequence::getStep() {
return Step;
}

//Time-out sub-library code begins here.

Timeout::Timeout() {}

void Timeout::begin() {
if(Counting = true) {
	
 CurrentTime = millis();
 if (_Condition) {
	Passed = true;
 }
 if(CurrentTime - LastTime >= _TimeO || Passed == true) {
	TimedOut = true;
	Counting = false;
}
	} else {
	TimedOut = true;
	}
	if(TimedOut == true && _Condition == false) {
	Passed = false;
	}
		}

void Timeout::startCounting() {
 if (reset = true) {
    reset = false;
	LastTime = CurrentTime; //reset timer.
	Passed = false; //reset boolean value 1.
	TimedOut = false; //reset boolean value 2.
	Counting = true; //enable counting.
	} else {}
}

void Timeout::setTime(int TimeO) {
	_TimeO = TimeO;
}

bool Timeout::hasExpired() {
	return TimedOut; 
}

bool Timeout::passed() {
	return Passed;
}

void Timeout::condition(bool Condition) {
	_Condition = Condition;
 }
 
void Timeout::reset() {
	reset = true;
}

