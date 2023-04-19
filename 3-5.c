#include <stdio.h>
#include <limits.h>
#include <string.h>

/* I decided to extract the first negative digit manually instead of
 * worrying wether something like -10 % 3 is 1 or -1 as it might
 * depend on the compiler */

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {

    int n = INT_MIN;
    char s[256];
    itob(n, s, 8);
    printf("n = %d\n", n);
    printf("s = %s\n", s);
    return 0;
}

/* itob:  convert n to characters in s */ 
void itob(int n, char s[], int b) 
{ 
    int i, sign, m, d; 
    i = 0;
    m = n;
    /* Extract the first digit from a negative number manually */
    if ((sign = n) < 0) {  /* record sign */ 
        m /= b; m = -m;
        d = -1*(n+b*m);
        s[i++] = d + '0' + (d < 10 ? 0 : 7) ; /* Extract the first digit only */
    }
    do {      /* generate digits in reverse order */ 
        d = m % b;
        s[i++] = d + '0' + (d < 10 ? 0 : 7) ; 
    } while ((m /= b) > 0);    /* delete it */ 
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
