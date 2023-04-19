#include <stdio.h>

int strend(char* s, char* t);
int strend_ptr(char* s, char* t);
int my_strlen(char* s);

int main(void) {
    /* char *s = "1234567890"; */
    char *s = "abcdefg";
    char *t = "cdefg";
    if(strend(s, t))
        printf("Found\n");
    else
        printf("Not Found\n");
    /* printf("%d\n", my_strlen(s)); */
    return 0;
}

int strend(char* s, char* t)
{
    int i = 0;
    int j = 0;
    /* we can just use strlen too */
    while(s[i] != '\0') i++;
    while(t[j] != '\0') j++;
    if(i < j)
        return 0;

    while(j >= 0) {
        if(s[i--] != t[j--])
            return 0;
    }
    return 1;
}

int strend_ptr(char* s, char* t)
{
    int sl = my_strlen(s);
    int tl = my_strlen(t);
    if(tl > sl)
        return 0;
    s += tl - sl;
    while(*s == *t++)
        if(*s++ == '\0')
            return 1;
    return 0;
}


int my_strlen(char* s)
{
    char *p = s;
    while(*s) /* *s != '\0' is more readable */
        s++;
    return s - p;
}
