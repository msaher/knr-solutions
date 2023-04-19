#include <stdio.h> 
#include <string.h> 
#include "mygetline.c"
#include <ctype.h>
#include "mem.c"
/* is alpha, digit or blank */
#define isadb(A) (isalpha((A)) || isdigit((A)) || isblank((A)))

#define MAXLINES 5000     /* max #lines to be sorted */ 
#define MAXLEN   5000
char *lineptr[MAXLINES];  /* pointers to text lines */ 

/* The idea is that we have a global compare function that we modify
 * depending on the flags passed to sort. Initally I tried to do this
 * wihtout global varaibles, but by functions that return comparators,
 * but doing that was trikcier than I thought. so I had to resort to
 * relying on global comp function
 */

double atof(char s[]);

int readlines(char *lineptr[], int nlines); 
void writelines(char *lineptr[], int nlines); 

void qsort(void *lineptr[], int left, int right, 
        int (*comp)(void *, void *), int scale); 

int numcmp(char *, char *); 
int foldcomp(char* a, char* b);
int dircomp(char* a, char* b);

int (*comp)(char* a, char* b);
int (*modcmp)(char* a, char* b); /* modified compare */

/* sort input lines */ 
int main(int argc, char *argv[]) 
{ 
    int nlines;        /* number of input lines read */ 

    /* I'm using char save space */
    char numeric = 0;   /* 1 if numeric sort */ 
    char reverse= 1; /* reverse sort */
    char fold = 0; /* treat a and A the same */
    char dir = 0;

    while(--argc) {
        if((*++argv)[0] == '-') { /* non dash arguements will be ignored */
            while(*++(*argv) != '\0')
                switch(**argv) {
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        reverse *= -1; /* -r -r will reverse twice.
                                          This is a feature, not a bug
                                          */
                        break;
                    case 'f':
                        fold = 1;
                        break;
                    case 'd':
                        dir = 1;
                        break;
                    default:
                        fprintf(stderr, "Usage: sort -n -r -f\n");
                        return 1;
                        break;
                }
        }
    }

    if(numeric)
        comp = numcmp;
    else if(dir)
        comp = dircomp;
    else
        comp = (int (*)(char*, char*))(strcmp);

    modcmp = (int (*)(char*, char*))(fold ? foldcomp: comp);

    /* printf("numeric = %d\n", numeric); */
    /* printf("reverse = %d\n", reverse); */
    /* return 0; */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) { 
        qsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))modcmp, reverse);
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

void strtolower(char* s, char* t, int len) {
    for(int i = 0; i < len; i++)
        t[i] = tolower(s[i]);
    t[len] = '\0';
}

/* Ignore case when comparing */
int foldcomp(char* a, char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    char alow[alen];
    char blow[blen];
    strtolower(a, alow, alen);
    strtolower(b, blow, blen);
    return (*comp)(alow, blow);
}

int dircomp(char* a, char* b)
{
    while(*a != '\0' && *b != '\0') {
        while(!isadb(*a) && *a != '\0')
            a++;
        while(!isadb(*b) && *b != '\0')
            b++;

        if(*a-*b != 0)
            return *a-*b;
        else {
            if(*a != '\0')
                a++;

            if(*b != '\0')
                b++;
        }
    }

    while(!isadb(*a) && *a != '\0') a++;
    while(!isadb(*b) && *b != '\0') b++;

    int diff = 0;
    if(*a == '\0')
        diff -= 1;
    if(*b == '\0')
        diff += 1;

    return diff;
}

/* testing dircomp */
/* int main(int argc, char *argv[]) */
/* { */
/*     ++argv; */
/*     char* s = argv[0]; */
/*     printf("s=%s\n", s); */
/*     char* t = argv[1]; */
/*     printf("t=%s\n", t); */
/*     int comp = dircomp(s,t); */
/*     printf("\tcomp=%d\n", comp); */
/*     return 0; */
/* } */
