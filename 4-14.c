#define swap(t,x,y) {t tmp; tmp = x, x = y, y = tmp;}
#include <stdio.h>

int main(void) {
    char x = 'x';
    char y = 'y';
    printf("x is %c, y is %c\n", x, y);
    printf("swapping...\n");
    swap(char, x, y);
    printf("x is %c, y is %c\n", x, y);
    return 0;
}
