/* Write a program to "fold" long input lines into two or more shorter 
   lines after the last non-blank character that occurs before the n-th 
   column of input. Make sure your program does something intelligent with 
   very long lines, and if there are no blanks or tabs before the 
   specified column. */
#include <stdio.h>

#define MAXLINE 1000
#define FOLD 72

int getLine(char line[], int len);
void fold(char line[]);

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = getLine(line, MAXLINE)) > 0) 
        fold(line);
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

void fold(char s[])
{
    int i, j, k, lastBlank, idx;
    char temp[FOLD];

    lastBlank = -1;
    for (i=0, j=1; s[i] != '\n'; ++i, ++j) {
        temp[j - 1] = s[i];
        if (s[i] == ' ' || s[i] == '\t') {
            lastBlank = j - 1;
            idx = i;
        }
        if (j % FOLD == 0) {
            if (lastBlank == -1) {
                for (k=0; k < FOLD; ++k)
                    putchar(temp[k]);
            }
            else {
                for (k=0; k <= lastBlank; ++k)
                    putchar(temp[k]);
                i = idx;
            }
            j = 0;
            lastBlank = -1;
            putchar('\n');
        }
    }
    for (k=0; k < j - 1; ++k)
        putchar(temp[k]);
    putchar('\n');
}
