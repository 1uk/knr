/* The C Programming Language - Ex 1-19
 * reverseS: reverses input strings and prints them out, assuming sting ends with '\n''\0'.
 * Lukas Kitsche    Wed 20 Mar 2013 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum line length */

void reverseS(char line[], int len);

int main()
{
    char line[MAXLINE];     /* current line */
    int len;                /* current line length */

    while((len = mygetline(line, MAXLINE)) > 0){
        reverseS(line, len);
        printf("%s", line);
    }
    return 0;
}

/* reverseS: reverses s[] assuming s[] ends with '\n''\0' */
void reverseS(char s[], int len)
{
    char c;
    int i;

    for(i=0; i < (len-1)/2; ++i){   /* i goes from zero to middle */
        c = s[i];
        s[i] = s[len-2-i];      /* -2 because of '\n' and '\0' */
        s[len-2-i] = c;
    }
}


/* mygetline: read a line into s, return length
 * length is the tuple containing last char */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
