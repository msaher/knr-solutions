#ifndef XREF
#define XREF
#include <stdlib.h>
#include "llist.h"

struct xref {
    char* w;
    struct sllist* occur;
};

struct xref* xrefalloc(void);
void addoccur(struct xref* cr, int linenumber);
void xrefprint(struct xref* cr);
#endif
