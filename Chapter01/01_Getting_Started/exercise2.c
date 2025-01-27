// Experiment to find out what happens when prints's argument string contains
// \c, where c is some character not listed above.
#include <stdio.h>

int main() 
{
    printf("hello, world\c");
}

/*
exercise2.c:7:25: warning: unknown escape sequence '\c' [-Wunknown-escape-sequence]
    7 |     printf("hello, world\c");
      |                         ^~
1 warning generated.
*/