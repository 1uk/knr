/* knr book exercise 1-23, cmr: remove comments
 * Lukas Kitsche    21 Thu 30 May 14:19 */

#include <stdio.h>

#define NML     1   /* NORMAL */
#define COM     2   /* COMMENT */
#define C99     3   /* C99 (//)  Comment */
#define OLDC    4   /* old C comment like this one */
#define OLDCOUT 5   /* ending '*' of a old C comment */
#define SQ      6   /* single quotes */
#define SQB     7   /* escape sequency in SQ */
#define DQ      8   /* double quotes */
#define DQB     9   /* escape sequency in DQ */

int main()
{
    int state = NML; /* current state */
    char c;          /* current char */

    while ((c = getchar()) != EOF) {
        switch (state) {
            case NML:   /* 1 */
                if (c == '/') {
                    state = COM;
                }
                else if (c == '"') {
                    state = DQ;
                    putchar(c);
                }
                else if (c == '\'') {
                    state = SQ;
                    putchar(c);
                }
                else {
                    putchar(c);
                }
                break;

            case COM: /* 2 */
                if (c == '/')
                    state = C99;
                else if (c == '*')
                    state = OLDC;
                else {
                    state = NML;
                    putchar('/');
                    putchar(c);
                }
                break;
            case C99: /* 3 */
                if (c == '\n') {
                    state = NML;
                    putchar(c);
                }
                break;
            case OLDC: /* 4 */
                if (c == '*')
                    state = OLDCOUT;
                break;
            case OLDCOUT: /* 5 */
                if (c == '/')
                    state = NML;
                else
                    state = OLDC;
                break;
            case SQ: /* 6 */
                if (c == '\'')
                    state = NML;
                else if (c == '\\')
                    state = SQB;
                putchar(c);
                break;
            case SQB: /* 7 */
                state = SQ;
                putchar(c);
                break;
            case DQ: /* 8 */
                if (c == '"')
                    state = NML;
                else if (c == '\\')
                    state = DQB;
                putchar(c);
                break;
            case DQB: /* 9 */
                state = DQ;
                putchar(c);
                break;
            default: /* shouldn't happen */
                printf("Error, current state: %d, current char: %c", state, c);
                return 1;

        }
    }

    return 0;
}
