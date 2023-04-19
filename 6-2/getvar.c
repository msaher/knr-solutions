#include "getword.h"
#include "binsearch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "getvar.h"
/* #define iskeyword(v) (binsearch(((v)), (void**) keywords, sizeof(keywords)/sizeof(char*), (int (*)(void*, void*)) strcmp) != -1) */

/* int iskeyword(char* v); */
/* int getvar(char* v, int lim); */

/* Don't forget to put sort them! That was annoying to debug :( */
char* keywords[] = {"auto", "break", "case", "char", "const",
    "continue", "default", "do", "double", "else", "enum", "extern",
    "float", "for", "goto", "if", "int", "long", "register", "return",
    "short", "signed", "sizeof", "static", "struct", "switch",
    "typedef", "union", "unsigned", "void", "volatile", "while" };


/* int main(int argc, char* argv[]) */
/* { */
/*     char* v; */
/*     while(getvar(v, MAXWORD) != EOF) */
/*         printf("%s\n", v); */
/*         /1* printf("Varaiable: %s\n", v); *1/ */

/*     return 0; */
/* } */

/* I rarely ever use gotos, I want to try them out */
int getvar(char* v, int lim)
{
    int c;

loop:
    do {
        c = getword(v, lim);

    } while((!(isalpha(c) || c == '_') || iskeyword(v)) && c != EOF);

    if((c = getch()) == '(') /* false positive. v is a function! */
        goto loop;
        /* printf("Let me guess, %s is a function?\n", v); */
    else
        ungetch(c);

    return c;
}

int iskeyword(char* v)
{
    return (binsearch(v, (void**) keywords, sizeof(keywords)/sizeof(char*), (int (*)(void*, void*)) strcmp) != -1);
}
