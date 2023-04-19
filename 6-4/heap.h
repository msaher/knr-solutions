#ifndef HEAP
#define HEAP
#include "hnode.h"
void insert(struct hnode* heap[], int *len, struct wrdfrq wf);
void heapsort(struct hnode* heap[], int* len, struct wrdfrq array[]);
#endif
