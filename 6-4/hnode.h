#ifndef HNODE
#define HNODE
#include "wrdfrq.h"
struct hnode {
    struct wrdfrq wf;
    struct hnode* left;
    struct hnode* right;
};
#endif
