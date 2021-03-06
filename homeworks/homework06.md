## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

Constant: Malloc, free
Proportional: Calloc and realloc


2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

Segfault, or you would just read garbage data.

b) Writing to unallocated memory.

Segfault, or the potential to overwrite something important that could go undetected.

c) Reading from a freed chunk.

Same as a.

d) Writing to a freed chunk.

Same as b.

e) Failing to free a chunk that is no longer needed.

Memory leaks, which could result in the system running out of memory in larger programs.


3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

My top three processes are all google chrome. I have three tabs open in google chrome.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

This can lead to fragmentation, where there are many small allocated chunks in memory spaced apart that result in the inability to allocate more chunks

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
