/* todo: cmr(): delete empty lines */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXLINE 1000    /* maximum input line */
#define NORMAL  0       /* used for state in function cmr() */
#define COMMENT 1       /* used for state in function cmr() */
#define QUOTE   2       /* used for state in function cmr() */


int cmr(char s[], int lim);
int mygetline(char s[], int lim);

int main()
{
    char line[MAXLINE];     /* current line */

    while (mygetline(line, MAXLINE) > 0) {
        cmr(line, MAXLINE);
        printf("%s", line);
    }
    return 0;
}

/* cmr: remove comments, return new length, assuming every given string ends with a '\0' */
int cmr (char s[], int lim)
{
    int state;      /* current state */
    int i,a;

    state = NORMAL;
    for (i=0, a=0; (s[i]=s[a]) != '\0'; ++i, ++a) {
        if (s[a] == '"') {
            if (state == NORMAL)                                        /* quote start */
                state = QUOTE;
            else if (state == QUOTE)                                    /* quote end */
                state = NORMAL;
            state = QUOTE;
        }
        else if (s[a] == '/' && s[a+1] == '*' && state == NORMAL) {     /* comment start */
            state = COMMENT;
            --i;
        }
        else if (state == COMMENT) {                                    /* while comment */
            --i;
            if (s[a-1] == '*' && s[a] == '/')                           /* comment end */
                state = NORMAL;
        }
    }
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
