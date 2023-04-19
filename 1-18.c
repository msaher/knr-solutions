#include <stdio.h>
#define MAX 100

int mygetline(char line[], int maxline);
int isblnk(char c);
void copy(char to[], char from[]);
void strip(char line[], int len);

int main()
{
    char line[MAX];
    int len;
    while((len = mygetline(line, MAX)) > 0){
        strip(line, len);
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

int isblnk(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

void strip(char line[], int len)
{
    int i = len-2;
    for(; i >= 0 && isblnk(line[i]); i--);
    if(i > 0) {
        line[i+1] = '\n';
        line[i+2] = '\0';
    }
    else
        line[0] = '\0';
}
