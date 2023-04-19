#include <ctype.h> 
#include <stdio.h>

int main()
{
    double atof(char[]);
    char s[] = "123.45e-6";
    double f = atof(s);
    printf("%f\n", f);
    return 0;
}

/* atof:  convert string s to double */ 
double atof(char s[]) 
{ 
    double val, power; 
    int i; 
    double sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */ 
        ; 
    sign = (s[i] == '-') ? -1 : 1; 
    if (s[i] == '+' || s[i] == '-') 
        i++; 
    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + (s[i] - '0'); 
    if (s[i] == '.') 
        i++; 
    for (power = 1.0; isdigit(s[i]); i++) { 
        val = 10.0 * val + (s[i] - '0'); 
        power *= 10; 
    } 

    val = sign * val / power; 
    if (s[i] == 'e' || s[i] == 'E') 
        i++;
    else
        return val;

    sign = (s[i] == '-') ? 0.1 : 10.0; 
    if (s[i] == '+' || s[i] == '-') 
        i++;

    for (power = 0; isdigit(s[i]); i++)
        power = 10.0 * power + (s[i] - '0'); 

    /* Note: We could do this more efficiently using a recursive pow
     * function*/
    while(power-- != 0)
        val *= sign;

    return val;
} 
