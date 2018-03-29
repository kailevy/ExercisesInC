## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

Then the program executes a different part.

2) What is the fundamental problem caches are meant to solve?

Caching is meant to solve the bottleneck of getting data from memory to the CPU.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

5.5ns at 50%, 1.9ns at 90%.

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

Reading files as streams would increase locality, while collecting input from various sources would decrease it.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

I think that cache-aware is more specific to the hardware of a processor, while improving locality is a general performance improvement.

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

$150 for 4MiB cache, $300 for 8MiB, so ~$37.5/MiB?

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

The bottom of the hierarchy is bigger and slower, so there is more time to make complex decision.

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Perhaps operating systems could put a hard limit on the number of pages a process can use, depending on the number of processes, to prevent thrashing.
