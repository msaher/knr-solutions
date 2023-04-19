#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
#include "mygetline.c"

/* int getline(char *line, int max); */

/* find (not to be confused with GNU find): print lines that match pattern from 1st arg. */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    while (--argc > 0 && (*++argv)[0] == '-') /* decrement argc and skip the 0th pointer
                                                 derefrence it, and check the first characther [0]  */
        while (c = *++argv[0]) /* get first pointer via [0] increment it, 
                                  derefrence it until it points to '\0' which is zero */
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (mygetline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}
