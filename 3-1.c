#include <stdio.h>

int binsearch0(int x, int v[], int n);
int binsearch1(int x, int v[], int n);

int main() {
    int v[] = {0,1,2,3,4,5,6,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int n =  sizeof(v)/sizeof(int);
    int x = 17;
    printf("binsearch0(x) = %d\n", binsearch0(x,v,n));
    printf("binsearch1(x) = %d\n", binsearch1(x,v,n));
    return 0;
}

int binsearch1(int x, int v[], int n)
{
    int low, high, mid; 
    low = 0; 
    high = n - 1; 
    while (low < high) {  /* stop when low == high */
        mid = (low+high)/2; 
        if (x <= v[mid]) 
            high = mid; /* we dont subtract 1, because mid might actually be the key */
        else
            low = mid + 1; 
    } 
    /* when low == high, look for the key */
    return (x == v[low]) ? low : -1;
}

/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */ 
int binsearch0(int x, int v[], int n) 
{ 
    int low, high, mid; 
    low = 0; 
    high = n - 1; 
    while (low <= high) { 
        mid = (low+high)/2; 
        if (x < v[mid]) 
            high = mid - 1; 
        else if (x  > v[mid]) 
            low = mid + 1; 
        else    /* found match */ 
            return mid; 
    } 
    return -1;   /* no match */ 
} 
