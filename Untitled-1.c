#include <stdio.h>
#include <stdlib.h>

// ПРочитай про локальные переменные в функциях си

void zero (int a)
{
    a = 0;

    printf("a in function: %d\n", a);
}

int main ()
{
    int a = 1;

    printf("a before zero: %d\n", a);

    zero(a);

    printf("a after zero: %d\n", a);

    return 0;
}
