Sequencer-lib (main)
====================


Library for Arduino to create timed sequences of events and more! 
(Created by: Austin W. Rowe from REC) ----
(Package v2.0) (Sequencer v1.3.1) (Timeout v0.4-B)
*******************************************************************************
Description:
--------
 This library allows the user to simply create a timed sequences of code.  Uses include:  Creating led animations, Sequencing servos to move certain distances and directions, can be used in a drawing robot to run motors.  (Multipal sequences can be created by creating a new instance of the sequencer class with a different name). 


How to use:
---------
 The sequence itself can be made of either a switch case or a simple if statement. 
But a switch case statement is recommended.  The steps to make your sequence is as follows:

Before you do anything, you need to declare you are using the library by importing it. 
Then create an instance of the Sequencer class by making a global variable, “Timer1” for example.

1. First create a switch case statement with the variable in switch( ) being any variable you want.
 But we are going to use “Step” for now.  The cases represent the step, starting at 1
 and ending at the last step (create a case 0: if the sequence is not set to loop forever)
 Let's say there are 4 steps in the sequence.  So you will have cases 1 through 4. But if you wanted to only run the
 sequence a set amount of times, you will have cases 0 through 4 (case 0 is only called when the sequence is 
 completed.
2. Second you need to define the time you want each step to take by using Timer1.setTime(time) 
 in the top of each step (or case).
3. Okay, now we have a switch case statement and we set the time for each step.  
 Next we need to set that variable we chose earlier equal to the current step by simply setting it equal
 to Timer1.getStep().  This is put at the top of void loop() (Not in a case).
4. Now we have almost everything we need to have a working sequence. The only thing left is to
 add the begin statement Timer1.start(int, int). The first “int” is the total amount of steps.  The
 second "int" is the amount of times the sequence will repeat (set to 0 to loop forever).
 The begin statement is put at the top of void loop(), preferably above Timer1.getStep()).
5. Now add some some things in each step to test it, blink an led at different speeds for example.
   Remember case 0 (if applicable) only runs when the sequence is completed.


Timeout-lib
============

This library is in beta and may not work as good as it could, please give it time.
***

Description:
--------
 This library allows the user to easily create time sensitive code.  Uses include: A button that has to be pressed in a certain amount of time or it will time out, or a piece of code that will do an alternative function when an expected variable or expression does not become true in a certain amount of time.  This library could (in the future) add the ability to do other taskes like a timed button sequence where you have to press the right buttons in the right order (like a cheat code), but where each button has to be held down for a certain amount of time for it to work.  Or if you dont complete the sequence in the amount of time specified, it wont work.

How to use:
--------
 The time sensitive code can only be in a stacked if statement for now due to the way the library returns whether or not the condition has passed.  The first if statement is to test if the time has expired, the if statement inside is
to test if the condition passed.

1. Put Timeout.setTime(int) in void setup() or in a place where it wont be set over and over, and set the time to 
what ever you want in miliseconds.
2. put Timeout.begin() in the main loop or in a function where it cant get interupted, because this is the timer.
3. Put the condition you want to test inside Timeout.condition(bool) (place below Timeout.begin() if it is in the main loop).
3. Create an if statement where the condition is Timeout.hasExpired().
4. Create another if statement inside that where the condition is Timeout.passed().
5. Put code you want to execute when it passes in the body of that if statement.
6. Put code you want to execute when it failes in an else{} after that if statement but not after the first one we
created.
7. Start the timer by calling Timeout.startCounting().  (There is a procaution to prevent accidental calls of this).
8. When the time expires you can run it again by calling Timeout.reset(), then Timeout.startCounting() again.


Keywords and uses
===================

There are more commands than just the ones talked about in the instructions.  Here is a full list of keywords.

Sequencer:
--------

void Sequencer.start(int, int).   Starts the sequence. The 1st "int" is the amount of steps in the sequence, the 2nd "int"  
                              is the amount of times the Sequence will repeat (setting it to 0 will make it loop 
                              forever).

 int Sequencer.getStep().   Returns the current step the sequence is running.

 void Sequencer.setTime(int).   Sets the time a step will take (must be put at the TOP of a case to work correctly)

 void Sequencer.gotoStep(int).   Sets the current step to the value secified.

 void Sequencer.pause().   Pauses the sequence where it is (paused the timer).

 void Sequencer.unpause().   Unpauses the sequence (BUG: using this without the sequence paused will screw up the timer).
 
 bool Sequencer.getComplete().   Returns either true or false whether the sequence is complete.
 
 int Sequencer.getIteration().   Returns the number of iterations the sequence has completed.
 
 Timeout:
 --------
 void Timeout.begin().   Initializes the timer.
 
 void Timeout.setTime(int).   Sets the time the timer will count to before expiring.
 
 void Timeout.startCounting().   Starts the timer.
 
 bool Timeout.hasExpired().   Returns true if time has expired.
 
 bool Timeout.passed().  Returns true if condition has passed.
 
 void Timeout.condition(bool).  The condition to test.


