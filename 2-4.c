#include <stdio.h>
#include "mygetline.c"
#define MAX 999

void squeeze(char s1[], char s2[]);

int main() {
    char s1[MAX];
    char s2[] = "xyz"; /* I hate 3d */
    mygetline(s1, MAX);
    squeeze(s1, s2);
    printf("%s", s1);
    return 0;
}

/* We could simply reuse oldsqueeze here, but that'd would be too
 * easy, and very efficient */

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int found = 0;

    for(i = j = k = 0; s1[i] != '\0'; i++, k = 0) {
        found = 0;

        while(!found && s2[k] != '\0')
            if(s1[i] == s2[k++])
                found = 1;

        if(!found)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';

        /* for(k = 0; s2[k] != '\0', k++) */
        /*     if(s1[i] == s2[k]) /1* found a match *1/ */

}

/* oldsqueeze:  delete all c from s */ 
/* void oldsqueeze(char s[], int c) */ 
/* { */ 
/*     int i, j; */ 

/*     for (i = j = 0; s[i] != '\0'; i++) */ 
/*         if (s[i] != c) */ 
/*             s[j++] = s[i]; */ 
/*     s[j] = '\0'; */ 
/* } */ 
