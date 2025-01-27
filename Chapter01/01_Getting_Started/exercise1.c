// Run the "hello world" program on your system. Experiment with leaving out
// parts of the program, to see what error messages you get.
#include <stdio.h>

int main() 
{
    printf("hello world
    ");
}

/*
exercise1.c:5:12: warning: missing terminating '"' character [-Winvalid-pp-token]
    5 |     printf("hello world
      |            ^
exercise1.c:5:12: error: expected expression
exercise1.c:6:5: warning: missing terminating '"' character [-Winvalid-pp-token]
    6 |     ");
      |     ^
exercise1.c:7:2: error: expected '}'
    7 | }
      |  ^
exercise1.c:4:1: note: to match this '{'
    4 | {
      | ^
2 warnings and 2 errors generated.
*/