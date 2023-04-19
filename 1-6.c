#include <stdio.h>

int main()
{
    int c;
    while(c = getchar() != EOF){
        printf("%d", c); /* you will get a 1 for every character */
    }

    printf("\n%d\n", c); /* you will get a 0 when you do CTLR-D */
}
