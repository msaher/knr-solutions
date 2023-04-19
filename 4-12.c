#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void itoa_helper(unsigned int, char[], int[]);
void reverse(char s[]);

int main(void)
{
    int n = INT_MIN;
    char s[256];
    itoa(n, s);
    printf("n = %d\n", n);
    printf("s = %s\n", s);
    return 0;
}


/* Using static varaibles: */ 
/* void itoa(int n, char s[]) */ 
/* { */
/*     static int i = 0; */
/*     if(i == 0 && n < 0) { */
/*         n = -n; */
/*         s[i++] = '-'; */
/*     } */

/*     else if(n / 10) */
/*         itoa(n / 10, s); */

/*     s[i++] = n % 10 + '0';  /1* get next digit *1/ */ 
/*     s[i] = '\0'; */
/* } */

void itoa(int n, char s[])
{
    unsigned int un;
    int i = 0;
    if(n < 0) {
        un = -n;
        s[i++] = '-';
    }
    else
        un = n;
    int index[] = {i};
    itoa_helper(un, s, index);
}

void itoa_helper(unsigned n , char s[], int index[])
{
    if(n / 10)
        itoa_helper(n / 10, s, index);
    s[index[0]++] = n % 10 + '0';  /* get next digit */ 
    s[index[0]] = '\0';

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

