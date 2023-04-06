#ifndef FILE_READ_H
#define FILE_READ_H

#define MAX_LINE_LENGTH 1056
#define MAX_LENGTH 5000

#include <stdbool.h>
#include "../coding/coding.h"


extern long int last_pos;
extern int lines_number;

char *read_from_file(const char *filename);
int read_nodes_number(const char *filename);
void read_tree(const char *filename, int nodes_number, huffman_node **nodes);
char *read_code(const char *filename);



#endif