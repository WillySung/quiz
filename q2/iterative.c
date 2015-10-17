/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char smallest_character(char str[], char c)
{
    int i=0;
    while(str[i]!='\0') {
        if(str[i]>c)
            return str[i];
        i++;
    }
    return str[0];
}

int main()
{
    char a[20] = {'c','f','j','p','v'};
    char b[20] = {'c','c','k'};
    char ans=smallest_character(a,'a');
    printf("%c\n", ans);
    ans=smallest_character(a,'c');
    printf("%c\n", ans);
    ans=smallest_character(a,'z');
    printf("%c\n", ans);
    ans=smallest_character(b,'f');
    printf("%c\n", ans);
    return 0;
}
