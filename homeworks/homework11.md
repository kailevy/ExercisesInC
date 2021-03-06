## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

Because it behaves as a structure, so assignment is copying and copying is undefined behavior.

2) When you use a Semaphore as a mutex, what should its initial value be?

1 to be unlocked.

3) Can you think of another use for a Semaphore where you might use a different initial value?

If you would like a process to be initially blocked, then start it at 0.

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

That there are 3 empty spaces in the queue.

5) What does it mean if `queue->space` is `-3`?

Push was somehow called three times without being blocked, resulting in 2 spaces being overwritten.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

Because it can check queue->items instead to see how many items are left.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

Semaphores can be implemented with mutexes and condition variables, proving that the same problems can be solved with just those.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf). 

"Property 3: if there are threads waiting on a semaphore when a thread executes signal, then one of the waiting threads has to be woken"


