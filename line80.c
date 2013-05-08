/* The C Programming Language - 1.9 Character Arrays - Exercise 1-17
 * line80: prints all input lines that are longer than 80 characters
 * Lukas Kitsche    Sun 17 Mar 2013 */

#include <stdio.h>
#define MAXLINE 1000    /* max length of an input line */

int mygetline(char line[], int maxline);

int main()
{
    char line[MAXLINE];  /* current input line */
    int len;            /* current line length */


    while((len = mygetline(line, MAXLINE)) > 0)
        if(len > 80)
            printf("%s\n", line);
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int i;

    for(i=0; (s[i]=getchar())!='\n' && s[i]!=EOF && i<lim-1; ++i);
    if(s[i]=='\n'){
        ++i;
        s[i] = '\0';
    }
    else
        s[i] = '\0';
    return i;
}
