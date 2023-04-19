void itoa(int n, char s[]);
void reverse(char s[]);

/* itoa:  convert n to characters in s */ 
void itoa(int n, char s[]) 
{ 
    int i, sign; 
    unsigned int un;

    if ((sign = n) < 0)  /* record sign */ 
        un = -n;          /* make n positive */ 
    else
        un = n;
    i = 0; 
    do {      /* generate digits in reverse order */ 
        s[i++] = un % 10 + '0';  /* get next digit */ 
    } while ((un /= 10) > 0);    /* delete it */ 
    if (sign < 0) 
        s[i++] = '-'; 
    s[i] = '\0'; 
    reverse(s); 
} 

/* reverse:  reverse string s in place */ 
void reverse(char s[]) 
{ 
    int c, i, j; 
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) { 
        c = s[i]; 
        s[i] = s[j]; 
        s[j] = c; 
    } 
} 
