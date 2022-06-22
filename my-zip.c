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
