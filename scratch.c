#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int f(int, int);
int rf(int, int, int (*)(int, int));
int (*rfmaker(int (*)(int, int)))(int, int);

int main(int argc, char *argv[])
{
    if(--argc < 2) {
        fprintf(stderr, "Wrong number of arguements\n");
        return 1;
    }
    int a, b;
    a = atoi(*++argv);
    b = atoi(*++argv);
    printf("f(a,b) is %d\n", f(a,b));
    printf("rf(a,b, f) is %d\n", rf(a,b, f));
    return 0;
}

int f(int a, int b)
{
    return a - b;
}

int (*rfmaker(int (*fun)(int, int)))(int, int)
{
    return (*fun)(b, a);
}
