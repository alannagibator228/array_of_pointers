#ifndef FUNC_H
#define FUNC_H

int create_array_of_pointers(char** array);

long create_buffer(char* buf);
long create_memory_for_buf(FILE* file, char* buf);

int create_memory_for_pointers(char** arr, char* buf, long size);
void write_pointers(char** array, char* buf, long size);

void print_text_from_array_of_pointers (char** arr, int lenght);

#endif