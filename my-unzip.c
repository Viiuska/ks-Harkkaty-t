#include <stdio.h>
#include <stdlib.h>

void decompressfile(char *filename) {
    char curr = 0;
    int count = 0;
    
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("[%s] file does not exist.", filename);
        exit(1);
    }
    while(1) {
        int bytes = fread(&count, 1, 4, fp);
        if(bytes != 4) {
            break;
        }
       fread(&curr, 1, 1, fp);{
       for(int i = 0; i < count; i++) {
            fwrite(&curr, 1, 1, stdout);
            }
        }

    fclose(fp);
}

int main(int argc, char **argv) {
    int i = 0;
    
    if(argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n"); exit(1);
        }
    
    for(i = 1; i < argc; i++) {
        decompressfile(argv[i]);
        }
    return 0;
}
