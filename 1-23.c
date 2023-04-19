#include <stdio.h>
#define IN 1
#define OUT 0

int main() {

    int state = OUT;
    int q = 0; /* 0 means no qoute, 1 means single qoute, 2 means double qoutes*/
    int s = 0; /* means slash when state == OUT, but means star when state == IN */
    int bs = 0; /* back slash */
    int c;

    while((c = getchar()) != EOF) {
        if(state == OUT) {
            /* Entering and leaving qoutes */
            /* put */

            if(c == '/' && !s) {
                if(q == 0)
                    s = 1; /* don't put */
                else 
                    putchar(c);
            }

            else if(c == '\\') {
                putchar(c);
                bs = !bs; 
            }

            else if(c == '\'') {
                putchar(c);
                if(bs) bs = 0;
                else if(q != 2) q = !q;
            }

            else if(c == '\"') {
                putchar(c);
                if(bs) bs = 0;
                else if (q == 2) q = 0; else q = 2;
            }


            else if(s) {
                s = 0; /* we always want to exist s */
                if(c == '*') state = IN;
                else {putchar('/'); putchar(c); s = 0;}
            }

            else
                putchar(c);
        }

        /* don't put here  */
        else { /* state == IN */
            if(c == '*')
                s = 1;
            else if(c == '/' && s) {
                state = OUT;
                s = 0; /* resset s */
            }
            else
                s = 0;
        }

    }
    return 0;
}

/* while state is OUT */
/* read until you reach a ' " slash star */
/* if you reach a ' put everything until you reach a ' */
/* if you reach a " put everything until you reach a " */
/* if you reach a slash star don't put everything until you reach a slash star */
/* (inclusive) */
/* Bonus: remove white space as well */

/* while state is IN */
/* read until you reach a slash star  */
/* OUT */
