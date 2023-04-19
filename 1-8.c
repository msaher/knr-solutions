#include <stdio.h>

int main()
{
    int c, whites = 0;

    while((c = getchar()) != EOF) {
        /* I'm not using || because the book didn't introduce it yet */
        if(c == ' ')
            ++whites;;
        if(c == '\n' )
            ++whites;
        if(c == '\t')
            ++whites;
    }

    printf("%d\n", whites);

}
