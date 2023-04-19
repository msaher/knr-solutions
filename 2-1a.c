#include <stdio.h>
#include <limits.h>

int main() {

    printf("char\n");
    printf("signed char max %d\n", SCHAR_MAX);
    printf("signed char min %d\n", SCHAR_MIN);
    printf("unsigned char max %d\n", UCHAR_MAX);

    printf("\nshort\n");
    printf("signed char min %i\n", SHRT_MIN);
    printf("signed char max %i\n", SHRT_MAX);
    printf("unsigned short max %i\n", USHRT_MAX);

    printf("\nint\n");
    printf("signed short min %i\n", INT_MIN);
    printf("signed short max %i\n", INT_MAX);

    printf("\nint\n");
    printf("usigned int max %ld\n", UINT_MAX);

    printf("\nlong\n");
    printf("signed long min %ld\n", LONG_MIN);
    printf("signed long max %ld\n", LONG_MAX);
    printf("unsigned long max %lu\n", ULONG_MAX);

    printf("\nlong long\n");
    printf("signed long min %lld\n", LLONG_MAX);
    printf("signed long max %lld\n", LLONG_MIN);
    printf("unsigned long max %llu\n", ULLONG_MAX);



    return 0;

}
