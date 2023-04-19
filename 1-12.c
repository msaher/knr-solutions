#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* words that span multiple lare counted as seperate lines. Also words can
 * not have special characters in between them. For instance
 * "hello,world" is considred one word.*/

int main()
{
    int c, state = OUT;

    while ((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            putchar('\n');
        }
        else {
            state = IN;
            putchar(c);
        }
    }
}

