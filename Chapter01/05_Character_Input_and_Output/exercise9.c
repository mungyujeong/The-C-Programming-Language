/* Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
#include <stdio.h>

int main()
{
    int c;
    int last_char = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' && last_char == ' ')
            continue;
            
        putchar(c);
        last_char = c;
    }

    return 0;
}