#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    if(argc == 1){
        printf("my-zip: file1 [file2...]\n");
        exit(1);
    }
    
    FILE *fp = fopen(argc[1], "r");
    FILE *fpz = fopen(argc[2], "w");
    
    if (fp == NULL){
                printf("Could not open file\n");
                exit(-1);
        }
    
    
    return 0;
}
