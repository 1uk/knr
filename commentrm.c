/* cmr.c is a better solution
 * K&R Exercise 1-23: remove c comments
 * Lukas Kitsche    Fri 17 May 2013 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* values for state */
#define NORMAL 0    /* when inside normal code */
#define CCOM 1      /* when inside a c comment */
#define EXITING 2   /* when exiting a c comment */
#define C99COM 3    /* when inside a c99 comment */
#define SQUOTE 4    /* when inside a single quote */
#define DQUOTE 5    /* when inside a double quote */
#define DQB 6       /* when last char was a backslash */
#define SQB 7

int main()
{
    char buf[2];    /* char buffer */
    int state;      /* current state */

    state = NORMAL; /* starting with NORMAL state */
    buf[1] = getchar();
    while ((buf[0]=buf[1]) != EOF){
        buf[1] = getchar();
        if (state == NORMAL){
            if (buf[0] == '/' && buf[1] == '*') { /* entering c comment */
                state = CCOM;
            }
            else if (buf[0] == '/' && buf[1] == '/') { /* entering a c99 comment */
                state = C99COM;
            }
            else if (buf[0] == '"') { /* entering double quote */
                state = DQUOTE;
                putchar(buf[0]);
            }
            else if (buf[0] == '\'') { /* entering single quote */
                state = SQUOTE;
                putchar(buf[0]);
            }
            else {                  /* resting in state normal */
                putchar(buf[0]);
            }
        }
        else if (state == DQUOTE) {
            putchar(buf[0]);
            if (buf[0] == '\\') /* entering escape sequency */
                state = DQB;
            else if (buf[0] == '"')
                state = NORMAL; /* exiting double quote */
        }
        else if (state == SQUOTE) {
            putchar(buf[0]);
            if (buf[0] == '\\') /* entering escape sequency */
                state = SQB;
            else if (buf[0] == '\'')
                state = NORMAL; /* exiting single quote */
        }
        else if (state == CCOM && buf[0] == '*' && buf[1] == '/') { /* exiting c comment step 1 */
            state = EXITING;
        }
        else if (state == EXITING) { /* exiting c comment step 2 */
            state = NORMAL;
        }
        else if (state == C99COM && buf[0] == '\n') { /* exiting c99 comment */
            state = NORMAL;
        }
        else if (state == DQB) { /* exiting escape sequency, going back to double quote */
            state = DQUOTE;
            putchar(buf[0]);
        }
        else if (state == SQB) { /* exiting escape sequency, going back to single quote */
            state = SQUOTE;
            putchar(buf[0]);
        }
    }
}
