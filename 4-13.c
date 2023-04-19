#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse_helper(char s[], int, int);
void reverse(char s[]);

int main(void)
{
    char s[] = "abcd";
    printf("s = %s\n", s);
    reverse(s);
    printf("s = %s\n", s);
    return 0;
}


/* itoa:  convert n to characters in s */ 
void itoa(int n, char s[]) 
{
    static int i = 0;
    if(i == 0 && n < 0) {
        n = -n;
        s[i++] = '-';
    }

    else if(n / 10)
        itoa(n / 10, s);

    s[i++] = n % 10 + '0';  /* get next digit */ 
    s[i] = '\0';
}

/* reverse:  reverse string s in place */ 
void reverse(char s[]) {
    reverse_helper(s, 0, strlen(s)-1);
}

/* Lesson learned. Static varialbes are to be avoided! Having to reset
 * your static varaibles after making sure that all you recursive
 * calls have been made by creating ANOTHER static variable is yuck.
 * Furthermore, being forced to having constants as initial values in
 * static variables is limiting. */

void reverse_helper(char s[], int i, int j) 
{ 
    if(i < j) {
        char tmp;
        tmp = s[i], s[i] = s[j],  s[j] = tmp;
        reverse_helper(s, i+1, j-1);
    }
}
