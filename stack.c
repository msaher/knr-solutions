#define MAXSTACK 1000

double storage[MAXSTACK];
double *stack = storage;
int size;

void push(double);
double pop();

void push(double d)
{
    *stack++ = d;
}

double pop()
{
    return *--stack;
}
