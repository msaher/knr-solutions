#define BUFSIZE 100 
#include <stdio.h>

/* The solution is to change buf array to type int because EOF is
 * beyond char*/
 
int getch(void); 
void ungetch(int); 
int buf[BUFSIZE];    /* (changed to int) buffer for ungetch */ 
int bufp = 0;         /* next free position in buf */ 

int main() {
    return 0;
}

int getch(void)  /* get a (possibly pushed-back) character */ 
{ 
    return (bufp > 0) ? buf[--bufp] : getchar(); 
} 

void ungetch(int c)   /* push character back on input */ 
{ 
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n"); 
    else 
        buf[bufp++] = c; 
} 


