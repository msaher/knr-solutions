#include <stdio.h>
#include "globals.h"
#include "mygetline.h"
#include "getword.h"
#include "llist.h"
#include "tree.h"
#include "xref.h"
#include "binsearch.h"
#include <string.h>

int linenumber = 1;
char* noise[] = { "\"", "'", "I", "and", "but", "is", "not", "or", "the", "this"};

int isnoise(char* w);

int main(int argc, char* argv[])
{

    int c;
    char* w;

    struct tnode* root = NULL;
    while((c = getword(w, MAXWORD)) != EOF) {
        if(!isnoise(w))
            root = addtree(root, w);
    }
    treeprint(root);
}

int isnoise(char* w)
{
    return binsearch((void*) w, (void **) noise, sizeof(noise)/sizeof(noise[0]), (int (*)(void*, void*))strcmp) != -1;
}
