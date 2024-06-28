#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MADMAX 100

int mirror ( char *s, char *c ) {
    int error = 0, i = 0, x = 0;
    char *temp = ( char* ) malloc (MADMAX);
    for ( char *p = s, *q = s + strlen(s) - 1; p <= q; ++p, --q ) {
        if ( *p != *q ) {
            error++;
            i = 0;
            *temp = '\0';
            if ( *(p - 1) == *(q + 1) )
                x = 2;
            
        }
        else if ( *p == *q )
            *(temp + i++) = *p;
        if ( strlen(c) < strlen(temp) ) {
            strcpy(c, temp);
            x = 0;
        }
    }
    if (x) error = x;
    return error;
}


int main()
{
    char s[MADMAX], *c = ( char* ) malloc (MADMAX);
    int t = 1, x = 0;
    printf(" enter a string: ");
    gets(s);
    x = mirror(s, c);
    if (!x)
        puts(" the string is palindrome ");
    else {
        puts(" the string is not palindrome but here's the longest palindrome substring in it:");
        for ( char *p = c; p >= c; p += t ) {
            if ( p == c + strlen(c) - 1 ) {
                t *= -1;
                if ( x == 2 )
                    putchar(*p);
            }
            putchar(*p);
        }
    }
    return 0;
}
