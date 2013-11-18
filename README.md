Sequencer-lib
=============

(Beta 2.0, WIP) NOT UPDATED!

Library for Arduino to create timed sequences of events. 
(Created by: Austin W. Rowe from REC)

How to use:
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



There are more commands than just the ones talked about in the instructions.  Here is a full list of keywords.

 Sequencer.start(int, int).   Starts the sequence. The 1st "int" is the amount of steps in the sequence, the 2nd "int"  
                              is the amount of times the Sequence will repeat (setting it to 0 will make it loop 
                              forever).

 int Sequencer.getStep().   Returns the current step the sequence is running.

 Sequencer.setTime(int).   Sets the time a step will take (must be put at the TOP of a case to work correctly)

 Sequencer.gotoStep(int).   Sets the current step to the value secified.

 Sequencer.pause().   Pauses the sequence where it is (paused the timer).

 Sequencer.unpause().   Unpauses the sequence (BUG: using this without the sequence paused will screw up the timer).
 
 Sequencer.getComplete().   Returns either true or false whether the sequence is complete.
 
 Sequencer.getIteration().   Returns the number of iterations the sequence has completed.


