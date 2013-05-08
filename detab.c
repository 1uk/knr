/* Exercise 1-20
 * detab: replaces each tab with n whitespaces
 * Lukas Kitsche    Thu 21 Mar 2013 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define TABSTOP 4       /* n whitespaces */

int retab(char line[], int maxline);

int main()
{
    char line[MAXLINE];  /* current line */

    while(retab(line, MAXLINE) > 0)
        printf("%s", line);
    return 0;
}

/* retab: read a line into s, replacing tabs with n whitespaces, return length */
int retab(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n';){
        if(c == '\t')
            for(int b=0; b<TABSTOP; ++b, ++i)
                s[i] = ' ';
        else{
            s[i] = c;
            ++i;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

