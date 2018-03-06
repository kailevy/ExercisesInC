## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/kailevy/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

The 128 is represented as 0b10000000. If we applied sign extension we would get 0b1111111110000000, which could be interpretted as 65408 or -128 in 2's complement.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

0b01100^0b11111+0b1 = 0b10100

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

The bias in the exponent is probably to make it easier to represent negative exponents easier, and therefore fractions.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

0b11000001010100000000000000000000. This would be interpretted as 1095761920 as an integer.

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

```
char ** lower_to_upper(char *s) {
    l = strlen(s);
    r = malloc(l * sizeof(char));
    for (i=0; i<l; i++)  {
        r[i] = flip_6th(s[i]);
    }
    return r;
}

char flip_6th(char lower) {
    return lower^0b100000;
}
```
