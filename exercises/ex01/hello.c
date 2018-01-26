#include <stdio.h>

int main() {
    int x = 5;
    int y = x+1;
    printf("Hello, World! %d\n", y);
    return 0;
}

/*
With the optimization flag, the compiler skips the unused declaration of x.

But when we print x, it is included even with optimization (makes sense)

When we declare and print y as x+1, it skips the x and just substitues a 5 for it when optimization is on.

So the optimization flag is preprocessing and interpretting our code to remove things that aren't used.

*/