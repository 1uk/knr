/* K&R Ex 1-22
 * linebreak: "folds" long input lines into two or more
 * Lukas Kitsche    Mon 26 Mar 2013 */

#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */
#define LINEBREAK 50   /* where the line is to be broken */
#define BREAKRANGE 1 /* range where whitespaces are searched */

int folder(char line[], int maxline);

int main(void)
{
    char line[MAXLINE]; /* current line */

    while (folder(line, MAXLINE) > 0)
        printf("%s", line);
    return 0;
}

/* folder: folds long input lines, returns length */
int folder(char s[], int lim)
{
    int i, w;

    for (i=0; (s[i]=getchar()) != EOF && s[i] != '\n' && i < lim-2; ++i) {
        if (s[i] == ' ' || s[i] == '\t')
            w = i;
        if (i % LINEBREAK == 0 && i != 0) {
            if (w % LINEBREAK > LINEBREAK-1 - BREAKRANGE || w % LINEBREAK == 0) {
                s[w] = '\n';
            } else {
                ++i;
                s[i] = '-';
                ++i;
                s[i] = '\n';
            }
        }
    }
    if (s[i] == '\n')
        ++i;
    s[i] = '\0';
    return i;
}
