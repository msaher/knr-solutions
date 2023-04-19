#include <stdio.h> 

int lower(int);

int main() {
    int c = 'B';
    printf("%c\n", lower(c));
    return 0;
}

/* lower:  convert c to lower case; ASCII only */ 
int lower(int c) 
{ 
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
} 
