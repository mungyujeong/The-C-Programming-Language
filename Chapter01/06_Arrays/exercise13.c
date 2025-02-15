/* Write a program to print a histogram of the lengths of words in its input.
   It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */
#include <stdio.h>

#define IN      1
#define OUT     0
#define MAX_LEN 20

int main()
{
    int c, state, i, j, length, max_length;
    int wordLength[MAX_LEN];

    for (i = 0; i < MAX_LEN; ++i)
        wordLength[i] = 0;
    length = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
                ++wordLength[length];
                if (wordLength[length] > max_length)
                    max_length = wordLength[length];
                length = 0;
            }
        }
        else {
            state = IN;
            ++length;
        }
    }

    printf("Histogram of the lengths of words in its input (horizontal)\n");
    for (i = 0; i < MAX_LEN; ++i) {
        printf("%d: ", i);
        for (j = 0; j < wordLength[i]; ++j)
            printf("*");
        printf("\n");
    }

    printf("Histogram of the lengths of words in its input (vertical)\n");
    for (i = max_length; i >= 0; --i) {
        for (j = 0; j < MAX_LEN; ++j) {
            if (i == 0) 
                printf("%d\t", j);
            else if (wordLength[j] == i) {
                printf("*\t");
                --wordLength[j];
            }
            else
                printf("\t");
        }
        printf("\n");
    }

    return 0;
}