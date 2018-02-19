## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

File systems abstract files as streams of bytes, when they are actually stored in nonlinear blocks with complex mappings.

2) What information do you imagine is stored in an `OpenFileTableEntry`?

Some pointers to the file start and the location of where the process is reading.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

Block transfer, pre-fetching, buffering, and caching help the OS improve performance. 

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

The program had buffered the changes and was going to write them to the disk later. When the power was lost, the RAM was cleared and so were your changes.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

UNIX inode seems like it would perform well for file sizes that fit into its blocks (including no indirection, single, double and triple). FAT would have to do many jumps for longer files, slowing down performance. But inode does not have anything built in for files larger than triple indirection so its performance may suffer more for very very large files. 

6) What is overhead?  What is fragmentation?

Overhead is the of the file system that does not store actual user data. Fragmentation is unused space between blocks.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

Everything is a file makes for a simple reuseable api and allows for good compatibility between various programs. It may not be a good idea for more complex structures that cannot be easily represented as files. 

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



