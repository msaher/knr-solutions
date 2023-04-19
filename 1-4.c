#include <stdio.h>
/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */

/* I don't like this solution. It difficult to
 * extend. I know we haven't taken functions yet, so maybe thats why
 * the authors are doing it this way */
int normalSolution()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;

    /* lower limit of temperatuire scale */
    /* upper limit */
    /* step size */
    fahr = lower;
    printf("Fahrenheit-Celsius table\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    celsius = lower;
    printf("Celsius-Fahrenheit table\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

}

int main()
{
    return normalSolution();
}
