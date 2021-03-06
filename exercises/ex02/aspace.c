/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void printer()
{

    int var3 = 10;

    printf ("Address of var3 is %p\n", &var3);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(18);
    void *t = malloc(18);
    char *s = "Literal string";
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of p is %p\n", p);
    printf ("Address of t is %p\n", t);
    printf ("Address of s is %p\n", s);
    printer();

    return 0;
}
