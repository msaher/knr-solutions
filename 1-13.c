#include <stdio.h>
#define OUT 0
#define IN 1
#define MAXWORDS 15

/* I'm using the book's defintion of a word 
 * This solution is not limited to any number of words. It will show
 * the hologram after every line  */
int sol()
{
    int c, l = 0, state = OUT;

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            if(l != 0) {
                printf(": %d ", l);
                for(; l != 0; l--) /* should be replaced with a do-while */
                    printf("|");
                putchar('\n');
            }
        }
        else {
            state = IN;
            ++l;
            /* Uncommnet this if you want to see words */
            /* putchar(c); */
        }
    }

}

/* The book probably wants me to use arrays. I prefer not using them
 * because they're limited to a predefined number of words */
int altsol()
{
    int c = 0;
    int lenarr[MAXWORDS];
    int i;
    int state = OUT;

    /* clear array */
    for(i = 0; i < MAXWORDS; i++)
        lenarr[i] = 0;

    i = 0;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            i++;
        }
        else {
            state = IN;
            lenarr[i]++;
        }
    }

    int j;
    for(i = 0; i < MAXWORDS; i++){
        for(j = 0; j < lenarr[i]; j++)
            putchar('|');
        putchar('\n');
    }

}

int main()
{
    return 
        /* sol(); */
        altsol();
}

