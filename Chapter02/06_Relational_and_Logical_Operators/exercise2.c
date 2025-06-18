/*
Write a loop equivalent to the for loop above without using && or ||.
*/

#include <stdio.h>

int main()
{
    int c, i;
    int lim = 10;
    char s[lim];

    for (i = 0; i < lim - 1; i++) {
        c = getchar();
        if (c == EOF) 
            break;
        
        if (c == '\n') {
            s[i] = c;
            i++;
            break;
        }
        s[i] = c;
    }

    printf("Input line: %s", s);
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}