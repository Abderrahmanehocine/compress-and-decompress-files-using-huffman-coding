#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "write.h"


void write_huffman_tree(FILE *filename, huffman_node *root) {
    if (root == NULL) 
        return;
    fprintf(filename,"(%d,%d)\n", root->character,root->freqency);
    write_huffman_tree(filename, root->left_child);
    write_huffman_tree(filename, root->right_child);
}

bool write_data(const char *filename, const char *data_code, int node_number, huffman_node *root) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s.\n", filename);
        return 0;
    }
    fprintf(file,"%d\n", node_number);
    write_huffman_tree(file, root);
    fwrite(data_code, sizeof(char), strlen(data_code), file);
    fprintf(file,"\n");
    fclose(file);
    return 1;
}

bool write_decoded_data(const char *filename,const char *data){
    if(data == NULL)
        return 0;
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s.\n", filename);
        return 0;
    }
    fprintf(file,"%s",data);
    fclose(file);
    return 1;
}



