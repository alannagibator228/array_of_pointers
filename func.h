#ifndef FUNC_H
#define FUNC_H

int create_array_of_pointers(char*** array, char** buffer);
int write_in_buffer(FILE* file, char** buffer);
int memory_for_array (char*** array, char** buffer, int size_without_plus_byte);
void write_in_array (char*** array, char** buffer, int size_without_plus_byte);

#endif