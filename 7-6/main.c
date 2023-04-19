#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000


int main(int argc, char* argv[]) {

    FILE *a, *b;
    if(--argc != 2) {
        fprintf(stderr, "%s: Invalid number of arguemetns\n", *argv);
        exit(1);
    }

    a = fopen(*++argv, "r");
    b = fopen(*++argv, "r");

    char* aline = malloc(MAXLINE);
    char* bline = malloc(MAXLINE);

    do {
        aline = fgets(aline, MAXLINE, a);
        bline = fgets(bline, MAXLINE, b);
        if(aline == NULL || bline == NULL)
            break;
    } while(strcmp(aline, bline) == 0);

    if(aline != NULL)
        printf("%s", aline);

    if(bline != NULL)
        printf("%s", bline);

    fclose(a);
    fclose(b);

    return 0;
}
