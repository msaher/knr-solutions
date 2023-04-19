#include <stdio.h>
#define TAB 8

void boxputchar(int c);
int rem(int p, int q);

int main()
{

    int c;
    int col = 0;
    int nblnk = 0; /* number of constitutive blanks */
    while((c = getchar()) != EOF){

        if(c == '\t') {
            nblnk = 0;
            col = 0;
            boxputchar('\t');
        }

        else {
            ++col;
            if(c == ' ') {
                ++nblnk;
                if(col == TAB) {
                    boxputchar('\t');
                    nblnk = 0;
                    col = 0;
                }
            }

            /* TODO: same as above block */
            else if(c == '\n') {
                putchar('\n');
                nblnk = 0;
                col = 0;
            }

            else {
                for(; nblnk != 0; --nblnk)
                    boxputchar(' ');
                boxputchar(c);
            }
        }
    }
}

int rem(int p, int q)
{
    /* p = kq + r */
    return p - (p/q)*q;
}

void boxputchar(int c)
{
    switch(c) {
        case ' ':
            printf("[ ]");
            break;
        case '\t':
            printf("[\\t]");
            break;
        case '\n':
            putchar('\n');
            break;
        default:
            printf("[%c]", c);
    }
}
