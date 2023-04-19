#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned invert(unsigned x, int p, int n);

int main() {
    printf("%x\n", invert(0xafd, 7, 4));
    return 0;
}


unsigned getbits(unsigned x, int p, int n) 
{ 
    return (x >> (p+1-n)) & ~(~0 << n); 
} 

unsigned invert(unsigned x, int p, int n)
{
    unsigned prefix, inv, post;
    /*var & firstn will yield the first n bits from var*/
    unsigned firstn = ~(~0 << n);
    prefix = x & firstn;

    /* If you invert 010 you will get 1111111~(010). To work around this
     * we extract the firstnbits again*/
    inv = ~((x >> p-n+1) & firstn) & firstn;
    post = x & (~0 << p+1);
    return prefix | inv << n | post;
}
