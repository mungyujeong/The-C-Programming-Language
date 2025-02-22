/* Write a program entab that replaces strings of blanks by the minimum
   number of tabs and blanks to achieve the same spacing. Use the same
   tab stops as for detab. When either a tab or a single blank would 
   suffice to reach a tab stop, which should be given preference? */
// => A single blank should be given preference, because it is easier to manage
#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 10

int getLine(char line[], int len);
void entab(char entabLine[], char line[]);

int main()
{
    char line[MAXLINE];
    char entabLine[MAXLINE];
    int len;

    while ((len = getLine(line, MAXLINE)) > 0) {
        entab(entabLine, line);
        printf("%s", entabLine);
    }
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

void entab(char to[], char from[])
{
    int i, j, k, blanks, tabs;

    i = j = 0;
    while (from[i] != '\0') {
        if (from[i] == ' ') {
            blanks = 0;
            while (from[i] == ' ') {
                ++blanks;
                ++i;
            }

            tabs = blanks / TABSTOP;
            blanks = blanks % TABSTOP;
            for (k=0; k < tabs; ++k)
                to[j++] = '\t';
            for (k=0; k < blanks; ++k)
                to[j++] = ' ';
        }
        else to[j++] = from[i++];
    }
    to[j] = '\0';
}