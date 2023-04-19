#include <stdlib.h>
#include "llist.h"
#include <stdio.h>
#include "xref.h"

struct xref* xrefalloc(void)
{
    struct xref* cr = (struct xref*) malloc(sizeof(struct xref));
    cr->occur = NULL;
    return cr;
}

void addoccur(struct xref* cr, int linenumber)
{
    addtotail(cr->occur, linenumber);
}

void xrefprint(struct xref* cr)
{
    printf("Lines: ");
    listprint(cr->occur);
    printf("%s\n", cr->w);
}
