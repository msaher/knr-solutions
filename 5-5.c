#include <stdio.h>
#include <string.h>

char* my_strncpy(char *dest, char *src, size_t n);
int my_strncmp(char *dest, char *src, size_t n);
char* my_strncat(char *dest, char *src, size_t n);

void test_my_strncat(void);

int main(void) {
    test_my_strncat();
}

char *my_strncpy(char *dest, char *src, size_t n)
{
    while((*dest++ = *src++) && --n != 0);
    if(*src != '\0')
        *dest = '\0';
    return dest;
}

int my_strncmp(char *dest, char *src, size_t n)
{
    for (; n != 0 && *dest == *src ; dest++, src++, n--) {
        if (*dest == '\0')
            return 0; 
    }
    if(n == 0)
        return 0;
    else
        return *dest - *src; 
}

char *my_strncat(char *s, char *t, size_t n)
{
    /* All my homies hate readable code */
    for(s += strlen(s); *t != '\0' && n != 0; *s++ = *t++, n--);
    *s = '\0';
    return s;
}

void test_my_strncat(void)
{
    char s[] = "Please con";
    char c[] = "Please con"; /* control group */
    char t[] = "cat me";
    int n = 2;

    strncat(s, t, n);
    printf("s: %s\n", s);

    strncat(c, t, n);
    printf("c: %s\n", s);

    putchar('\n');
}
