#include <stdio.h>
#define SIZE 100
#include <ctype.h>
#define getch() getc(stdin)
#define ungetch(c) ungetc(c, stdin)

void printarr(double[], double);
int getfloat(double*);

int main(void)
{
   int n; double array[SIZE]; 
   for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);
   printarr(array, SIZE);
}


/* int getch(void); */ 
/* void ungetch(int); */ 

/* getfloat:  get next integer from input into *pn */ 
int getfloat(double *pn) 
{ 
    int c, sign; 

    while (isspace(c = getch()))   /* skip white space */ 
        ; 
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') { 
        ungetch(c);  /* it is not a number */ 
        return 0; 
    } 
    sign = (c == '-') ? -1 : 1; 
    if (c == '+' || c == '-') 
        if(!isdigit(c = getch()) && c != '.') {
            ungetch(c); /* never mind, not a number */
            return 0;
        }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0'); 

    double power = 1.0;
    if(c == '.')
        while(isdigit(c = getchar())) {
            *pn = 10 * *pn + (c - '0');
            power *= 10;
        }

    *pn = sign * *pn / power;

    if (c != EOF) 
        ungetch(c); 
    return c; 
} 

void printarr(double arr[], double len)
{
    printf("Array { ");
    for(int i = 0; i < len; i++)
        printf(" %f", arr[i]);
    printf("}\n");
}

