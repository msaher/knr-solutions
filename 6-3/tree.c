#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "globals.h"
#include "xref.h"

extern int linenumber;

struct tnode {     /* the tree node: */ 
    struct xref *cr;
    struct tnode *left;   /* left child */ 
    struct tnode *right;  /* right child */ 
}; 
 
/* talloc:  make a tnode */ 
struct tnode *talloc(void) 
{ 
    return (struct tnode *) malloc(sizeof(struct tnode)); 
} 

/* addtree:  add a node with w, at or below p */ 
struct tnode *addtree(struct tnode *p, char *w) 
{ 
    int cond; 

    if (p == NULL) {     /* a new word has arrived */ 
        p = talloc();    /* make a new node */
        p->left = p->right = NULL; 
        p->cr = xrefalloc();
        p->cr->w = strdup(w);
        addoccur(p->cr, linenumber);
    } 
    else if ((cond = strcmp(w, p->cr->w)) == 0) 
        addoccur(p->cr, linenumber);
    else if (cond < 0)   /* less than into left subtree */ 
        p->left = addtree(p->left, w); 
    else             /* greater than into right subtree */ 
        p->right = addtree(p->right, w); 
    return p; 
} 

struct tnode* addtreeif(struct tnode *p, char *w, int (*cond)(char* ))
{
    if(!(*cond)(w))
        return p;
    else
        return addtree(p, w);
}

/* struct tnode *findword(char* w, struct tnode *n) */
/* { */
/*     if(n == NULL) */
/*         return NULL; */

/*     int cond = strcmp(w, n->word); */
/*     if(cond < 0) */
/*         return findword(w, n->left); */
/*     if(cond > 0) */
/*         return findword(w, n->right); */
/*     else */
/*         return n; */
/* } */

/* treeprint:  in-order print of tree p */ 
void treeprint(struct tnode *p) 
{ 
    if (p != NULL) { 
        treeprint(p->left); 
        xrefprint(p->cr);
        /* printf("%4d %s\n", p->count, p->word); */ 
        treeprint(p->right); 
    } 
} 
