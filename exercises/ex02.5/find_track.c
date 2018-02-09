/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Uses regex.h library functions: regcomp compiles the
// regex expression, then regexec executes it on each of
// the tracks in order. Prints track number and title on
// match, and exits and reports on errors encountered
void find_track_regex(char pattern[])
{
    int i;
    int status;
    regex_t re;
    char buffer[80];

    status = regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB);
    if (status != 0) {
        printf("Could not compile regex\n");
        exit(1); 
    }
    for (i=0; i<NUM_TRACKS; i++) {
        status = regexec(&re, tracks[i], (size_t) 0, NULL, 0);
        if (status == REG_NOMATCH)
            continue;
        else if (status == 0)
            printf("Track %i: '%s'\n", i, tracks[i]);
        else {
            regerror(status, &re, buffer, sizeof(buffer));
            printf("Match failed: %s\n", buffer);
            exit(1);
        }
    }
    regfree(&re);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    // find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
