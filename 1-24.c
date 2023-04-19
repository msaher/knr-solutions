#include <stdio.h>
#define OUT 0
#define IN 1

int main() {
    int state = OUT;
    int paren = 0; int brack = 0; int brace = 0;
    int q = 0;
    int pc = EOF; int c;
    int bs = 0; /* back slash */

    while((c = getchar()) != EOF) {
        if(state == OUT) {

            if(c == '\\')
                bs = !bs;

            /* comments */
            else if(pc == '/' && c == '*' ) state = IN;

            else if(q == 0 && !bs) { /* ignore back slashes */

                     if(c == '(') paren++; else if(c == ')') paren--;
                else if(c == '{') brace++; else if(c == '}') brace--;
                else if(c == '[') brack++; else if(c == ']') brack--;

                /* ' " */
                else if(c == '\'') q = 1;
                else if(c == '\"') q = 2;

            }

            else if(q == 1) {
                if(bs) bs = 0;
                else if(c == '\'') q = 0;
            }

            else if(q == 2) {
                if(bs) bs = 0;
                else if(c == '\"') q = 0;
            }

        }

        /* state == IN */
        else if(pc == '*' && c == '/')
            state = OUT;

        pc = c;
    }

    printf("paren = %d brack = %d brace = %d q = %d\n, state = %d", paren, brack, brace, q, state);
    return 0;
}
