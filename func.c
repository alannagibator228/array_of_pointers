#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "func.h"
//-lasan -fsanitize=address -ggdb3

void create_array_of_pointers(char** array)
{
    FILE *file;
    
    if ((file=fopen("text.txt", "rb")) == NULL)
    {
    printf("Cannot open file.\n");
    }
    
    char* buffer = NULL;
    int size_plus_byte = cum_in_buffer(file, &buffer);

    for (int i = 0; i < size_plus_byte; i++)
    {
        printf("%c", buffer[i]);
    }

    free(buffer);
    fclose (file);
}

int cum_in_buffer(FILE* file, char** buffer)
{
    struct stat file_inf;
    fstat (fileno (file), &file_inf); 
    int size_plus_byte = file_inf.st_size + 1; 
    
    *buffer = (char*) calloc(size_plus_byte, sizeof(char)); 

    fread(*buffer, sizeof(char), size_plus_byte, file);
    (*buffer)[size_plus_byte - 1] = '\n';

    return size_plus_byte;
}