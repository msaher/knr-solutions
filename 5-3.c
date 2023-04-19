#include <stdio.h>

void strcat_ptr(char* s, char* t);
void strcat_arr(char* s, char* t);

int main(void)
{
    char s[] = "abcd";
    char t[] = "efgh";
    strcat_arr(s, t);
    printf("%s\n", s);
    char r[] = "abcd";
    strcat_ptr(r, t);
    printf("%s\n", r);
}

void strcat_ptr(char* s, char* t)
{
    while (*s != '\0') /* find end of s */ 
        s++; 
    while ((*s++ = *t++) != '\0') /* copy t */ 
        ; 
}

void strcat_arr(char* s, char* t)
{
    int i, j; 

    i = j = 0; 
    while (s[i] != '\0') /* find end of s */ 
        i++; 
    while ((s[i++] = t[j++]) != '\0') /* copy t */ 
        ; 
}
