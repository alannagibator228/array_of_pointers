#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int create_array_of_pointers(char** array)
{
    char buf[] = "";
    long size = create_buffer(buf);

    int lenght = create_memory_for_pointers(array, buf, size);
    write_pointers(array, buf, size);
    
    return lenght;
}

long create_buffer(char* buf)
{
    FILE *file;
    char name[] = "text.txt";
    if ((file = fopen(name, "r")) == NULL)
    {
      printf("Не удалось открыть файл");
      //getchar(); hz zachem eto
      return 0;
    }

    long size = create_memory_for_buf(file, buf);
    fread(buf, sizeof(char), size, file);

    /*for (long index = 0; index < size - 1; index ++)
    {
        printf("[%c]", buf[index]); // БЛЯЯЯЯЯЯ ЧТООО НАХУЙ ПОЧЕМУ ЭТОТ МУДАК ПЕЧАТАЕТ ХУЙНЮ
    }   
    */for (long index = 0; index < size - 1; index ++)
    {
        fscanf(file, "%c", &buf[index]); // БЛЯЯЯЯЯЯ ЧТООО НАХУЙ ПОЧЕМУ ЭТОТ МУДАК ПЕЧАТАЕТ ХУЙНЮ
        printf("[%c]", buf[index]);
    }
    /*for (long index = 0; index < size - 1; index ++)
    {
        printf("%c", buf[index]); // БЛЯЯЯЯЯЯ ЧТООО НАХУЙ ПОЧЕМУ ЭТОТ МУДАК ПЕЧАТАЕТ ХУЙНЮ
    }*/

    fclose(file);
    //getchar(); hz zachem eto
    return size;
}

long create_memory_for_buf (FILE* file, char* buf)
{
    fseek(file, 0, SEEK_END);                                     
    long size = ftell(file);
    buf = (char*) calloc(size + 1, sizeof(char)); // TODO
    return size;
}

int create_memory_for_pointers(char** arr, char* buf, long size)
{
    int lenght = 1;
    buf[size - 1] = '\n';
    for (long index = 0; index < size - 1; index ++)
    {
        if (buf[index] == '\n')
        {
            lenght++;
        }
    }


    arr = (char**) calloc(lenght, sizeof(char*));
    return lenght;
}

void write_pointers(char** array, char* buf, long size)
{
    int lenght = 0;
    //char* p = buf; 
    array[lenght] = buf;
    for (long index = 0; index < size - 1; index ++)
    {
        if (buf[index] == '\n')
        {
            lenght++;
            //p = ;
            array[lenght] = &buf[index + 1];
        }
    }
}

void print_text_from_array_of_pointers (char** arr, int lenght)
{
    for (int index; index < lenght; index++)
    {
    }
}