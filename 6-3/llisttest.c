#include <stdio.h>
#include "llist.h"

int main(int argc, char* argv[])
{
    /* struct lnode* nodeptr = lnalloc(); */
    struct sllist *list = sllalloc();
    addtotail(list, 2);
    addtotail(list, 4);
    addtotail(list, 7);
    addtotail(list, 10);
    addtotail(list, 14);
    addtotail(list, 7);
    listprint(list);
    printf("\n");
}
