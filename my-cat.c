#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1000

int main (int argc, char *argv[]) {
    
    if(argc < 1){
        printf("Too few arguments given\n");
        exit(1);
    }
    
    for(int i=1; i<=argc; i++){
    
        FILE *fp = fopen(argv[i], "r");
        
        if (fp == NULL) {
            printf("my-cat: cannot open file\n");
            exit(1);
        }
        
        char buff[BUFSIZE];
        
        printf("%s\n", fp);
        while(fgets(buff, BUFSIZE-1, fp)!=NULL){
            printf("%s", buff);
        }
        
        fclose(fp);
    }
    
    return 0;
}
