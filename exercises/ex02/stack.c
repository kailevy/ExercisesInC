/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        // We see random values before we set them. 
        printf("%d\n", array[i]);
        array[i] = 42;
        printf("%d\n", array[i]);
    }
    // This returns a local address which will not be valid outside of this function
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        // Since the array is allocated in the same place as the one in foo, the values are initially 42!
        printf("%d\n", array[i]);
        array[i] = i;
        printf("%d\n", array[i]);

    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        // This will seg fault since the array address is not valid in the scope of main
        printf("%d\n", array[i]);
    }

    return 0;
}
