
#include <stdio.h>
#include <math.h>

int bitcount(unsigned x);
int faster_bitcount(unsigned x);

int main() {
    int x = 8130;
    printf("bitcount = %d\nfaster_bitcount = %d\n", bitcount(x), faster_bitcount(x));
    return 0;
}

/* Explaination: Subtracting 1 from a binary number in two's
 * complement will turn all 0-bits into 1s until we reach the first
 * 1-bit at which we will convert it to 0. So if you have
 * xxxxxxx10000... then subtratcting one from that will result in
 * xxxxxx011111... If we `&' x and x-1 together we will delete the right
 * most 1 from x. We can use this fact to count the number of 1 bits
 * by removing the right most 1 until we reach x == 0. */

/* faster_bitcount:  count 1 bits in x */ 
int faster_bitcount(unsigned x)
{
    int b;
    while(x != 0) {
        x &= x-1;
        b++;
    }
    return b;
}

/* bitcount:  count 1 bits in x */ 
int bitcount(unsigned x) 
{ 
    int b; 
    for (b = 0; x != 0; x >>= 1) 
        if (x & 01) 
            b++; 
    return b; 
} 
