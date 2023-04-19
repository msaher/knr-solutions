#include <stdio.h>
#define MAX 100

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);
int length(char s[]);

int main()
{
    char line[MAX];
    int len;
    while((len = mygetline(line, MAX)) > 0){
        /* printf("%d\n%d", len, length(line)); */
        reverse(line);
        printf("%s", line);
    }
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

int length(char s[])
{
    int len = 0;
    while(s[len] != '\0') {
        ++len;
    }
    return len
}

void reverse(char s[])
{
    int len = length(s);
    int last = len-2; /* last character to reverse */
    int tmp;
    for(int i = 0; i < (last)/2+1; i++) {
        tmp = s[i];
        s[i] = s[last-i];
        s[last-i] = tmp;
    }
}
