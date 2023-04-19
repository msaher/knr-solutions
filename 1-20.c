#include <stdio.h>
#define WIDTH 8;

/* the next tab stop is a designated position in the columns.
 * Everytime you insert a \t, you have to go the next tab stop.
 * For example, if WDITH = 4, we have the following tab rule
 * ----\t----\t----\t----\t----\t----\t----\t----\t */

int main()
{
    int c;
    int tab = WIDTH;
    while((c = getchar()) != EOF)
        if(c == '\t') {
            while(tab-- != 0)
                putchar(' ');
            tab = WIDTH;
        }
        else {
            putchar(c);
            --tab;
            if(tab == 0 || c == '\n')
                tab = WIDTH;
        }
    return 0;
}
