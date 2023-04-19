#include <stdio.h>
#include <ctype.h>
#define getch() getc(stdin)
#define ungetch(c) ungetc(c, stdin)
#include "globals.h"

int getword(char *word, int lim);

/* int main() */
/* { */
/*     /1* char* word; *1/ */
/*     /1* int lim = MAXWORD; *1/ */
/*     /1* getword(word, lim); *1/ */
/*     /1* printf("%s\n", word); *1/ */
/*     /1* return 0; *1/ */

/*     char* word; */
/*     int lim = MAXWORD; */
/*     while(getword(word, lim) != EOF) */
/*         printf("%s\n", word); */
/*     return 0; */

/* } */

/* getword:  get next word or character from input */ 
int getword(char *word, int lim) 
{ 
    int c; 
    char *w = word; 

    while (isspace(c = getch()))
        if(c == '\n')
            linenumber++;
    if (c != EOF) 
        *w++ = c; 
    if (!isalpha(c)) { 
        *w = '\0'; 
        return c; 
    } 
    for ( ; --lim > 0; w++) 
        if (!isalnum(*w = getch())) { 
            ungetch(*w); 
            break; 
        } 
    *w = '\0'; 
    return word[0]; 
} 
