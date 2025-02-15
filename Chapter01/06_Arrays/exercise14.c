/* Write a program to print a histogram of the frequencies of different characters in its input */
#include <stdio.h>

#define IN  1
#define OUT 0
#define ASCII_SIZE 128

int main()
{
    int c, i, j;
    int charFreq[ASCII_SIZE];

    for (i = 0; i < ASCII_SIZE; ++i)
        charFreq[i] = 0;

    while ((c = getchar()) != EOF)
        if (c > 0 && c < ASCII_SIZE)
            ++charFreq[c];

    printf("Histogram of the frequencies of different characters in its input\n");
    for (i = 0; i < ASCII_SIZE; ++i) {
        if (charFreq[i]) {
            if (i == '\n')
                printf("\\n: ");
            else if (i == '\t')
                printf("\\t: ");
            else if (i == '\b')
                printf("\\b: ");
            else if (i == '\r')
                printf("\\r: ");
            else if (i == '\\')
                printf("\\\\: ");
            else if (i == ' ')
                printf("space: ");
            else
                printf("%c: ", i);
            for (j = 0; j < charFreq[i]; ++j)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}