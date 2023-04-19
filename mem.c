#include <stdio.h>
#define ALLOCSIZE 10000 /* size of available space */ 

static char allocbuf[ALLOCSIZE]; /* storage for alloc */ 
static char *allocp = allocbuf;  /* next free position */ 
static int lenf; /* lenght of the first pointer */

char *alloc(int n);
char *alloc(int n)    /* return pointer to n characters */ 
{ 
    // allocbuf + ALLOCSIZE is the whole space, subtracting allocp
    // gives the remaning space.
    if (allocbuf + ALLOCSIZE - allocp >= n) {  /* it fits */ 
        /* If first time allocating */
        if(allocp == allocbuf)
            lenf = n;
        allocp += n; 
        return allocp - n; /* old p */ 
    } else      /* not enough room */ 
        return NULL; 
} 

void afree(char *p);
void afree(char *p)  /* free storage pointed to by p */ 
{ 
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)  // check that that given pointer is valid
        allocp = p; 
} 

/* shift to the left by lenf */
void shiftlenf(char* lineptr[], int n);
void shiftlenf(char* lineptr[], int n)
{
    int size = allocp - allocbuf;
    int i;
    int lens = -1; /* lenght of second string */
    for(i = 0; i < size && lens == -1; i++) {
        allocbuf[i] = allocbuf[lenf+i];
        if(allocbuf[lenf + i] == '\0') /* length of second string */
            lens = i+1;
    }
    for(; i < size; i++)
        allocbuf[i] = allocbuf[lenf+i];

    /* update poniters to point the new strings */
    allocp -= lenf; /* next free position */
    for(i = 0; i < n; i++)
        lineptr[i] -= lenf;

    lenf = lens; /* update lenf */
}

/* void showbuf(int n); */
/* void showbuf(int n) */
/* { */
/*     int size = allocp - allocbuf; */
/*     /1* printf("Buffer content:\n"); *1/ */
/*     /1* printf("---------------\n"); *1/ */
/*     int i; */
/*     for(i = 0; i < size; i++  putchar(' ') *1/) { */
/*         if(allocbuf[i] == '\0') { */
/*             putchar('\n'); */
/*         } */
/*         else */
/*             putchar(allocbuf[i]); */
/*     } */
/*     /1* printf("i is %d\n", i); *1/ */
/*     /1* printf("lenf is %d\n", lenf); *1/ */
/*     /1* printf("---------------\n"); *1/ */
/* } */
