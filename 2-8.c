#include <stdio.h>
#include <math.h>

unsigned getbits(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned setbits(unsigned x, int p, int n, unsigned);

int main() {
    /* printf("%x\n", rightrot(0xabcde, 8)); */
    /* printf("%o\n", rightrot(032, 2)); */
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    unsigned firstn = x & ~(~0 << n);
    /* position of last 1-bit is floor of log2(x) + 1 */
    unsigned p = log(x)/log(2) + 1;
    return firstn << p-n | x >> n;

}
