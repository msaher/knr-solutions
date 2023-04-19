#include <stdio.h>
#include <ctype.h>
#define getch() getc(stdin)
#define ungetch(c) ungetc(c, stdin)
#define MAXWORD 100
#define IN 1
#define OUT 0

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

    while (isspace(c = getch()));
    if(c == EOF) {
        *w = '\0';
        return c;
    }

    if (!isalpha(c) && c != '_' && c != '/' && c != '"' && c != '\'') {
        *w++ = c;
        *w = '\0';
        return c;
    }

    int comment = OUT;
    int qoutechar = 0;
    if(c == '/')
        if((c = getch()) == '*')
            comment = IN;
        else {
            ungetch(c);
            *w++ = '/';
            *w = '\0';
            return '/';
        }
    else if(c == '\'' || c == '"')
        qoutechar = c;

    else
        *w++ = c;

    while(comment == IN) {
        while((c = getch()) != '*' && c != EOF);
        if((c = getch()) == '/')
            comment = OUT;
        else if(c == EOF)
            return c;
    }

    if(qoutechar != 0) {
        while((c = getch()) != qoutechar && c != EOF);
        if(c == EOF)
            return c;
    }

    for(; --lim > 0; w++) {
        if(!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0'; 
    return word[0];
} 
