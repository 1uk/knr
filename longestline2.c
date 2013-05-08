/* The C Programming Language - 1.9 Character Arrays - Exercise 1-16
 * Lukas Kitsche    Sun 17 Mar 2013 */

#include <stdio.h>
#define MAXLINE 10    /* maximum input line size */

int mygetline(char line[], int maxline);    /* getline() exists in stdio.h, -> prefix my */
void copy(char to[], char from[]);

/* print longest input line */
main()
{
        int len;            /* current line length */
        int max;            /* maximum length seen so far */
        char line[MAXLINE];     /* current input line */
        char longest[MAXLINE];  /* longest line saved here */

        max = 0;
        while ((len = mygetline(line, MAXLINE)) > 0)
            if (len > max) {
                max = len;
                copy(longest, line);
            }
        if (max > 0)    /* there was a line */
            printf("\n Longest Line: %s Length: %d\n", longest, max);
        return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i){
        if(i < lim-1)
            s[i] = c;   /* until s[] is full */
    }
    if(c == '\n'){      /* if the line ends with a newline */
        if(i < lim-1){  /* and fits into s[] */
        s[i] = c;
        s[i+1] = '\0';
        }
        ++i;    /* number newline among len */
    }
    else
        s[lim] = '\0';      /* line was too long */
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
