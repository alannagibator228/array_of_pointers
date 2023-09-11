#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "func.h"
//-lasan -fsanitize=address -ggdb3

int create_array_of_pointers(char*** array, char ** buffer)
{
    FILE *file;
    
    if ((file=fopen("text.txt", "rb")) == NULL)
    {
    printf("Cannot open file.\n");
    }
    
    
    int size_without_plus_byte = write_in_buffer(file, buffer);
    int size_plus_byte = size_without_plus_byte + 1;

    int length = memory_for_array (array, buffer, size_without_plus_byte);
    write_in_array (array, buffer, size_without_plus_byte);

    fclose (file);
    return length;
}

int write_in_buffer(FILE* file, char** buffer)
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

int memory_for_array (char*** array, char** buffer, int size_without_plus_byte)
{
    int length = 1;
    for (int index = 1; index < size_without_plus_byte; index++)  
    {
        if((*buffer)[index] == '\n')                
        {
            length++;
        }
    }
    *array = (char**) calloc(length, sizeof(char*));
    return length;
}

void write_in_array (char*** array, char** buffer, int size_without_plus_byte)
{
    (*array)[0] = *buffer;                        
    int index_for_array = 1;
    for (int index = 0; index < size_without_plus_byte; index++)  
    {
        if((*buffer)[index] == '\n')
        {
            (*array)[index_for_array] = *buffer + index + 1;
            index_for_array++;
        }
    }
}