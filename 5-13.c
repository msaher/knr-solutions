#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "atoi_valid.c"
#define N 10 /* default value of n */
#define MAXLINES 1000000
#define MAXLEN 100
#include "mygetline.c"
/* #include "mem.c" */
/* #include "queue.c" */
#include "itoa.c"
#include <limits.h>

/* For maximum efficiency Lineptr will never hold more than n
 * pointers. If we attempt to read n+1 lines, then my queue
 * implementation will remove the first line to make room for the
 * n+1th line. */

/* Queue: I decided to pass the array everytime */
extern void nq(char* ptr, char** q, int size);
extern char* dq(char **q, int size);

/* We need to release strings that we no longer need. However, this is
 * not possible with the current implementaion of alloc and afree
 * since calls folow a last in first out paradigm. We work around this
 * by shifting the memeory (and pointers!) to the left by the lenght
 * of the first string. i.e the lenght of the first pointer. */

/* Mem: Adated from the book */
extern char *alloc(int n);    /* return pointer to n characters */ 
extern void afree(char *p);  /* free storage pointed to by p */ 
extern void shiftlenf(char* lineptr[], int n); /* shift left by length
                                                  of first pointer */

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int n);

/* tail: read the last n lines from input */
int main(int argc, char *argv[]) {

    int n = N;
    char *name = *argv; /* Store the programs name */

    if(argc != 1) { /* Called with an arguement */
        if(argc > 2                    || /* wrong number of arguements */
          (*++argv)[0] != '-'          || /* first char in first arguement is not a - */
          !isdigit((*argv)[1])         || /* second char is not a number */
          atoi_valid(*argv+1, &n) == 0 || /* what's after '-' is not a valid integer */
          n == 0)                         /* If -0 was given. Note that atoi_valid changes n*/
        {
            fprintf(stderr, "Usage: %s -n, where n is a positive integer\n", name);
            return 1;
        }
        if(n < 0 || n > MAXLINES) { /* detect overflow. Ideally,
                                       MAXLINES would be around the
                                       maximum size of an automatic
                                       array */
            fprintf(stderr, "Error: n is too large\n");
            return 2;
        }
    }

    char *lineptr[n];
    int nlines;
    if((nlines = readlines(lineptr, n)) != -1)
        writelines(lineptr, nlines);
    else {
        fprintf(stderr, "Error: Input is too large\n");
        return 2;
    }

    return 0;
}

/* readlines: read lines from stdin */ 
int readlines(char *lineptr[], int n) 
{ 
    int len; 
    char *p, line[MAXLEN]; 
    int nlines = 0; 
    while ((len = mygetline(line, MAXLEN)) > 0) {
        if(nlines == n) {
            shiftlenf(lineptr, n); /* Shift to the left by the lenght
                                      of the first line everytime we
                                      need to overwrite a line */
        }
        if ((p = alloc(len)) == NULL) 
            return -1;
        else {
            line[len-1] = '\0';  /* delete newline */ 
            strcpy(p, line);
            nq(p, lineptr, n);
            if(nlines < n) 
                nlines++;
        }
    }
    return nlines;
}

/* adapted from 5-7.c */
/* writelines:  write output lines */ 
void writelines(char *lineptr[], int n /* BUG */ )
{ 
    int i = 0;
    for(i = 0; i < n; i++)
        printf("%s\n", dq(lineptr, n));
        /* printf("%s\n", lineptr[i]); */
} 
