#include "wrdfrq.h"
#include <stdlib.h>
struct wrdfrq* wfalloc(void)
{
    struct wrdfrq* ptr =  (struct wrdfrq*) malloc(sizeof(struct wrdfrq));
    /* ptr->freq = 0; */
    return ptr;
}
