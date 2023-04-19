#include <stdio.h> 
#include <string.h> 
#include "../mygetline.c"
#include <ctype.h>
#include "../mem.c"
#include <stdlib.h>
/* is alpha, digit or blank */
#define isadb(A) (isalpha((A)) || isdigit((A)) || isblank((A)))

#define MAXLINES 5000     /* max #lines to be sorted */ 
#define MAXLEN   5000
char *lineptr[MAXLINES];  /* pointers to text lines */ 

int readlines(char *lineptr[], int nlines); 
void writelines(char *lineptr[], int nlines); 
void myqsort(void *lineptr[], int left, int right, 
        int (*comp)(void *, void *)); 

int numcmp(char *, char *); 
int foldcomp(char* a, char* b);
int dircomp(char* a, char* b);
int revcomp(char* a, char* b);

extern int sep;
int fields[MAXLEN];
char* fieldsopts[MAXLEN];

char parse_sortargs(char* s, char *numeric, char *reverse, char *fold, char *dir);

int (*comp)(char* a, char* b);
int (*casecomp)(char* a, char* b); /* modified compare */
int (*finalcomp)(char* a, char* b); /* possibly reversed modified compare */


void setcomp(char, char, char, char);

/* sort input lines */ 
int main(int argc, char *argv[]) 
{ 
    int nlines;        /* number of input lines read */ 

    /* I'm using char save space */
    char numeric = 0;   /* 1 if numeric sort */ 
    char reverse = 0; /* reverse sort */
    char fold = 0; /* treat a and A the same */
    char dir = 0;

    int fld = 0; /* number of special fields */
    char c;
    char* s;

    while(--argc > 0) {
        if((*++argv)[0] == '-') { /* non dashed arguements will be ignored */

            if((*argv)[1] == 't')
                if((*argv)[2] != '\0')
                    sep = (*argv)[2];
                else {
                    fprintf(stderr, "Missing seperator after -t\n");
                    return 1;
                }

            else if(isdigit((*argv)[1]) && (*argv)[1] != '0') {
                fields[++fld] = atoi((*argv)+1);
                for(s = (*argv)+1; isdigit(*s); s++);
                if(*s == '\0') {
                    fprintf(stderr, "No sorting speicfied on field %d\n", fields[fld]);
                    return 1;
                }
                else
                    fieldsopts[fld] = s;
            }

            else if((c = parse_sortargs((*argv)+1, &numeric, &reverse, &fold, &dir)) != 0) {
                fprintf(stderr, "Invalid option: %c\n", c);
                return 1;
            }
        }
    }

    setcomp(numeric, reverse, fold, dir);

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) { 
        myqsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))finalcomp);
        writelines(lineptr, nlines);
        return 0;
    } else {
        fprintf(stderr, "Input too big to sort\n");
        return 1;
    }
}


/* myqsort:  sort v[left]...v[right] into increasing order */ 
void myqsort(void *v[], int left, int right, 
        int (*comp)(void *, void *)) 
{ 
    int i, last; 

    void swap(void *v[], int, int); 

    if (left >= right)    /* do  nothing if array contains */ 
        return;           /* fewer than two elements */ 
    swap(v, left, (left + right)/2); 
    last = left; 
    for (i = left+1; i <= right;  i++) 
        if ((*comp)(v[i], v[left]) < 0) 
            swap(v, ++last, i); 
    swap(v, left, last); 
    myqsort(v, left, last-1, comp); 
    myqsort(v, last+1, right, comp); 
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

/* parse_args: Set the value of numeric, reverse, fold and dir given a string
 * s. Note that `-t` is not included as its not a sorting arg. Also s does not
 * include the leading `-`. return 1 if invalid options are given */
char parse_sortargs(char* s, char *numeric, char *reverse, char *fold, char *dir)
{
    int i = 0;
    while(s[i] != '\0') {
        switch(s[i]) {
            case 'n':
                *numeric = 1;
                break;
            case 'r':
                *reverse = 1;
                break;
            case 'd':
                *dir = 1;
                break;
            case 'f':
                *fold = 1;
                break;
            default:
                return s[i]; /* failed character */
                break;
        }
        i++;
    }
    return 0; /* success */
}

void setcomp(char numeric, char reverse, char fold, char dir)
{
    if(numeric)
        comp = numcmp;
    else if(dir)
        comp = dircomp;
    else
        comp = (int (*)(char*, char*)) strcmp;

    casecomp = (int (*)(char*, char*))(fold ? foldcomp: comp);
    finalcomp = (int (*)(char*, char*))(reverse ? revcomp: casecomp);
}

int revcomp(char* a, char* b)
{
    return (*casecomp)(b, a);
}

int fieldcomp(char* a, char* b)
{
    int n, r, f, d;
    int fc = 0; /* field count */
    int i = 0; int j = 0; int k = 0;
    int pi = 0; int pj = 0;
    int diff = 0;
    char* opts;
    int(*)(char*, char*) defcomp = finalcomp;
    while(a[i] != '\0' && b[j] != '\0') {
        /* get fields */
        while(a[i] != sep && a[i] != '\0') i++;
        while(b[j] != sep && a[i] != '\0') j++;
        a[i] = '\0';
        b[j] = '\0';
        fc++;
        if(fc == fields[k]) {
            opts = fieldsopts[k++];
            parse_sortargs(opts, n, r, f, d);
            setcomp(n, r, f, d);
        }

        diff = (*finalcomp)(a+pi, b+pj);
        if(diff == 0) {
            comp = defcomp;
            return diff;
        }
        pi = i+1;
        pj = j+1;
        a[i] = sep;
        b[j] = sep;
    }

/*     } */

/* } */

/* /1* compare the first n characters of two strings given a comparator *1/ */
/* int ncmp(char* a, char*b, int n, int (*cmp)(char*, char*)) */
/* { */
/*     char* ap; */
/*     char* bp; */
/*     strncpy(ap, a, n); */
/*     strncpy(bp, b, n); */
/*     return (*cmp)(ap, bp); */
/* } */

/*
 * Write an abstraction barrier, setfield, which will mutlate
 * *s so it points to field i, then you can compare setfield
 * of a and setfield of b and return the result, otherwise get
 * the next field and repeat
 */
