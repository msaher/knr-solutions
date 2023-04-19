#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define UPPER "upper"
#define LOWER "lower"

/* I resorted to using strstr instead of strcmp. because I dont want
 * to deal with handling the ./ prefix */

int main(int argc, char* argv[])
{
    int c;

    int (*transformer)(int);
    if(strstr(*argv, UPPER) != NULL)
        transformer = toupper;
    else if(strstr(*argv, LOWER) != NULL)
        transformer = tolower;
    else {
        fprintf(stderr, "I was called with %s\n", *argv);
        fprintf(stderr, "What does that even mean?\n");
        fprintf(stderr, "i DoN'T KnOw wHaT To dO\n");
        return 1;
    }

    while((c = getchar()) != EOF) {
        putchar(transformer(c));
    }
    return 0;
}
