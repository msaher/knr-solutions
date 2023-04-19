#include <stdio.h>

int main()
{
    int c;
    while((c = getchar()) != EOF) {
        /* I miss swith statements :( */
        if(c == '\b')
            printf("\\b");
        if(c == '\\')
            printf("\\");
        if(c == '\t')
            printf("\\t");

        /* I miss else :( */
        if(c != '\b')
            if (c != '\\')
                if(c != '\t')
                    putchar(c);
    }
}

