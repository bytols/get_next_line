#include <stdio.h>
void test(char a)
{
    static char *str = NULL;
    str = &a;
    printf("%c\n" , *str);
}


int main()
{
    int i;

    test('a');
    test('b');
    test('c');

    return(0);
}

