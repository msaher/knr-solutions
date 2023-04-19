#include <stdio.h>
#include "mygetline.c"
#include <string.h>

int any(char[], char[]);

int main() {
    int max = 100;
    char line[max]; 
    char s2[] = "xyz";
    mygetline(line, max);

    printf("%d\n", any(line, s2));

    return 0;
}

int any(char s1[], char s2[]) {
    int i, j, k;

    /* optimiation: cache already checked characters. This is not
     * required by the exercise, but I thought it would be nice to
     * have. Note that I have use strlen which we have not covered it. */
    int len = strlen(s1);
    char cache[len]; int cachesize = 0;
    int checked;

    for(k = i = 0; s1[i] != '\0'; i++, k = 0) {
        checked = 0;

        while(!checked && k < cachesize)
            if(s1[i] == cache[k++])
                checked = 1;

        if(!checked)
            for(j = 0; s2[j] != '\0'; j++)
                if(s1[i] == s2[j])
                    return i;

        cache[cachesize++] = s1[i];
    }

    return -1;
}
