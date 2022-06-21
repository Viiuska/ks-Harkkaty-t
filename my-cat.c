#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1000

int main (int argc, char *argv[]) {
    
    if(argc < 1){
        printf("Too few arguments given\n");
        exit(1);
    }
    
    //Tämä sitten for rakenteeseen jos käyttäjä 
    //haluaa lukea monta tiedotoa yhdellä kertaa
    
    FILE *fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
    printf("my-cat: cannot open file\n");
    exit(1);
    }
    char buff[BUFSIZE];
    
    while(fgets(buff, BUFSIZE-1, fp)!=NULL){
        printf("%s", buff);
    }
    
    fclose(fp);
    
    return 0;
}
