/*
Write a program to determine the ranges of char, short, int, and long variables,
both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges
of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Ranges of integer types:\n");
    printf("char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %d\n", UCHAR_MAX);
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %d\n", USHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    printf("\nRanges of floating-point types:\n");
    printf("float: %.10e to %.10e\n", FLT_MIN, FLT_MAX);
    printf("double: %.10e to %.10e\n", DBL_MIN, DBL_MAX);
    printf("long double: %.10Le to %.10Le\n", LDBL_MIN, LDBL_MAX);

    return 0;
}