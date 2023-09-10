#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    char** array = NULL;
    char* buffer = NULL;
    
    create_array_of_pointers(&array, &buffer);

    for (int i = 0; i < 4; i++)
    {
        printf("%p [%c]\n", array[i], array[i][0]);
    }
    
    
    free(array);
    free(buffer);

    return 0;
}