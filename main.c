#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file/read.h"
#include "coding/coding.h"
#include "file/write.h"
#include "decoding/decoding.h"

void calculate_freqency(int *freq, const char *data) {
  int i;
  for (i = 0; i < strlen(data); i++)
    freq[(int)data[i]]++;
}

int main(int argc, char **argv) {

  if(argc <= 2){
    printf("\n1) To compress a file run the program with the -c or --compress option, followed by \n   the input file path and the output file path.\n");
    printf("   Example: ./huffman -c inputFileName.txt outputFileName.txt\n\n");
    printf("2) To decompress a file, run the program with the -d or --decompress option, followed by \n   the input file path and the output file path.\n");
    printf("   Example: ./huffman -d inputFileName.txt outputFileName.txt\n\n");
    printf("\nNote: Put the files with exe file\n");
    exit(0);
  }
  
  if(strcmp(argv[1],"-c") == 0 || strcmp(argv[1],"--compress") == 0){
    char *data = read_from_file(argv[2]);

    int freq[ASCII_SIZE] = {0};
    calculate_freqency(freq, data);

    huffman_node *root = build_huffman_tree(freq);

    char code[MAX_BITS] = "";
    character *charNodes[ASCII_SIZE];
    memset(charNodes, 0, sizeof(charNodes));

    create_char_code(root, charNodes, code);

    char *data_code = Create_message_code(data, charNodes);
    write_data(argv[3], data_code, nodes_number+charachter_number, root);

    // data_code allocated dynamicly in the function Create_message_code()
    free(data_code);

    // free the huffman tree
    freeTree(root);

    // free the array of characters
    freeChars(charNodes);
  }
  else if(strcmp(argv[1],"-d") == 0 || strcmp(argv[1],"--decompress") == 0){
    int nodes_num = read_nodes_number(argv[2]);

    huffman_node *treeNodes[nodes_num];
    read_tree(argv[2], nodes_num, treeNodes);
    char *code = read_code(argv[2]);

    int current_node = 0;
    huffman_node *root = rebuild_huffman_tree(treeNodes, &current_node);

    char *data = decode_data(code,root);

    write_decoded_data(argv[3], data);

    freeTree1(treeNodes);
  }
  printf("done\n");
  return 0;
}