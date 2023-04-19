#include <stdio.h>
#include <string.h>

void escape(char[], char[]);
void unescape(char s[], char t[]);

int main() {
    char t[] = "v\tic\nheheh\tcool";
    char s[2*strlen(t)];
    escape(s,t);
    printf("escapring:\n");
    printf("%s\n", t);
    printf("%s\n", s);

    printf("\nUnescaping:\n");
    unescape(s,t);
    printf("%s\n", t);
    printf("%s\n", s);
    return 0;
}

void unescape(char s[], char t[]) {
    int i = 0; int j = 0;
    char c;
    while((c = t[i++]) != '\0') {
        switch(c) {
            case '\\':
                c = t[i+1];
                if(c != '\0') i++;
                switch(c) {
                    case '\0':
                        break;
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = c;
                        break;
                }
                break;
            default:
                s[++j] = c;
        }
    }

    s[j] = '\0';

}

void escape(char s[], char t[])
{
    int i = 0; int j = 0;

    char c;
    while((c = t[i++]) != '\0')
        switch(c) {
            case '\t':
                s[j++] = '\\'; s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\'; s[j++] = 'n' ;
                break;
            default:
                s[j++] = c;
                break;
        }
    s[j] = '\0';
}
