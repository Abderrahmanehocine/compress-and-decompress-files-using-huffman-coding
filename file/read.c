#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

long int last_pos = 0;
int lines_number = 0;

char *read_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s.\n", filename);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    char data[MAX_LENGTH] = "";
    while (fgets(line, MAX_LENGTH, file) != NULL) {
        strcat(data,line);
    }

    fclose(file);

    return strdup(data);
}

int read_nodes_number(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s.\n", filename);
        return -1;
    }
    
    char line[100];
    int number = 0;

    fgets(line, sizeof(line), file);
    sscanf(line,"%d",&number);

    last_pos = ftell(file);
    fclose(file);

    return number;
}

void read_tree(const char *filename, int nodes_number, huffman_node **nodes) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s.\n", filename);
        return;
    }

    char line[256];

    fseek(file, last_pos, SEEK_SET);

    int i;
    for(i=0 ; i < nodes_number ; i++){
        fgets(line, sizeof(line), file);
        nodes[i] = (huffman_node*)malloc(sizeof(huffman_node));
        sscanf(line, "(%d,%d)", &nodes[i]->character, &nodes[i]->freqency);
        nodes[i]->left_child = nodes[i]->right_child = NULL;
    }

    last_pos = ftell(file);
    fclose(file);
}

char *read_code(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s.\n", filename);
        return NULL;
    }
    char line[5000];

    fseek(file, last_pos, SEEK_SET);
    fgets(line, sizeof(line), file);

    fclose(file);

    return strdup(line);
}
