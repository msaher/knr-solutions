#define BUFSIZE 100 
 
int getch(void); 
void ungetch(int); 
int buf = EOF;  /* buffer for ungetch */ 

int main() {
    return 0;
}

int getch(void)  /* get a (possibly pushed-back) character */ 
{ 
    return (buf == EOF) ? getchar() : buf; 
} 

void ungetch(int c)   /* push character back on input */ 
{ 
    buf = c; 
} 


