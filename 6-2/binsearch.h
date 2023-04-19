#include <stdlib.h> /* for size_t */

int binsearch(void* x, void* v[], size_t n, int (*compar)(void*, void*));
