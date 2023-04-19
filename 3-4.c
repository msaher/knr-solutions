#include <stdio.h>
#include <limits.h>
#include <string.h>

/* I decided to extract the first negative digit manually instead of
 * worrying wether something like -10 % 3 is 1 or -1 as it might
 * depend on the compiler */

void itoa(int n, char s[]);
void reverse(char s[]);

/* itoa will not work in twos complement because of the asymmetry
 * between postives and negatives. The largest positive number is
 * abs(largest negative) - 1. The line `n = -n' will fail */

int main() {

    int n = INT_MIN;
    char s[256];
    itoa(n, s);
    printf("n = %d\n", n);
    printf("s = %s\n", s);
    return 0;
}

/* itoa:  convert n to characters in s */ 
void itoa(int n, char s[]) 
{ 
    int i, sign, m; 
    i = 0;

    m = n;
    /* Extract the first digit from a negative number manually */
    if ((sign = n) < 0) {  /* record sign */ 
        m /= 10; m = -m;
        s[i++] = -1*(n+10*m) + '0'; /* Extract the first digit only */
    }
    do {      /* generate digits in reverse order */ 
        s[i++] = m % 10 + '0';  /* get next digit */ 
    } while ((m /= 10) > 0);    /* delete it */ 
    if (sign < 0) 
        s[i++] = '-'; 
    s[i] = '\0'; 
    reverse(s); 
} 

/* reverse:  reverse string s in place */ 
void reverse(char s[]) 
{ 
    int c, i, j; 
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) { 
        c = s[i]; 
        s[i] = s[j]; 
        s[j] = c; 
    } 
} 
