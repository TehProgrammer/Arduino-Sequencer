Sequencer-lib
=============

Library for Arduino to create timed sequences of events. 
(Created by: Austin W. Rowe from REC)

How to use:
The sequence itself can be made of either a switch case or a simple if statement. 
But a switch case statement is recommended.  The steps to make your sequence is as follows:

Before you do anything, you need to declare you are using the library by importing it. 
Then create an instance of the Sequencer class by making a global variable, “Timer1” for example.

1. First create a switch case statement with the switch( ) being any variable you want.
 But we are going to use “Step” for now.  The cases represent the step, starting at 1
 and ending at the last step.  Let's say there are 4 steps in the sequence.  So you will have cases 1 through 4.
2. Second you need to define the time you want each step to take by using Timer1.setFuse(time) 
 in the top of each step (or case).
3. Okay, now we have a switch case statement and we set times for each step.  
 Next we need to set that variable we chose earlier equal to the current step by simply setting it equal
 to Timer1.getStep().  This is put at the top of void loop() (Not in a case).
4. Now we have almost everything we need to have a working sequence. The only thing left is to
 add the begin statement Timer1.start(int). “int” is the total amount of steps.  
 The begin statement is put at the top of void loop() (put it above the Timer1.getStep()).
5. Now add some some things in each step to test it, blink an led at different speeds for example.



There are more commands than just the ones talked about in the instructions.  Here is a full list of keywords.

Sequence.start(int).

int Sequence.getStep().

Sequence.setFuse().

Sequence.gotoStep(int).

Sequence.pause().

Sequence.unpause().


