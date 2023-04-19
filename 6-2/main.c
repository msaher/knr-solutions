#include "tree.h"
#include "getvar.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXWORD 100
#define DEFAULT_LEN 6

/* I'm assuming that varaibles that are less than 6 (n) are not
 * allowed, because it doesn't make sense to have a list of all words
 * that are indentical in the first 6 (or n) characters some of them
 * are less than 6 (or n) */

char* prefix;
int n;
int matchesprefix(char* w);

int main(int argc, char* argv[])
{
    if(--argc > 1) {
        fprintf(stderr, "Error: Invalid number of arguements\n");
        fprintf(stderr, "Should be one positive integer\n");
        return 1;
    }

    if(++argv == NULL)
        n = DEFAULT_LEN;
    else
        if(isdigit(**argv) && **argv != '0')
            n = atoi(*argv);
        else {
            fprintf(stderr, "Invalid arguement %s, should be a positive integer\n", *argv);
            return 1;
        }

    struct tnode *root = NULL;
    char* v;
    char c;
    while((c = getvar(v,MAXWORD)) != EOF) {
        if(strlen(v) >= n) {
            root = addtree(root, v);
            break;
        }
    }

    if(c == EOF)
        return 0;

    prefix = malloc(n);
    strncpy(prefix, root->word, n);

    while(getvar(v,MAXWORD) != EOF) {
        root = addtreeif(root, v, matchesprefix);
    }


    /* printf("The first word is %s\n", root->word); */
    /* printf("The condition is matching the first %d characters which are %s\n", n, prefix); */
    /* if(root != NULL) */
    treeprint(root);
    return 0;
}

int matchesprefix(char* w)
{
    /* printf("\t%s\n", (strncmp(node->word, prefix, n) == 0) ? "MATCHES" : "DOES NOT MATCH"); */
    /* printf("%d\n", (strncmp(w, prefix, n))); */
    return (strncmp(w, prefix, n) == 0);
}
