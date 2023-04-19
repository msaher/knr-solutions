#include <stdio.h>
#include <string.h>
#include "mem.c"
#define MAXLINES 5000     /* max #lines to be sorted */ 

char *lineptr[MAXLINES];  /* pointers to text lines */ 

int readlines(char *lineptr[], int nlines, char* q); 
void writelines(char *lineptr[], int nlines); 

void qsort(char *lineptr[], int left, int right); 

/* sort input lines */ 
int main(void)
{ 
    int nlines;     /* number of input lines read */ 
    char q[ALLOCSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, q)) >= 0) { 
        qsort(lineptr, 0, nlines-1); 
        writelines(lineptr, nlines); 
        return 0; 
    } else { 
        printf("error: input too big to sort\n"); 
        return 1; 
    } 
} 

#define MAXLEN 1000  /* max length of any input line */ 
/* int getline(char *, int); */ 
/* char *alloc(int); */ 
#define getline(line, n) getline(line, n, stdin)
#include "mygetline.c"

/* readlines:  read input lines */ 
int readlines(char *lineptr[], int maxlines, char* q) 
{ 
    int len, nlines; 
    /* char *p; */
    char line[MAXLEN]; 
    int sum = 0;

    nlines = 0; 
    while ((len = mygetline(line, MAXLEN)) > 0) 
        if (nlines >= maxlines || len > ALLOCSIZE - sum) // || (p = alloc(len)) == NULL) 
            return -1;
        else {
            line[len-1] = '\0';  /* delete newline */ 
            /* printf("debug: line: %s\n", line); */
            strcpy(q, line);
            /* printf("debug: q...: %s\n", q); */
            lineptr[nlines++] = q;
            q += len;
            sum += len-1;
        }
    return nlines;
}

/* writelines:  write output lines */ 
void writelines(char *lineptr[], int nlines) 
{ 
    while (nlines-- > 0) 
        printf("%s\n", *lineptr++); 
} 


/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;
    /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap:  interchange v[i] and v[j] */ 
void swap(char *v[], int i, int j) 
{ 
    char *temp; 

    temp = v[i]; 
    v[i] = v[j]; 
    v[j] = temp; 
} 
