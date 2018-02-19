#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#define BUFSIZE 100

/*
I found that I got a bit bogged down in finding the "right" library functions for everything.
They may have saved time in the end, but digging through documentation was tedious and if I 
had a better handle on what is common in writing simple functions, I would have found what I was
looking for much quicker.

The professional implementation seems to be more concise in many ways, often sacrificing readability
for elegence. At the same time, it is a much more comprehensive solution which handles many more edge cases
that I didn't really think about. It also relies on even more obscure library functions than those that I found.
*/

void no_int_handler(int sig_num);

int main(int argc, char *argv[])
{
    int append = 0;
    int no_interrupt = 0;
    int i;
    char ch;
    char buffer[BUFSIZE];

    while ((ch = getopt(argc, argv, "ai")) != EOF)
        switch (ch) {
        case 'a': 
            append = 1;
            break;
        case 'i':
            no_interrupt = 1;
            break;
        }

    argc -= optind;
    argv += optind;

    if (no_interrupt)
        signal(SIGINT, no_int_handler);

    FILE *files[argc-1];

    for (i=0; i<argc; i++)
        files[i] = fopen(argv[i], append ? "a" : "w");

    while (NULL != fgets(buffer, BUFSIZE, stdin)) {
        for (i=0; i<argc; i++) {
            fprintf(files[i], "%s", buffer);
        }
        printf("%s", buffer);
    }


    for (i=0; i<argc; i++)
        fclose(files[i]);
}

void no_int_handler(int sig_num) {
    signal(SIGINT, no_int_handler);
    printf("\nNo quitting! Press ^D to end\n");
}
