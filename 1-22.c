#include <stdio.h>
#define WIDTH 80
#define TAB 8

int rem(int p, int q);
int isline(char s[], int len);
void printstr(char s[]);
void putwrd(void);
void putblnks(void);

char wrd[WIDTH];
char blnk[WIDTH];
int w = -1;
int b = -1;

void putwrd() {
    extern int w;
    extern char wrd[WIDTH];
    for(int j = 0; j <= w; j++)
        putchar(wrd[j]);
    w = -1;
}

void putblnks() {
    extern int b;
    extern char blnk[WIDTH];
    for(int j = 0; j <= b; j++)
        putchar(blnk[j]);
    b = -1;
}

/* This is probably better done using getline and an array.
 * Great example of why global variables sucks, and a great
 * indication that there's something inherintly tricky about imperative
 * programming and the order of variable change. */
int main()
{
    int c;
    int col = 0;
    int firstwrd = 1;
    while((c = getchar()) != EOF){
        if(c == '\n') {
            int tempw = w;
            if(col >= WIDTH && !firstwrd){
                putchar('\n');
                col = tempw + 1;
            }
            putwrd();
            putchar('\n');
            firstwrd = 1;
            col = 0;
            b = -1;
        }

        else if(c != ' ' && c != '\t') {
            ++col;
            wrd[++w] = c;
        }

        else {
            firstwrd = 0;
            if(c==' ') ++col;
            else col += col % TAB;
            blnk[++b] = c;

            if(col >= WIDTH) {
                putchar('\n');
                /* firstwrd = 1; */
                b = -1;
                col = w+2;
                putwrd();
                putchar(' ');
                /* printf("\tcol = %d\n", col); */
            }
            else {
                putwrd();
                putblnks();
            }
        }
    }
}


/* I learned that we need to also fold before a long word. This implementation does not do that and the algorithim used is not cannot be exteded to account for that because we'll need to keep track of that */
/* int main() */
/* { */
/*     int col = 0; */
/*     char blnk[WIDTH]; */
/*     int i = -1; */
/*     int c; */
/*     while((c = getchar()) != EOF){ */
/*         if(c == '\n') */
/*         { */
/*             putchar('\n'); */
/*             col = 0; */
/*             i = -1; */
/*         } */
/*         else if(c != ' ' && c != '\t') */
/*         { */
/*             ++col; */
/*             for(int j = 0; j <= i; j++) */
/*                 putchar(blnk[j]); */
/*             putchar(c); */
/*             i = -1; /1* reset blnks *1/ */
/*         } */
/*         else */
/*         { */
/*             blnk[++i] = c; */
/*             if(c==' ') */
/*                 ++col; */
/*             else */
/*                 col += col % TAB; */
/*             if(col >= WIDTH) { */
/*                 putchar('\n'); */
/*                 col = 0; */
/*                 i = -1; */
/*             } */

/*         } */
/*     } */
/* } */

/* void reset(){ */
/*     extern int col = 0; */
/*     extern int i = -1; */
/* } */

/* int main() */
/* { */
/*     char blnk[WIDTH]; */
/*     int i = -1; */
/*     int col = 0; */
/*     int c; */
/*     while((c = getchar()) != EOF){ */
/*         if((c==' ' || c=='\t') && col >= WIDTH) { */
/*             i = -1; */
/*             col = 0; */
/*             putchar('\n'); */
/*         } */
/*         else if(c != '\t') { */
/*             ++col; */
/*             if(c == ' ') */
/*                 blnk[++i] = c; */
/*             else { */
/*                 for(int j = 0; j <= i; j++) */
/*                     putchar(blnk[j]); */
/*                 putchar(c); */
/*                 i = -1; */
/*             } */
/*         } */
/*         else { */
/*             col += col % TAB; */
/*             blnk[++i] = c; */
/*         } */
/*     } */
/* } */

/* int main() */
/* { */
/*     char blnks[WIDTH] ; /1* place to store the blnk type (' ' or '\t' ), */
/*                            order matters! *1/ */
/*     int i = -1; */
/*     int c; */
/*     int col = 0; */
/*     while((c = getchar()) != EOF) { */
/*         if(++col > WIDTH){ */
/*             putchar('\n'); */
/*             putchar(c); */
/*             i = -1; */
/*             col = 0; */
/*         } */
/*         else if(c == ' ' || c == '\t') { */
/*             blnks[++i] = c; */
/*             if(col == WIDTH) { */
/*                 putchar('\n'); */
/*                 i = -1; */
/*                 col = 0; */
/*             } */
/*         } */
/*         else if(c == '\n') { */
/*             putchar('\n'); */
/*             i = -1; */
/*             col = 0; */
/*         } */
        /* else { */
        /*     for(int j = 0; j <= i; j++) */
        /*         putchar(blnks[j]); */
        /*     putchar(c); */
        /* } */
    /* } */
/* } */

/* int main() */
/* { */
/*     char[WIDTH] blnks; */
/*     int c; */
/*     int col = 0; */
/*     int blnk = 0; */
/*     while((c = getchar()) != EOF){ */
/*         ++col; */
/*         if(c == ' ' || c == '\t') { */
/*             if(c==' ') ++blnk; */
/*             if(c=='\t') blnk += col % TAB; */
/*             if(col == WIDTH) { */
/*                 putchar('\n'); */
/*                 col = 0; */
/*             } */
/*         } */
/*         else { */
/*             for(; blnk != 0; blnk--) */
/*                 putchar */
/*         } */
/*     } */
/* } */

int isline(char s[], int len){
    return s[len-1] == '\n';
}

int rem(int p, int q) {
    return p - (p/q)*q;
}

/* printstr: show the structure of the array */ 
void printstr(char s[])
{
    for(int i = 0, c = s[i]; c!='\0'; c = s[++i]) {
        if(c == '\n')
            printf("[\\n]");
        else if(c == '\t')
            printf("[\\t]");
        else
            printf("[%c]", c);
    }
    putchar('\n');
}




/* int main() */
/* { */
/*     int c; */
/*     int count = 0; */
/*     while((c = getchar()) != EOF) { */
/*         ++count; */
/*         if(c == '\n' || (c==' ' || c=='\t') && count > WIDTH) { */
/*             putchar('\n'); */
/*             count = 0; */
/*         } */
/*         else */
/*             putchar(c); */

/*     } */
/*     return 0; */
/* } */

/* let col be 0
 * read a c
 * increment col
 * if col == WIDTH
    * newline
    * putchar(c)
    * done
* if c == ' '
    */
