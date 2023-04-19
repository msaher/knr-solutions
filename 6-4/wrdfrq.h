#ifndef WRDFRQ
#define WRDFRQ
struct wrdfrq {
    char* word;
    int freq;
};

struct wrdfrq* wfalloc(void);
#endif
