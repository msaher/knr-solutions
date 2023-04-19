#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "hashtable.h"
#include "getword.h"
#define DEFINE "define"
#define MAXLINE 1000
#define FAILURE 0
#define SUCCESS 1

/* getrestline: store the rest of the line in line */
void getrestline(char line[])
{
    int c;
    int i = 0;
    while((c = getch()) != '\n' && c != EOF)
        line[i++] = c;
    line[i] = '\0';
}

/* flushline: Ignore line*/
void flushline(void)
{
    int c;
    while((c = getch()) != '\n' && c != EOF);
}

int isvalidvar(char *s)
{
    if(isdigit(*s) || *s == '\0')
        return 0;

    do {
        if(!isalnum(*s) && *s != '_')
            return 0;
    } while(*++s != '\0');

    return 1;

}

int getdefine(char *key, char* val, int *sig)
{
    int c = getch();
    if(c != '#') {
i_want_to_try_gotos_more:
        return c;
    }

    char* dummy = key; /* I'm just using key as a dummy place to
                           store words to avoid allocating memoery */
    getword(dummy, MAXWORD);
    if(strcmp(dummy, DEFINE) != 0)
        goto i_want_to_try_gotos_more;

    /* printf("dummy is %s\n", dummy); */
    getword(key, MAXWORD);
    /* printf("key is %s\n", key); */
    if(!isvalidvar(key))
        goto i_want_to_try_gotos_more;

    /* printf("is key valid? %d\n", isvalidvar(key)); */
    while(isspace(c = getch()))
        if(c == '\n') {
            /* printf("a new line\n"); */
            ungetch(c);
            return c;
        }

    ungetch(c); /* first non-space character */

    getrestline(val);
    *sig = SUCCESS;
    return c;
}

int main(int argc, char* argv[])
{
    char key[MAXWORD];
    char val[MAXWORD];
    int sig = 0;
    int c;
    while((c = getdefine(key, val, &sig)) != EOF) {
        if(sig == SUCCESS) {
            printf("Installing %s and %s\n", key, val);
            install(key, val);
            sig = FAILURE;
        }
        else
            while((c = getch()) != '\n' && c != EOF); /* flush line */
    }
    printf("Hash:\n");
    printf("-------\n");
    printhash();
    return 0;
}
