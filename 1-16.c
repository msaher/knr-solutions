#include <stdio.h>
#define MAXLINE 10

/* replace getline with mygetline because getline is a built in
 * function in the standared library */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    int c;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        if(line[len-1] != '\n') /* Line exceeds the limit */
            while((c = getchar()) != EOF && c != '\n'){
                len++;
            }

        if (len > max) {
            max = len;
            copy(longest, line);
        }

    }
    if (max > 0)
        printf("%s", longest);
        printf("\n%d characters\n", max);
        /* printf("%c", longest[MAXLINE-2]); */
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
