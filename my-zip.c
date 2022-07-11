#include <stdio.h>
#include <stdlib.h>

void compressfile(char *filename) {
    FILE *fp = fopen(filename, "rb");
    char prev = 0, 
    char curr = 0;
    int count = 0;
    
    if(fp == NULL){
        printf("[%s] file does not exist.\n", filename);
        exit(1);
    }
    while(1){
        curr = fgetc(fp);
        if(curr == EOF){
            if(count > 0) {
            //writes first the character and then number
            fwrite(&count, 1, 4, stdout);
            fwrite(&prev, 1, 1, stdout);
        }
            break;
        }
        if(curr != prev) {
                //writes first the character and then number
                if(count > 0) {
                    fwrite(&count, 1, 4, stdout);
                    fwrite(&prev, 1, 1, stdout);
                }
                count = 0;
        }
        count++;
        prev = curr;
    }
    fclose(fp);

}

int main(int argc, char **argv) {
    int i = 0;
    if(argc < 2) {
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
    }
    for(i = 1; i < argc; i++) {
            compressfile(argv[i]);
    }
    return 0;
}
