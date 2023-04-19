#ifndef GETWORD
#define GETWORD
#include "globals.h"
#define getch() getc(stdin)
#define ungetch(c) ungetc(c, stdin)
int getword(char *word, int lim);
#endif
