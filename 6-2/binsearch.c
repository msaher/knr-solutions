#include <stdlib.h>

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */ 
int binsearch(void* x, void* v[], size_t n, int (*compar)(void*, void*)) 
{ 
    int cond;
    int low, high, mid; 
    low = 0; 
    high = n - 1; 
    while (low <= high) { 
        mid = (low+high)/2; 
        if ((cond = (*compar)(x, v[mid])) < 0) 
            high = mid - 1; 
        else if (cond > 0) 
            low = mid + 1; 
        else    /* found match */ 
            return mid; 
    } 
    return -1;   /* no match */ 
}
