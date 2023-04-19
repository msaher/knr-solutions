#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "wrdfrq.h"
#include "globals.h"
 
/* talloc:  make a tnode */ 
struct tnode *talloc(void) 
{ 
    /* struct tnode* node = (struct tnode *) malloc(sizeof(struct tnode)) */
    /* struct tnode* node = (struct tnode *) malloc(sizeof(struct tnode)) */
    return (struct tnode *) malloc(sizeof(struct tnode));
} 

/* addtree:  add a node with w, at or below p */ 
struct tnode *addtree(struct tnode *p, char *w) 
{ 
    int cond; 

    if (p == NULL) {     /* a new word has arrived */ 
        p = talloc();    /* make a new node */ 
        p->wf = wfalloc();
        p->wf->word = strdup(w);
        p->wf->freq = 1;
        uniqwrds++;
        p->left = p->right = NULL; 
    } else if ((cond = strcmp(w, p->wf->word)) == 0) 
        p->wf->freq++;      /* repeated word */ 
    else if (cond < 0)   /* less than into left subtree */ 
        p->left = addtree(p->left, w); 
    else             /* greater than into right subtree */ 
        p->right = addtree(p->right, w); 
    return p; 
} 

/* treeprint:  in-order print of tree p */ 
void treeprint(struct tnode *p) 
{ 
    if (p != NULL) { 
        treeprint(p->left); 
        printf("%4d %s\n", p->wf->freq, p->wf->word); 
        treeprint(p->right); 
    } 
} 

/* Ideally, we would have a traversal function that accepts a function
 * pointer visit that takes a tnode */
void treetoarray(struct tnode *p, struct wrdfrq* arr[], int* iptr) 
{ 
    if (p != NULL) { 
        treetoarray(p->left, arr, iptr); 
        arr[(*iptr)++] = p->wf;
        treetoarray(p->right, arr, iptr); 
    } 
}
