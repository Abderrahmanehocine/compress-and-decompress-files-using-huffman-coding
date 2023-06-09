#ifndef CODING_CODING_H
#define CODING_CODING_H

#define MAX_TEXT_SIZE 1024
#define ASCII_SIZE 256
#define MAX_BITS 9 

extern int charachter_number;
extern int nodes_number;

typedef struct huffman_node{
    int character;
    int freqency;
    struct huffman_node *left_child;
    struct huffman_node *right_child;
} huffman_node;

typedef struct character{
    int character;
    char code[100];
} character;

huffman_node *build_huffman_tree(int *freq);
void create_char_code(huffman_node *root, character **char_nodes, char *code);
char *Create_message_code(char *text, character **nodes);
void freeTree(huffman_node* root);
void freeChars(character **nodes);

#endif