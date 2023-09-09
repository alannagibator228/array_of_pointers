#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "func.h"
//-lasan -fsanitize=address -ggdb3

void create_array_of_pointers(char** array)
{
    FILE *file;
    struct stat file_inf;
    if ((file=fopen("text.txt", "rb")) == NULL)
    {
    printf("Cannot open file.\n");
    exit (1);
    }
    /* заполнение структуры типа stat */
    fstat (fileno (file), &file_inf);
    int size = file_inf.st_size;
    char* buffer = NULL;
    buffer = (char*) calloc(size, sizeof(char));
    fread(buffer, sizeof(char), size, file);
    
    for (int i = 0; i < size; i++)
    {
        printf("%c", buffer[i]);
    }

    fclose (file);
}