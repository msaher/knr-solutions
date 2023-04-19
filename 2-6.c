#include <stdio.h>

/* The reason why use unsgined is to avoid using signed bits when shifting*/
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned);


int main() {
    /* printf("%x\n", setbits(0xfff, 7, 4, 0xd)); */
    /* printf("%o\n", setbits(0777, 5, 3, 00)); */
    /* printf("%x\n", getbits(-1, 7, 4)); */
    return 0;
}

unsigned getbits(unsigned x, int p, int n) 
{ 
    return (x >> (p+1-n)) & ~(~0 << n); 
} 

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned set, prefix, post;
    /*var & firstn will yield the first n bits from var*/
    unsigned firstn = ~(~0 << n);
    prefix = x & firstn; /* same as getbits(x,n-1,n); */
    set = y & firstn; /* same as getbits(y,n-1,n); */
    post = x & (~0 << p+1); /* let all bits preceding the bit p+1 be zero */
    return prefix | set << n | post ;
}

/* Say we have any arbirtary bit string:
 *
 * 010101010101010111011010101
 *               p...866543210
 *
 * We want to capture p, p-1, p-2... p-(n-1). This is a total of n bits.
 * To do this, we first shift x such that the first bit becomes
 * p-(n-1)=p-n+1, the second bit becomes p-n+2... all the way to p. To
 * do this, we shift p-n+1 times. In otherwords x >> p-n+1.
 * 
 * Now that we have our n bits ready, we just need to turn them on,
 * and turn everything else off. That is we need to & them with a bit
 * string with only the first n bits being equal to one. We do this by
 * shifting ~0 to the left n times to get 111111110000000000, and
 * taking the ~ of that to get 0000000111111111 to get the first n
 * bits.
 * 
 * */
