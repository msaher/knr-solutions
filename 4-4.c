#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void swap(void);
void duplicate(void);
void clear(void);

/* reverse Polish calculator */
int main()
{
    int type, skip = 0; /* skip next popping on \n */
    double op2;
    char s[MAXOP];
    {
        while ((type = getop(s)) != EOF) {
            switch (type) {
                case NUMBER:
                    push(atof(s));
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
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
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
    double tmp;
    tmp = val[sp-1], val[sp-1] = val[sp-2], val[sp-2] = tmp;
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
    if (!isdigit(c) && c != '.' && c != '+' && c != '-') {
        return c; /* not a number */
    }

    /* We can nest this block in the above if, but that would make the
     * solution less redable */
    if(c == '+' || c == '-') {
        if(!isdigit(s[++i] = c = getc(stdin))) {
            ungetc(c, stdin);
            return s[0];
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
