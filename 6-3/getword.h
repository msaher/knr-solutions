#ifndef GETWORD
#define GETWORD
#define getch() getc(stdin)
#define ungetch(c) ungetc(c, stdin)
int getword(char *word, int lim);
#endif
