## Homework 8

### C Exercises

Modify the link below so it points to the `ex08` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

To handle interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

The program counter

3) What is the difference between an interrupt and a context switch?

A context switch is an interrupt that switches to a different process.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

A disk request.

5) Why might a scheduler want to give higher priority to an I/O bound process?

Because these processes are more likely to be blocked often, and would benefit more from priority scheduling.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

8 on one side, then 4 on one side and 4 on the other side, then 8 on the other side.
