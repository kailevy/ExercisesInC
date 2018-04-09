## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

So that threads can call functions without messing each other up.

2) What does the gcc flag `-lpthread` do?

Compiles with the pthread library

3) What does the argument of `pthread_exit` do?

Passes a value to the thread that joins the calling thread.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

It would still execute, but could likely get stuck in some sort of wait condition.

5) What goes wrong if several threads try to increment a shared integer at the same time?

Since the increment is two instructions, they may end up overwriting each other's increments.

6) What does it mean to "lock a mutex"?

It's a call which will block the execution of other threads sharing the same mutex.
