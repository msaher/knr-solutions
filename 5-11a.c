#include <stdio.h>
#include <ctype.h>
#define WIDTH 8
#define MAXINPUT 1000
#include "mem.c"
#include <stdlib.h>

/* the next tab stop is a designated position in the columns.
 * Everytime you insert a \t, you have to go the next tab stop.
 * For example, if WDITH = 4, we have the following tab rule
 * ----\t----\t----\t----\t----\t----\t----\t----\t */

int aredigits(char* s);

int main(int argc, char *argv[])
{
    int tab;
    int size = (--argc == 0) ? 1 : argc;
    int tablist[size];
    tablist[0] = WIDTH;

    ++argv; /* skip the program's name */
    for(int i = 0; i < argc; i++)
        if(!aredigits(argv[i])) {
            fprintf(stderr, "Non-integer arguement: %s\n", argv[i]);
            return 1;
        }
        else
            tablist[i] = atoi(argv[i]);

    int c;
    int i = 0;
    tab = tablist[i];
    while((c = getchar()) != EOF) {
        if(c == '\t') {
            while(tab-- != 0)
                putchar(' ');
            i = (i+1) % size;
            tab = tablist[i];
        }
        else {
            putchar(c);
            --tab;
            if(tab == 0 || c == '\n') {
                i = (i+1) % size;
                tab = tablist[i];
            }
        }
    }
        return 0;
}

int aredigits(char* s) {
    while(*s != '\0')
        if(!isdigit(*s++))
            return 0;
    return 1;
}
