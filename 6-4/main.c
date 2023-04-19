#include "tree.h"
#include "getword.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "globals.h"
#include "wrdfrq.h"
#include "qsort.h"
int uniqwrds = 0;

int freqcmp(struct wrdfrq* a, struct wrdfrq* b);
int revcmp(struct wrdfrq* a, struct wrdfrq* b);

int main(int argc, char* argv[])
{

    struct tnode *root = NULL;

    char w[MAXWORD];
    char c;
    while(getword(w, MAXWORD) != EOF)
        root = addtree(root, w);

    int i = 0;
    struct wrdfrq* pairs[uniqwrds];
    treetoarray(root, pairs, &i); 
    myqsort((void**) pairs, 0, uniqwrds-1, (int (*)(void*, void*)) revcmp);

    for(i = 0; i < uniqwrds; i++) {
        printf("%d %s\n", pairs[i]->freq, pairs[i]->word);
    }

    /* treeprint(root); */
    return 0;
}

int freqcmp(struct wrdfrq* a, struct wrdfrq* b)
{
    return a->freq - b->freq;
}

int revcmp(struct wrdfrq* a, struct wrdfrq* b)
{
    return freqcmp(b, a);
}

