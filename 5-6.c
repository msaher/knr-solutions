#include <stdio.h>
#include <ctype.h>
#define MAX 100
#include "mygetline.c" 
#include "myatoi.c"
#include "reverse.c"
#include "itoa.c"
#include <limits.h>
#include "strindex.c"
#define NUMBER '1'
#define getch() getc(stdin)
#define ungetch(c) ungetc(c, stdin)

int getlineptr(char s[], int lim);
void printline(char *line);
int atoiptr(char* s);
void reverseptr(char* s);
int getop(char* );
int getopptr(char* );

void test_mygetline(void);
void test_atoi(void);
void test_itoa(void);
void test_reverse(void);
void test_strindex(void);
void test_getop(void);

int main(void)
{
    /* test_mygetline(); */
    /* test_atoi(); */
    /* test_itoa(); */
    /* test_reverse(); */
    /* test_strindex(); */
    test_getop();
    return 0;
}

int getlineptr(char* s, int lim)
{
    int i = 0;
    int c;
    while((c = getchar()) !=EOF && c != '\n' && i < lim-1) {
        *s++ = c;
        i++;
    }

    if(c == '\n')
        *s++ = c;
    *s = '\0';
    return i;
}

void test_mygetline(void)
{
    int lim = MAX;
    char line[lim];
    mygetline(line, lim);
    printline(line);
    getlineptr(line, lim);
    printline(line);

}

void printline(char *line)
{
    while(*line != '\0') {
        switch(*line) {
            case '\n':
                printf("[\\n]");
                break;
            case '\t':
                printf("[\\t]");
                break;
            default:
                printf("[%c]", *line);
                break;
        }
        line++;
    }
        putchar('\n');
}

int atoiptr(char* s)
{
    /* ignore white space */
    while(isspace(*s)) s++;
    int sign = (*s == '-') ? -1 : 1; 
    if (*s == '+' || *s == '-')  /* skip sign */ 
        s++; 

    int n;
    for (n = 0; isdigit(*s); s++) 
        n = 10 * n + (*s - '0'); 
    return sign * n; 
}

void test_atoi(void)
{
    char line[MAX];
    while(getlineptr(line, MAX) > 0) {
        printf("atoi    %d\n", myatoi(line));
        printf("atoiptr %d\n", atoiptr(line));
    }
    
}

void itoaptr(int n, char* s)
{
    int i, sign;
    unsigned int un;

    if ((sign = n) < 0)  /* record sign */ 
        un = -n;          /* make n positive */ 
    else
        un = n;
    do {      /* generate digits in reverse order */ 
        *s++ = un % 10 + '0';  /* get next digit */ 
    } while ((un /= 10) > 0);    /* delete it */ 
    if (sign < 0) 
        *s++ = '-'; 
    *s = '\0';
    reverse(s);
}

void test_itoa(void)
{
    int n = INT_MIN;
    char s[MAX];
    itoa(n, s);
    printf("itoa:    %s\n", s);
    char t[MAX];
    itoa(n, t);
    printf("itoaptr: %s\n", t);

}

void reverseptr(char* s)
{
    char *p = s + strlen(s)-1;
    for(char tmp; s < p; s++, p--) {
        tmp = *s;
        *s = *p;
        *p = tmp;
    }
}

void test_reverse(void)
{
    char s[] = "123456789";
    char t[strlen(s)+1];
    strcpy(t,s);
    reverseptr(s);
    printf("%s\n", s);
    reverse(t);
    printf("%s\n", t);
}


int strindexptr(char* s, char* t)
{
    char* bt = t; /* beginning of t */
    char* bs = s; /* beginning of s */
    char* cs; /* copy of s */
    for(; *s != '\0'; s++) {
        for(t = bt, cs = s; *t != '\0' && *t == *cs; cs++, t++);
        if(t > bt && *t == '\0')
            return s - bs;
    }
    return -1;
}


void test_strindex(void)
{
    char s[] = "hi this is really long text that contains some things";
    char t[] = "really";
    printf("strindex    %d\n", strindex(s, t));
    printf("strindexptr %d\n", strindexptr(s, t));
}

/* getop:  get next character or numeric operand */ 
int getop(char s[]) 
{ 
    int i, c; 

    while ((s[0] = c = getch()) == ' ' || c == '\t') 
        ; 
    s[1] = '\0'; 
    if (!isdigit(c) && c != '.') 
        return c;      /* not a number */ 
    i = 0; 
    if (isdigit(c))    /* collect integer part */ 
        while (isdigit(s[++i] = c = getch())) 
            ; 
    if (c == '.')      /* collect fraction part */ 

        while (isdigit(s[++i] = c = getch())) 
            ; 
    s[i] = '\0'; 
    if (c != EOF) 
        ungetch(c); 
    return NUMBER; 
} 

int getopptr(char s[]) 
{ 
    int i, c; 

    while ((*s = c = getch()) == ' ' || c == '\t') 
        ; 
    *(s+1) = '\0'; 

    if (!isdigit(c) && c != '.') 
        return c;      /* not a number */ 
    i = 0; 
    if (isdigit(c))    /* collect integer part */ 
        while (isdigit(*++s = c = getch()))
            ; 
    if (c == '.')      /* collect fraction part */ 
        while (isdigit(*++s = c = getch())) 
            ; 
    *s = '\0'; 

    if (c != EOF) 
        ungetch(c); 
    return NUMBER; 
} 

void test_getop(void)
{
    char s[100];
    getopptr(s);
    printf("%s\n", s);

}
