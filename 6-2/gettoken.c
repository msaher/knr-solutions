#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#define MAXWORD 100
#define getch() getc(stdin)
#define ungetch(c) ungetc(c, stdin)

int gettoken(void);

/* int gettoken(void)  /1* return next token *1/ */ 
/* { */ 
/*     int c */
/*     char *p; */

/*     while ((c = getch()) == ' ' || c == '\t') */ 
/*         ; */
/*     if (c == '(') { */ 
/*         if ((c = getch()) == ')') { */ 
/*             strcpy(token, "()"); */ 
/*             return tokentype = PARENS; */ 
/*         } else { */ 
/*             ungetch(c); */ 
/*             return tokentype = '('; */ 
/*         } */ 
/*     } else if (c == '[') { */ 
/*         for (*p++ = c; (*p++ = getch()) != ']'; ) */ 
/*             ; */ 
/*         *p = '\0'; */ 
/*         return tokentype = BRACKETS; */ 
/*     } else if (isalpha(c)) { */ 
/*         for (*p++ = c; isalnum(c = getch()); ) */ 
/*             *p++ = c; */ 
/*         *p = '\0'; */ 
/*         ungetch(c); */ 
/*         return tokentype = NAME; */ 
/*     } else */ 
/*         return tokentype = c; */ 

/* } */ 
/* getch and ungetch are discussed in Chapter 4. */  

/* } */
