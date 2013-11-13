/* 
   Sequence.h - library for creating timed sequences of code.
   Created by Austin W. Rowe, October 30, 2013.
   Released into the public domain.
   Version 1.2
 */
   
   #ifndef Sequencer_h
   #define Sequencer_h
   #include "Arduino.h"
   
class Sequence {
public:
Sequence();
void setTime(int Time);
void start(int Steps);
void pause();
void unpause();
void gotoStep(int StepNum);
int getStep();
int Step;

private:
long TimeLast;
long TimePaused;
unsigned long TimeCurrent;
int _Time;
bool paused;
};

#endif
