#ifndef FILE_WRITE_H
#define FILE_WRITE_H

#include <stdbool.h>
#include "../coding/coding.h"

bool write_data(const char *filename, const char *data_code, int node_number, huffman_node *root);
void write_huffman_tree(FILE *filename, huffman_node *root);
bool write_decoded_data(const char *filename,const char *data);


#endif