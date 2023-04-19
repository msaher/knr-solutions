#include <stdio.h>
#define MAX 15
#define MIN 10

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;
    int max;
    char line[MAX];
    char longest[MAX];

    int c;
    while ((len = mygetline(line, MAX)) > 0) {
        if(len > MIN) { /* Line exceeds the limit */
            printf("%s", line);
            if(line[len-1] != '\n') {
                while((c = getchar()) != EOF && c != '\n')
                    putchar(c);
                putchar('\n');
            }
        }
    }
    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i;

    for(i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
