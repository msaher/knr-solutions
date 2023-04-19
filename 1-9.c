#include <stdio.h>

int restrictedSolution()
{
    int c, wasblnk = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ')
        {
            if(wasblnk == 0)
            {
                wasblnk = 1;
                putchar(c);
            }
        }

        /* can't use else */
        if(c != ' ') {
            wasblnk = 0;
            putchar(c);
        }
    }
}

int betterRestrictedSolution(){

    int c, pc = EOF;
    while((c = getchar()) != EOF){
        if(c == ' ')
            if(pc != ' ')
                putchar(c);
        pc = c;
        if(c != ' ')
            putchar(c);
    }
}

int betterSolution()
{
    int c, wasblnk = 0;

    while((c = getchar()) != EOF){
        if(c == ' ')
            if(!wasblnk) {
                wasblnk = 1;
                putchar(c);
            }
        else {
            wasblnk = 0;
            putchar(c);
        }
    }
}

/* I've realized this is done more elegantly using loops*/
int loopSolution()
{
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
        if(c == ' '){
            do {
                c = getchar();
            } while(c == ' ');
            putchar(c);
        }
    }
}

int main()
{
    return
    /* restrictedSolution(); */
    /* betterSolution(); */
        /* loopSolution(); */
    betterRestrictedSolution();

}
