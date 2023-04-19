#include <stdio.h>
#include <limits.h>
#include <math.h>

void maxmin(void);

/* ignore this function, its their to indicate the "standard appraoch" */
/* long limit(int); */

int main() {
    /* double x = 1/((unsigned double) -1); */
    /* printf("%f", x); */

    maxmin();

    /* Percision */

    printf("\nPercision: \n");

    double d = 1;
    double pd = 0;
    do {
        pd = d;
    } while( (d /= 2) != 0);

    printf("smallest double = %E\n", pd);

    float f = 1;
    float pf = 0;

    do {
        pf = f;
    } while( (f /= 2) != 0);

    printf("smallest float = %E\n", pf);

    return 0;
}

void maxmin() {
    /* better handled by a function, but whatever */

    unsigned char uc = -1;
    char sc = uc/2;
    printf("signed char max %d\n", sc);
    printf("signed char min %d\n", -sc-1);
    printf("unsigned char max %d\n", uc);

    printf("\n");
    unsigned short us = -1;
    short ss = us/2;
    printf("signed short max %d\n", ss);
    printf("signed short min %d\n", -ss-1);
    printf("unsigned short max %ld\n", us);

    printf("\n");
    unsigned long ul = -1;
    long sl = ul/2;
    printf("signed long max %ld\n", sl);
    printf("signed long min %ld\n", -sl-1);
    printf("unsigned long max %lu\n", ul);

    printf("\n");
    unsigned long long ull = -1;
    long long sll = ull/2;
    printf("signed long long max %ld\n", sll);
    printf("signed long long min %ld\n", -sll-1);
    printf("unsigned long long max %lu\n", ull);

}


/* my inital inefficient appraoch. isntead, set unsighed types to -1 and cast them since 1111... is -1 */
/* long limit(int i) { /1* here i is the number of bits for(i = 0; x != 0; ++i, x <<= 1); *1/ */
/*     long res = 1; */
/*     while(i-- != 0) */
/*         res <<= 1; */

/*     return res-1; */
/* } */

    /* long x = 1; */
    /* int i; */

    /* printf("signed char have %ld bits\n", i); */

    /* for(i = 0; x != 0; ++i, x <<= 1); */

    /* unsigned long umax = limit(i); */
    /* /1* unsigned long umax = -1; *1/ */
    /* long smax =  (unsigned) umax >> 1; */

    /* /1* printf("signed min %lu\n", smax); *1/ */
    /* /1* printf("signed max %lu\n", smax); *1/ */
    /* printf("unsigned char have max value of %lu\n", umax); */
    /* /1* printf("unsigned char have max value of %lu\n", limit(i)); *1/ */
