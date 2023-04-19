#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* words that span multiple lare counted as seperate lines. Also words can
 * not have special characters in between them. For instance
 * "hello,world" is considred one word.*/

int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
