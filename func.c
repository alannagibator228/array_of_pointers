#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "func.h"
//-lasan -fsanitize=address -ggdb3

void create_array_of_pointers(char*** array, char ** buffer)
{
    FILE *file;
    
    if ((file=fopen("text.txt", "rb")) == NULL)
    {
    printf("Cannot open file.\n");
    }
    
    
    int size_without_plus_byte = cum_in_buffer(file, buffer);
    int size_plus_byte = size_without_plus_byte + 1;

    ////////////////////// cum in array //or// memory for array
    int length = 1;
    for (int index = 1; index < size_without_plus_byte; index++)  // передать size_without_plus_byte
    {
        if((*buffer)[index] == '\n')                 // передать buffer
        {
            length++;
        }
    }
    *array = (char**) calloc(length, sizeof(char*)); // грамотно передать и использовать aaray // если делаю memory => return length;
    
    /////////////////////             //or// cum in array
    (*array)[0] = *buffer;                               //впринципе передавать только array и buffer
    int index_for_array = 1;
    for (int index = 0; index < size_without_plus_byte; index++)  
    {
        if((*buffer)[index] == '\n')
        {
            (*array)[index_for_array] = *buffer + index + 1;
            index_for_array++;
        }
    }

    fclose (file);
}

int cum_in_buffer(FILE* file, char** buffer)
{
    struct stat file_inf;
    fstat (fileno (file), &file_inf); 
    int size_without_plus_byte = file_inf.st_size; 
    int size_plus_byte = size_without_plus_byte + 1;
    
    *buffer = (char*) calloc(size_plus_byte, sizeof(char)); 
    
    fread(*buffer, sizeof(char), size_without_plus_byte, file);
    (*buffer)[size_plus_byte - 1] = '\n';

    return size_without_plus_byte;
}