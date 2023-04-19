#ifndef TREE
#define TREE
#include "wrdfrq.h"
struct tnode {     /* the tree node: */ 
    struct wrdfrq* wf;
    struct tnode *left;   /* left child */ 
    struct tnode *right;  /* right child */ 
}; 

void treeprint(struct tnode *p);
struct tnode *addtree(struct tnode *p, char *w);
void copydec(struct tnode *p, struct wrdfrq arr[], int* iptr);
void treetoarray(struct tnode *p, struct wrdfrq* arr[], int* iptr); 
#endif
