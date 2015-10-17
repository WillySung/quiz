/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char smallest_character(char str[], char c, int ptr)
{
    if(str[ptr]=='\0')	return str[0];
    if(str[ptr]>c) return str[ptr];
    else {
        return smallest_character(str,c,ptr+1);
    }
}

int main()
{
    char a[100] = {'c','f','j','p','v'};
    char b[100] = {'c','c','k'};
    char ans=smallest_character(a,'a',0);
    printf("%c\n", ans);
    ans=smallest_character(a,'c',0);
    printf("%c\n", ans);
    ans=smallest_character(a,'z',0);
    printf("%c\n", ans);
    ans=smallest_character(b,'f',0);
    printf("%c\n", ans);
    return 0;
}
