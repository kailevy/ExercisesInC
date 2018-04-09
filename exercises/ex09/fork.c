/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;

int globalval = 0;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i, int *stackval, int *heapval)
{
    sleep(i);
    *stackval += 1;
    *heapval += 1;
    globalval += 1;
    printf("Hello from child %d.\n", i);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    int stackval= 10;
    int *heapval = malloc(sizeof(int));
    *heapval = 100;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    printf("PARENT BEGIN\nstackval: %d, heapval: %d, globalval: %d\n", stackval, *heapval, globalval);

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();


        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            printf("Address: %p\n", &pid);
            child_code(i, &stackval, heapval);

            printf("CHILD %d\nstackval: %d, heapval: %d, globalval: %d\n", i, stackval, *heapval, globalval);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");


    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    printf("PARENT END\nstackval: %d, heapval: %d, globalval: %d\n", stackval, *heapval, globalval);

    exit(0);
}

/* We create a global var, a stack var and a heap var and initialize them. Then, in each of the children's code, we increment them.
We print them in the child and see that they have incremented, but they are the same for each child, so the children aren't sharing
variables. And when we print them at the end, they are back to the initial values, so they aren't sharing variables with the parent
either. */
 