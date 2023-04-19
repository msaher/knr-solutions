#include <stdio.h>
#include "mygetline.c"
#define MAX 1000

int lamegetline(char s[], int lim);

int main() {

    char line[MAX];
    printf("%d\n", lamegetline(line, MAX));
    printf("%d\n", mygetline(line, MAX));

    while(lamegetline(line, MAX) > 0)
        printf("%s", line);
    return 0;
}

/* We really do take logical operators for granted */
int lamegetline(char s[], int lim)
{
    int c, i = 0; /* don't forget to set i to zero */
    int cont = 1; /* continue */
    while(cont) {

        if(i >= lim-1)
            cont = 0;
        else
            if((c = getchar()) != EOF)
                if(c != '\n')
                    s[i++] = c;
                else
                    cont = 0;
            else
                cont = 0;
    }

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}


/* for(i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) */

