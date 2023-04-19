#include <stdio.h>
#include <ctype.h>
#define WIDTH 8
#define MAX 1000
#include "mem.c"
#include <stdlib.h>
#include "atoi_valid.c"
#define complain(c, x) fprintf(stderr, "Error: Non-integer %c" #x " value %s. Ignoring...\n", c, *argv+1)

/* the next tab stop is a designated position in the columns.
 * Everytime you insert a \t, you have to go the next tab stop.
 * For example, if WDITH = 4, we have the following tab rule
 * ----\t----\t----\t----\t----\t----\t----\t----\t */

int aredigits(char* s);

int main(int argc, char *argv[])
{
    int n = WIDTH; /*  stop every n columns */
    int m = WIDTH; /*  starting from column m */
    int c;
    while(--argc > 0) {
        c = (*++argv)[0];
        if(c == '-') {
            if(!atoi_valid(*argv+1, &m))
                complain(c, m);
        }
        else if(c == '+')
            if(!atoi_valid(*argv+1, &n))
                complain(c, n);
    }
    
    int tab = m;
    while((c = getchar()) != EOF) {
        if(c == '\t') {
            while(tab-- != 0)
                putchar(' ');
            tab = n;
        }
        else {
            putchar(c);
            --tab;
            if(tab == 0 || c == '\n')
                tab = n;
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
