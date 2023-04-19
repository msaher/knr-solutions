#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define VARIABLE '1' /* signal that a number was found */
#define RECENT 0 /* Index of the varaible of the most recently printed value */

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void swap(void);
void duplicate(void);
void clear(void);
void set(double);
void show(char);
void ungets(char[]);

double var[26+1]; /* variable array */

/* reverse Polish calculator */
int main()
{
    int type, skip = 0;
    double op2;
    char s[MAXOP];
    {
        while ((type = getop(s)) != EOF) 
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case VARIABLE:
                    push(var[s[0]-'`']);
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '%':
                    op2 = pop();
                    if(op2 != 0.0)
                        push((int) pop() % (int) op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case 'S':
                    push(sin(pop()));
                    break;
                case 'E':
                    push(exp(pop()));
                    break;
                case '^':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case '?': /* A question mark is for asking */
                    printf("\t%.8g\n", var[RECENT] = peek());
                    skip = 1;
                    break;
                case '=':
                    set(pop());
                    skip = 1;
                    break;
                case ':':
                    duplicate();
                    skip = 1;
                    break;
                case ';': /* the , looks like its moving */
                    swap();
                    skip = 1;
                    break;
                case '!': /* Screaming at the stack */
                    clear();
                    skip = 1;
                    break;
                case '\n':
                    if(skip)
                        skip = 0;
                    else
                        printf("\t%.8g\n", var[RECENT] = pop());
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
        }
            return 0;
    }
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double peek(void)
{
    if(sp > 0)
        return val[sp-1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate(void)
{
    push(peek());
}

void swap(void)
{
    if(sp >= 2) { /* We have more than two elements */
        double tmp;
        tmp = val[sp-1], val[sp-1] = val[sp-2], val[sp-2] = tmp;
    }
    else 
        printf("error: %s%d elements in stack\n", sp == 1 ? "only " : " ", sp);
}

void clear(void)
{
    sp = 0;
}

#include <ctype.h>
/* We can use getc and ungetc from the stdlib */
/* int getch(void); */
/* void ungetch(int); */

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getc(stdin)) == ' ' || c == '\t');
    s[1] = '\0';

    i = 0;

    if(islower(c) || c == '`')
        return VARIABLE;

    if (!isdigit(c) && c != '.' && c != '+' && c != '-' && c != '=') {
        return c; /* not a number or variable */
    }

    /* We can nest this block in the above if, but that would make the
     * solution less redable */
    if(c == '+' || c == '-') {
        if(!isdigit(s[++i] = c = getc(stdin))) {
            ungetc(c, stdin);
            return s[0];
        }
    }

    else if(c == '=') {
        if(islower(s[++i] = c = getc(stdin))) {
            ungetc(c, stdin);
            return '=';
        }
        else {
            ungetc(c, stdin);
            return ':'; /* if no varaible follows =, it will be
                           interpreted as duplicate : to retain
                           compatability with the previous version of
                           this program */
        }
    }

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getc(stdin)));

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getc(stdin)));

    s[i] = '\0';
    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}

void set(double v) {
    char x = getc(stdin);
    var[x-'`'] = v;
}

void ungets(char s[])
{
    for(int i = strlen(s)-1; s[i] >= 0; i--)
        ungetc(s[i], stdin);
}
