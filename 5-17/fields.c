#include <stdio.h>

char sep = ','; /* default seperator */

int strlen_field(char* s);

/* int main(int argc, char *argv[]) */
/* { */
/*     int len = strlen_field(*(++argv)); */
/*     /1* printf("String is %s\n", *++argv); *1/ */
/*     printf("Length of the first field is %d\n", len); */
/*     printf("Length of the next field is %d\n", strlen_field(*argv+len+1, ',')); */
/*     return 0; */
/* } */

/* strlen: Lenght of the first field, to get the nextfield, you would
 * do strlen(s+lenfirstfield+1)*/
int strlen_field(char* s)
{
    int lenf = 0;
    while(*s != sep && *s != '\0') {
        s++;
        lenf++;
    }
    return lenf;
}
