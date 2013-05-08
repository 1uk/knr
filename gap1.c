/* The C Programming Language - 1.9 Character Arrays - Exercise 1-18
 * gap1: removes trailing blanks, tabs and newlines
 * Lukas Kitsche    Mon 18 Mar 2013 */

#include <stdio.h>
#define MAXLINE 1000    /* max line size */
#define TRUE    1
#define FALSE   0

int filtergaps(char line[], int maxline);

int main()
{
    char line[MAXLINE];  /* current line */
    int len;             /* line length */

    while((len = filtergaps(line, MAXLINE)) > 0){
        printf("%s", line);
    }
}

/* filtergaps: reads filtered input string into s[], returns length (only under MAXLINE) */
int filtergaps(char s[], int lim)
{
    char c;
    int i;
    int gap = FALSE; /* last char wasn't a blank, tab or newline */

    for(i=0; (c=getchar()) != '\n' && c != EOF && i < lim-1;){
        if(c != ' ' && c != '\t' && gap == TRUE) /* current char isn't a gap */
            gap = FALSE;
        if(gap == FALSE){           /* current char isnt a trailing gap */
            s[i] = c;
            ++i;
        }
        if(c == ' ' || c == '\t')   /* current char is a gap */
            gap = TRUE;
    }
    if(i == 1 && gap == TRUE)   /* line contains only gaps */
        s[0] = '\0';            /* ugly way to print nothing */
    else if(c == '\n'){         /* most lines end with a newline */
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
