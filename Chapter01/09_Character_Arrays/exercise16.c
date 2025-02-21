/* Revise the main routine of the longest-line program so it will correctly
   print the length of arbitrary long input lines, and as much as possible 
   of the text. */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */
    int temp_len;
    char temp[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (line[len - 1] != '\n') {
            while ((temp_len = getLine(temp, MAXLINE)) && temp[temp_len - 1] != '\n')
                len += temp_len;
            len += temp_len;
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) { /* there was a line */
        printf("length of longest line: %d\n", max);
        printf("%s", longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}