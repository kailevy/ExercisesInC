## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

The data structure won't behave unexpectedly under concurrent conditions.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

We don't want next_in == next_out, which would signal that the queue is empty, so we stop one short of n.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

Access to both next_in and next_out at the same time, incrementing them incorrectly.

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

Otherwise there would never be access to the queue.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

The condition is true, so the queue isn't empty, and it's probably safe to access.

6) What happens if you signal a condition variable when there are no waiting threads?

Nothing.

7) Do you have to lock the mutex to signal a condition variable?

I don't think so.

8) Does the condition have to be true when you signal a condition variable?

Not necessarily.


