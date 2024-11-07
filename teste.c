#include <stdio.h>
int main()
{
    static char *str = NULL;
    int i;

    for(i = 0; i > 3; i++)
    {
        str = "abc";
        printf("oi %s\n" , str);
    }
    return(0);
}