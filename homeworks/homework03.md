## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

The closest power of 2 above 33 is 2^6=64, so 6 bits.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 = 4294967296 characters.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

Storage is for long-term storage, when files are physically written to a drive. Memory is for random access memory, which is used for processes and lost upon shutdown.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

A gibibyte is 2^30 bytes, while a gigabyte is 10^9 bytes. They are about 7% different (GiB is bigger).

5) How does the virtual memory system help isolate processes from each other?

The virtual memory addresses are translated into physical addresses, which the processes have no control over, so on process cannot access the same physical address as another one.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

These are the parts of the memory that can change dynamically, and there is a finite amount of address space. In order to make sure they don't overlap while they are growing, we want them to grow in opposite directions. By starting them at opposite ends of the address space, they won't collide until they overflow, the addresses are convenient to reference from the bottom and top of the address space, and they can grow dynamically during program execution.

7) What Python data structure would you use to represent a sparse array?

A dictionary.

8) What is a context switch?

When the OS interrupts a process, saves its state, and switches to another.
