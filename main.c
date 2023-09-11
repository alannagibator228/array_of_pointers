#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    char** array = NULL;
    char* buffer = NULL;
    
    int length = create_array_of_pointers(&array, &buffer);

    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%p [%c]\n", array[i], array[i][0]);
    // }

    // int symbol_num;
    // for (int line_num = 0; line_num < length; line_num++)
    // {
    //     symbol_num = 0;
    //     while (array[line_num][symbol_num] != '\n')
    //     {
    //         printf("%c", array[line_num][symbol_num]);
    //         symbol_num++;
    //     }
    // }

    int symbol_num = 0;
    int line_num = 0;
    while (array[line_num][symbol_num] != '\n')
    {
        printf("%c", array[line_num][symbol_num]);
        //printf("%d %d\n", line_num, symbol_num);
        symbol_num++;
    }

    // printf("%c", array[0][0]);
    // printf("%c", array[0][1]);
    // printf("%c", array[0][2]);
    // printf("%c", array[0][3]);
    // printf("%c", array[0][4]);


    
    
    free(array);
    free(buffer);

    return 0;
}