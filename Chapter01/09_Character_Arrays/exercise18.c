/* Write a program to remove trailing blacnks and tabs from each line of input, 
   and to delete entirely blank lines. */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);
void removeBlanksAndTabs(char line[], int len);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        removeBlanksAndTabs(line, len);
        if (line[0] != '\0')
            printf("%s\n", line);
    }
    return 0;
}

/* getLine: read a line into s, return length */
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

void removeBlanksAndTabs(char s[], int len)
{
    int i = len - 1; // skip null character '\0'

    while (i >= 0 && s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        --i;
    s[i+1] = '\n';
    s[i+2] = '\0';
}