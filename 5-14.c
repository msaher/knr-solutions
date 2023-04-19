#include <stdio.h> 
#include <string.h> 
#include "mygetline.c"
#include <ctype.h>
#include "mem.c"

#define MAXLINES 5000     /* max #lines to be sorted */ 
#define MAXLEN   5000
char *lineptr[MAXLINES];  /* pointers to text lines */ 

double atof(char s[]);

int readlines(char *lineptr[], int nlines); 
void writelines(char *lineptr[], int nlines); 

void qsort(void *lineptr[], int left, int right, 
        int (*comp)(void *, void *), int scale); 
int numcmp(char *, char *); 

/* sort input lines */ 
int main(int argc, char *argv[]) 
{ 
    int nlines;        /* number of input lines read */ 
    char numeric = 0;   /* 1 if numeric sort */ 
    char reverse = 1;
    char c;
    while(--argc) {
        if((*++argv)[0] == '-') {
            while(*++(*argv) != '\0')
                switch(c = **argv) {
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        reverse *= -1; /* -r -r will reverse twice.
                                          This is a feature, not a bug
                                          */
                        break;
                    default:
                        fprintf(stderr, "Usage: sort -n -r\n");
                        return 1;
                        break;
                }
        }
    }

    /* printf("numeric = %d\n", numeric); */
    /* printf("reverse = %d\n", reverse); */
    /* return 0; */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) { 
        qsort((void**) lineptr, 0, nlines-1, 
                (int (*)(void*,void*))(numeric ? numcmp : strcmp), reverse);
        writelines(lineptr, nlines);
        return 0;
    } else {
        fprintf(stderr, "Input too big to sort\n");
        return 1;
    }
}


/* qsort:  sort v[left]...v[right] into increasing order */ 
void qsort(void *v[], int left, int right, 
        int (*comp)(void *, void *), int scale) 
{ 
    int i, last; 

    void swap(void *v[], int, int); 

    if (left >= right)    /* do  nothing if array contains */ 
        return;           /* fewer than two elements */ 
    swap(v, left, (left + right)/2); 
    last = left; 
    for (i = left+1; i <= right;  i++) 
        if ((*comp)(v[i], v[left])*scale < 0) 
            swap(v, ++last, i); 
    swap(v, left, last); 
    qsort(v, left, last-1, comp, scale); 
    qsort(v, last+1, right, comp, scale); 
} 
 
/* numcmp:  compare s1 and s2 numerically */ 
int numcmp(char *s1, char *s2) 
{ 
    double v1, v2; 

    v1 = atof(s1); 
    v2 = atof(s2); 
    if (v1 < v2) 
        return -1; 
    else if (v1 > v2) 
        return 1; 
    else 
        return 0; 
} 

void swap(void *v[],  int i, int j) 
{ 
    void *temp; 

    temp = v[i]; 
    v[i] = v[j]; 
    v[j] = temp; 
}

/* readlines:  read input lines */ 
int readlines(char *lineptr[], int nlines) 
{ 
    int len; 
    char *p;
    char line[MAXLEN]; 

    nlines = 0; 
    while ((len = mygetline(line, MAXLEN)) > 0) 
        if (nlines >= MAXLEN || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';  /* delete newline */ 
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines:  write output lines */ 
void writelines(char *lineptr[], int nlines) 
{ 
    while (nlines-- > 0) 
        printf("%s\n", *lineptr++); 
}
