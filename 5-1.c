#include <stdio.h>
#define SIZE 100
#include <ctype.h>
#define getch() getc(stdin)
#define ungetch(c) ungetc(c, stdin)

void printarr(int[], int);
int getint(int*);

int main(void)
{
   int n, array[SIZE], getint(int *); 
   for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++);
   printarr(array, SIZE);
}


/* int getch(void); */ 
/* void ungetch(int); */ 

/* getint:  get next integer from input into *pn */ 
int getint(int *pn) 
{ 
    int c, sign; 

    while (isspace(c = getch()))   /* skip white space */ 
        ; 
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') { 
        ungetch(c);  /* it is not a number */ 
        return 0; 
    } 
    sign = (c == '-') ? -1 : 1; 
    if (c == '+' || c == '-') 
        if(!isdigit(c = getch())) {
            ungetch(c); /* never mind, not a number */
            return 0;
        }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0'); 
    *pn *= sign; 
    if (c != EOF) 
        ungetch(c); 
    return c; 
} 

void printarr(int arr[], int len)
{
    printf("Array { ");
    for(int i = 0; i < len; i++)
        printf(" %d", arr[i]);
    printf("}\n");
}
