#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

struct lnode* lnalloc(void)
{
    return (struct lnode *) malloc(sizeof(struct lnode)); 
}

struct sllist* sllalloc(void)
{
    struct sllist* list = (struct sllist*) malloc(sizeof(struct sllist));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addtohead(struct sllist *list, int data)
{
    if(list == NULL)
        list = sllalloc();
    struct lnode *newhead = lnalloc();
    newhead->data = data;
    newhead->next = list->head;
    if(list->head == NULL)
        list-> tail = newhead;
    list->head = newhead;
}

void addtotail(struct sllist *list, int data)
{
    if(list == NULL)
        list = sllalloc();
    struct lnode *newtail = lnalloc();
    newtail->data = data;
    newtail->next = NULL;
    if(list->tail == NULL) {
        list->head = newtail;
        list->tail = newtail;
    }
    else {
        list->tail->next = newtail;
        list->tail = newtail;
    }
}

void listprint(struct sllist *list)
{
    struct lnode *node = list->head;
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}


/* struct lnode* lnalloc(int n) */
/* { */

/* } */
