/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion */
#include <stdio.h>

/* print Fahrenheit-Celsius table 
    for fahr = 0, 20, ..., 300; */
float fahrToCelsius(float fahr);

int main()
{
    float fahr;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahrToCelsius(fahr));
        fahr = fahr + step;
    }
}

float fahrToCelsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}