#include <stdio.h>
#include "stack.c"
#include <ctype.h> 
#include <math.h>
#include <string.h>

int atof_valid(char *s, double *dp);
char get_op(char* s);
/* int test_atof(int argc, char* argv[]); */
/* int test_atof(int argc, char* argv[]) */
/* { */
/*     double d = 10; */
/*     while(--argc) { */
/*         if(atof_valid(*++argv, &d)) */
/*             printf("float: %lf\n", *&d); */
/*         else */
/*             printf("Invalid string: %s\n", *argv); */
/*     } */

/*     return 0; */
/* } */

int main(int argc, char *argv[])
{
    char *s;
    double op2;
    double num;
    if(argc == 1) {
        printf("expr usage: operands operators\n");
        return 1;
    }
    while(--argc) {
        s = *++argv;
        if(isdigit(*s) || ((*s == '-' || *s == '+') && s[1] != '\0')) {
            if(atof_valid(s, &num))
                push(num);
            else {
                printf("Error: Uknown oparand: %s\n", s);
                return 1;
            }
        }

        else {
            switch(get_op(s)) {
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    if(op2 != 0)
                        push(pop() / op2);
                    else {
                        printf("Error: Divison by zero\n");
                        return 1;
                    }
                    break;
                case '%':
                    op2 = pop();
                    if(op2 != 0)
                        push((int) pop() % (int) op2);
                    else {
                        printf("Error: Mod zero\n");
                        return 1;
                    }
                    break;
                case 's':
                    push(sin(pop()));
                    break;
                case 'c':
                    push(cos(pop()));
                    break;
                case 't':
                    push(tan(pop()));
                    break;
                case 'e':
                    push(exp(pop()));
                    break;
                case 'q':
                    push(sqrt(pop()));
                    break;
                default:
                    printf("Error: Uknown operator: %s\n", s);
                    return 1;
                    break;
            }

        }

    }
    printf("%g\n", pop());
    return 0;
}

/* Like atof, but report an error if input is invalid instead of returning 0.
 * 0 means failure
 * 1 means success
 * */
int atof_valid(char *s, double *dp)
{

    *dp = 0; /* start fresh */
    short sign = (*s == '-') ? -1 : 1; 
    if(*s == '-' || *s =='+')
        s++;

    while(*s != '\0') {
        if(!isdigit(*s))
            break;
        else
            *dp = 10.0 * *dp + (*s++ - '0'); /* do what atof would normally do */
    }

    if(*s == '\0') {
        *dp *= sign;
        return 1; /* Success */
    }
    else if(*s == '.') { /* We still have to deal with floating points */
        s++;
        double power = 1.0;
        while(*s != '\0') {
            if(!isdigit(*s))
                return 0;
            else {
                *dp = 10.0 * *dp + (*s++ - '0'); 
                power *= 10;
            }
        }
        *dp = sign * *dp / power; 
        return 1;
    }
    else { /* Not a number nor a point */
        return 0;
    }
}

/* Format: <CHAR>:<Name of function>. The first char represents the hash for
 * the function */

char *fun[] = {
    "s:sin", "c:cos", "t:tan", "q:sqrt", NULL /* You can add up to UCHAR_MAX-17 functions 
                                                (The other chars are reserved for numbers,
                                                arithmatic operations and exp) */
};

/* get_op: Extract an operator (or function) form a string */
char get_op(char* s) {
    if(strlen(s) == 1) {
        /* get one character operators out of the way to reduce computation time */
        if(*s == '+' || *s == '-' || *s == '/' || *s == '*' || *s == '%' || *s == '^' || *s == 'e')
            return *s;
        else
            return '\0';
    }

    char** ops = fun;

    while(*ops != NULL)
        if(strcmp(*ops+2, s) == 0) /* start at 2nd character to skip char and : */
            return *ops[0];
        else
            ops++;

    return '\0'; /* can't find anything meaningful */

}
