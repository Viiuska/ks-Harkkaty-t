#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    if(argc == 1){
        printf("my-grep: searchterm [file...]\n");
        exit(1);
    }
    
    for(int i=2; i<argc; i++){
        FILE *fp = fopen(argv[i], "r");
            
        if (fp == NULL) {
            printf("my-cat: cannot open file\n");
            exit(1);
        }
        
        char *contents = NULL;
        size_t len = 0;
        
        while(getline(&contents, &len, fp)!=-1){
            if(strstr(contents , argv[1]) != NULL){
                printf("%s", contents);
            }
        }
            
        fclose(fp);
        free(contents);
    }
    return 0;
}
