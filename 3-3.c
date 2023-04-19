#include <stdio.h>
#include <string.h>

void expand(char[], char[]);

int main() {
    char s1[] = "-a-b-c\na-z\nA-z\nz-a\na-a\n4-9\n4-10\n";
    char s2[256];
    expand(s1,s2);
    printf("%s\n", s1);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[]) {
    int i = 0; int j = 0;
    char c;
    short d = 0; /* 1 means previous character was a dash */
    char pc = '\0'; /* previous non-dash character */
    /* interpret leading dash literally */
    if(s1[0] == '-') {
        s2[j++] = '-';
        ++i;
    }

    while((c = s1[i++]) != '\0') {
        if(c == '-') {
            d = 1;
            continue;
        }
        if(d) {
            d = 0;
            /* add the interval [a+1, b] (as `a' was added in the previous iteration) */
            char a = pc, b = c;
            if(b >= a &&
                    (a >= 'a' && b <= 'z' ||
                     a >= 'A' && b <= 'Z' ||
                     a >= '0' && b <= '9'))
                while(a < b)
                    s2[j++] = ++a; /* offset by 1 */
            else {
                s2[j++] = '-'; s2[j++] = c;
                pc = c;
            }
        }
        else
            s2[j++] = c;
        pc = c;
    }
    if(d) /* trailling dash */
        s2[j++] = '-';
    s2[j] = '\0';
}

/* dumb debugging... ignore */
/* printf("condition is %d\n", */ 
/*         b >= a && */
/*         (a >= 'a' && b <= 'z' || */
/*          a >= 'A' && b <= 'Z' || */
/*          a >= '0' && b <= '9')); */

/* printf("a is %c\n", a); */
/* printf("b is %c\n", b); */

