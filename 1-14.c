#include <stdio.h>
#define CHARS 26

int main()
{
    /* lowercase and uppercase and all other characters */
    int len = 2*CHARS + 1; /* + 5; */
    int freq[len];
    int c = 0;
    int i;

    for(i = 0; i < len; i++)
        freq[i] = 0;

    while((c = getchar()) != EOF){
        if(c >= 'A' && c <= 'Z')
            ++freq[c-'A'];
        else if( c >= 'a' && c <= 'z')
            ++freq[c-'A'-6]; /* to account for [ \ ] ^ _ ` */
        else
            /* other chars */
            ++freq[len-1];
    }


    /* A great example of why we need functions */

    int half = (len-1)/2;
    for(i = 0; i < half; i++) {
        printf("%c:", i+'A');
        for(c = 0; c < freq[i]; c++)
            putchar('|');
        putchar('\n');
    }

    for(i = half; i < len-1; i++){
        printf("%c:", (i-half)+'a');
        for(c = 0; c < freq[i]; c++)
            putchar('|');
        putchar('\n');
    }

    printf("others:");
    for(c = 0; c < freq[len-1]; c++){
        putchar('|');
    }
    putchar('\n');

}
