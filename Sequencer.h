/* 
   Sequence.h - library for creating timed sequences of code without delay().
   Created by Austin W. Rowe, October 30, 2013.
   Released into the public domain.
   Version 2.0 (Updated on November 17, 2013)
 */
   
   #ifndef Sequencer_h
   #define Sequencer_h
   #include "Arduino.h"

class Sequence {
public:
 Sequence();
 void setTime(int Time);
 void start(int Steps, int Iterations);  //Set iterations to 0 to loop indefinitely
 void stop();
 void pause();
 void unpause();
 void gotoStep(int StepNum);
 int getStep();
 void reset();
 bool isComplete();
 int getIteration();
 int Step;

private:
 unsigned long TimeLast;
 unsigned long TimePaused;
 unsigned long TimeCurrent;
 int _Time;
 bool paused;
 int Iteration;
 bool Stopped;
 bool Complete;
};
class Timeout {
public:
 Timeout();
 void begin();
 void setTime(int TimeO);
 void startCounting();
 bool hasExpired();
 bool passed();
 void condition(bool Condition);
 void reset();
 
private:
 unsigned long CurrentTime;
 unsigned long LastTime;
 int _TimeO;
 bool Counting;
 bool TimedOut;
 bool Passed;
 bool _Condition;
 bool reset = true;
};
#endif
