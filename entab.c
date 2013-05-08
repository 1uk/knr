/* KnR - Exercise 1-21
 * entab: replaces strings of blanks by the minimum number of tabs and blanks in the input
 * Lukas Kitsche    Fri 22 Mar 2013 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum line size */
#define TABSTOP 4       /* number of chars in a tab */
#define TABCHAR '-'     /* chars a tab is filled with */
#define SPACECHAR ' '   /* char which stands for a blank */

int entab(char line[], int maxline);

int main()
{
    char line[MAXLINE];  /* current line */

    while(entab(line, MAXLINE) > 0)
        printf("%s", line);
}

/* entab: replaces strings by the minimum number of tabs and blanks in the input, returns length */
int entab(char s[], int lim)
{
    int i, b, c;
    int w = 0;  /* trailing whitespaces */
    char charbuff;

    i = 0;
    while((s[i]=getchar())!='\n' && s[i] != EOF && i < lim-1){
        if(s[i] == ' ')     /* current char is a whitespace */
            ++w;
        else if(w > 0){     /* last char/s was/were whitespace/s, but current isnt */
            charbuff = s[i];
            for(int b=0; b<=w-TABSTOP; b+=4)      /* insert tabs */
                for(int c=0; c<TABSTOP; ++c){
                    s[i] = TABCHAR;
                    ++i;
                }
            for(int b=0; b<w%TABSTOP; ++b){     /* insert blanks */
                s[i] = SPACECHAR;
                ++i;
            }
            s[i] = charbuff;
            ++i;
            w = 0;
        }
        else
            ++i;
    }
    if(s[i] == '\n')    /* current char is a newline */
        ++i;
    s[i] = '\0';
    return i;   /* return string length */
}

