#include <stdio.h>

float celsius2fahr(float c);
float fahr2celsius(float f);

float celsius2fahr(float celsius)
{
    float fahr = (9.0/5.0) * celsius + 32.0;
    return fahr;
}

float fahr2celsius(float fahr)
{
    float celsius = (5.0/9.0) * (fahr-32.0);
    return celsius;
}

void solution()
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
        celsius = celsius2fahr(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    celsius = lower;
    printf("Celsius-Fahrenheit table\n");
    while (celsius <= upper) {
        fahr = fahr2celsius(celsius);
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

}

int main()
{
    solution();
    return 0;
}
