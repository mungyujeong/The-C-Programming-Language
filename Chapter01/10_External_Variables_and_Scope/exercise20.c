/* Write a program detab that replaces tabs in the input with the proper number
   of blanks to space to the next tab stop. Assume a fixed set of tab stops, 
   say every n columns. Should n be a variable or a symbolic parameter? */
// => n should be a symbolic parameter, because it is a constant value that should
#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 10

int getLine(char line[], int len);
void detab(char detabLine[], char line[]);

int main()
{
    char line[MAXLINE];
    char detabLine[MAXLINE];
    int len;

    while ((len = getLine(line, MAXLINE)) > 0) {
        detab(detabLine, line);
        printf("%s", detabLine);
    }
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i, j;
    
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void detab(char to[], char from[])
{
    int i, j, k;

    i = j = 0;
    while (from[i] != '\0') {
        if (from[i] == '\t') {
            for (k=0; k < TABSTOP; ++k)
                to[j++] = ' ';
        }
        else to[j++] = from[i];
        ++i;
    }
    to[j] = '\0';
}