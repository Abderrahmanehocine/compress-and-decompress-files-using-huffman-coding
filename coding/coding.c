#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "coding.h"

int charachter_number = 0;
int nodes_number = 0;

huffman_node *build_huffman_tree(int *freq) {
    huffman_node *tree_node[ASCII_SIZE];
    int node_index = 0;

    int i;
    for(i = 0 ; i < ASCII_SIZE ; i++){
        if(freq[i] > 0){
            huffman_node *node = (huffman_node*)malloc(sizeof(huffman_node));
            node->character = i;
            node->freqency  = freq[i];
            node->left_child= NULL;
            node->right_child= NULL;
            tree_node[node_index++] = node;
        }
    }
    charachter_number = node_index;
    while(node_index > 1){
        int min_index1 = -1;
        int min_index2 = -2;
        for(i=0 ; i < node_index ; i++){
            if(min_index1 == -1 || tree_node[i]->freqency < tree_node[min_index1]->freqency){
                min_index2 = min_index1;
                min_index1 = i;
            }
            else if(min_index2 == -1 || tree_node[i]->freqency < tree_node[min_index2]->freqency)
                min_index2 = i;
        }

        huffman_node *new_node = (huffman_node*)malloc(sizeof(huffman_node));
        nodes_number++;
        new_node->character = -1;
        new_node->freqency  = tree_node[min_index1]->freqency + tree_node[min_index2]->freqency;
        new_node->left_child = tree_node[min_index1];
        new_node->right_child = tree_node[min_index2];
        

        if (min_index1 < min_index2) {
            tree_node[min_index1] = new_node;
            tree_node[min_index2] = tree_node[node_index-1];
        } else {
            tree_node[min_index2] = new_node;
            tree_node[min_index1] = tree_node[node_index-1];
        }
        node_index--;
    }
    // Return the root of the tree
    return tree_node[0];
}

void create_char_code(huffman_node *root, character **char_nodes, char *code) {
    if(root == NULL)
        return;
    if (root->left_child != NULL) {
        strcat(code,"0");
        create_char_code(root->left_child, char_nodes, code);
        if(root->right_child != NULL){
            strcat(code,"1");
            create_char_code(root->right_child, char_nodes, code);
        }
    }
    else{
        character *new_node = (character*)malloc(sizeof(character));
        new_node->character = root->character;
        strcpy(new_node->code,code);
        char_nodes[root->character] = new_node;
    }
    code[strlen(code)-1] = '\0';
}

char *Create_message_code(char *text, character **nodes) {
    char *message = NULL;
    size_t message_size = 0;

    for (size_t i = 0; i < strlen(text); i++) {
        int char_number = (int) text[i];
        char *code = nodes[char_number]->code;
        size_t code_size = strlen(code);

        // Resize the message buffer to accommodate the new code
        message_size += code_size;
        message = realloc(message, message_size + 1);  // +1 for the null terminator

        if (message == NULL) {
            // Memory allocation failed, clean up and return NULL
            free(message);
            return NULL;
        }

        // Append the new code to the message buffer
        strcat(message, code);
    }
    return message;
}

void freeTree(huffman_node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left_child);
    freeTree(root->right_child);
    free(root);
}

void freeChars(character **nodes) {
    int i;
    for(i=0 ; i<charachter_number ; i++)
        free(nodes[i]);
}