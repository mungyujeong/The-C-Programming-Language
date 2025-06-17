/* Write a program to remove all comments from a C program. Don't forget 
   to handle quoted strings and character constants properly. C comments 
   don't nest. */
#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int len);
void removeComments(char line[]);

int inComment;

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = getLine(line, MAXLINE)) > 0) {
        removeComments(line);
        printf("%s", line);
    }
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void removeComments(char s[])
{
    int i;
    extern int inComment;

    inComment = 0;
    for (i=0; s[i] != '\n'; ++i) {
        if (s[i] == '/') {
            if (s[i+1] == '/')
                return;
            if (s[i+1] == '*')
                inComment = 1;
        }
        else if (s[i] == '*') {
            if (s[i+1] == '/')
                inComment = 0;
        }
    }
}