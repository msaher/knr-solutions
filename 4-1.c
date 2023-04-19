#include <stdio.h>
#include "mygetline.c"

int strindex(char[], char[]);

int main() {
    char p[] = "ould";
    int found = 0;
    int max = 100; /* i hate constants */
    // char line[] = "How could\n I forget what has been done\nI should've never forgave you"
    char line[max];
    int pos;
    while(mygetline(line, max) > 0)
        if((pos = strindex(line, p)) >= 0) {
            printf("%d\n", pos);
            found++;
        }
    return found;
}

/* strindex:  return index of t in s, -1 if none */ 
int strindex(char s[], char t[]) 
{ 
    int i, j, k; 
    int pi = -1; /* potential i to return */

    for (i = 0; s[i] != '\0'; i++) { 
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            pi = i;
    }
    return pi;
}
