#include <stdio.h>
#include <ctype.h>
#include "mygetline.c"
#define MAX 1000

int hatoi(char s[]);
int isvalid(char);

int main() {
    char line[MAX];
    mygetline(line, MAX);
    int i = hatoi(line);

    /* printf("%c\n", toupper(63)); */
    printf("%d\n", i);
    return 0;
}

int hatoi(char s[]) {
    int i;
    int n = 0;

    /* empty string case */
    if(s[0] == '\0')
        return n;

    /* if you have 0x at the beginning, skip them */
    if((s[1] == 'x' || s[1] == 'X') && s[0] == '0')
        i = 2;
    else
        i = 0;

    /* Not as pretty as it can be, but efficient */
    char offset;
    while(1) {
        if(isdigit(s[i]))
            offset = '0';
        else if((s[i] = toupper(s[i])) >= 'A' && s[i] <= 'F')
            offset = '0' + 7; /* 12356789;;<=>?@ABCD... */
        else
            return n;
        n = 16 * n + s[i++] - offset;
    }

}

/* shorter alternative to the above loop, works, but not very
 * readable, and slightly less efficient since it performs to checks:
 * One for the loop condition, and one for the offset */

/* while(((s[i] = toupper(s[i])) >= '0') && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F') */
/*     n = 16 * n + s[i] - '0' - (!isdigit(s[i++]) ? 7 : 0); */
/* return n; */
