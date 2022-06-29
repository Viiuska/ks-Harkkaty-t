#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 1000

int main (int argc, char *argv[]) {
    if(argc == 1){
        printf("my-zip: file1 [file2...]\n");
        exit(1);
    }
    
    FILE *fp = fopen(argv[1], "r");
    //FILE *fpz = fopen(argc[2], "w");
    
    if (fp == NULL){
                printf("Could not open file\n");
                exit(-1);
        }
    char buff[BUFSIZE];
    char current=buff[0];
    int count =1;
        printf("%s:\n", argv[1]);
        while(fgets(buff, BUFSIZE-1, fp)!=NULL){
            for(int i =1; buff[i] != '\0'; i++){
                if(buff[i] == current){
                    count++;
                }else{
                    printf("%c%d", current,count);
                    current = buff[i];
                    count=1;
                }
            }
            
        }
        
        fclose(fp);    
    return 0;
}




//versio 2

#include <stdio.h>
#include <stdlib.h>

void compress(char *path) {
    FILE *fp = fopen(path, "rb");
    char prev = 0, curr = 0;
    int count = 0;
    if(fp == NULL){
        printf("[%s] file does not exist, exiting program ..\n", path);
        exit(1);
    }
    while(1){
        curr = fgetc(fp);
        if(curr == EOF){
            if(count > 0) {
            fwrite(&count, 1, 4, stdout);
            fwrite(&prev, 1, 1, stdout);
        }
            break;
        }
        if(curr != prev) {
                /* * We got a new character, so first write the count of previous * character. */
                if(count > 0) {
                    fwrite(&count, 1, 4, stdout);
                    fwrite(&prev, 1, 1, stdout);
                }
                count = 0;
        }
        count++; prev = curr;
    }
    fclose(fp);

}

int main(int argc, char **argv) {
    int i = 0;
    if(argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    for(i = 1; i < argc; i++) {
            compress(argv[i]);
    }
    return 0;
}
