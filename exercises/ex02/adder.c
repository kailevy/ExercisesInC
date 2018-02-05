#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10
#define BUFLEN 8



int get_word(char buf[]);
int add(int arr[], int len);


int main()
{
    int arr[SIZE];
    long lnum;
    char *end;
    int arrp = 0;
    char buf[BUFLEN];
    while (get_word(buf) == 0)
    {
        if (arrp > SIZE) {
            printf("error: exceeded array length");
            break;
        }
        // I didn't like the interface of atoi since it couldn't tell the difference between 0 and error, so I used code similar to seen here
        // https://stackoverflow.com/questions/8871711/atoi-how-to-identify-the-difference-between-zero-and-error
        lnum = strtol(buf, &end, 10);
        if (end == buf) {
            printf("error: cannot convert input to number\n");
            continue;
        }
        if ((lnum == LONG_MAX || lnum == LONG_MIN) )  {
            printf("error: number out of range\n");
            continue;
        }
        if ( (lnum > INT_MAX) || (lnum < INT_MIN) ) {
            printf("error: number out of range\n");
            continue;
        }
        else {
            arr[arrp++] = (int) lnum;
        }
    }
    printf("total: %d\n", add(arr, arrp));
}

/*
This function fills a character buffer and detects buffer overflows
*/
int get_word(char buf[])
{
    int bufp = 0;
    char c = 0;
    while (c != EOF) {
        c = getchar();
        if (c == '\n') {
            buf[bufp++] = '\0';
            return 0;
        }
        if (bufp >= BUFLEN) {
            printf("error: buffer overflow\n");
            return 0;
        }
        buf[bufp++] = c;
    }
    return 1;
}

/*
This function adds the numbers stored in the array
*/
int add(int arr[], int len)
{   
    int tot = 0;
    for (int i=0; i<len; i++) {
        tot += arr[i];
    }
    return tot;
}