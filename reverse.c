#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1000

void main(int argc, char *argv[]){
        FILE * input = fopen("input.txt","r");
        FILE * output = fopen("output.txt", "w");

        if (input == NULL){
                printf("Could not open file\n");
                exit(-1);
        }

        char buff[BUFSIZE];
        
        

        while(fgets(buff, BUFSIZE - 1, input) != NULL){
                printf("%s",buff);
        }

        readfileinreverse(input,output);


        fclose(input);
        fclose(output);

}
//FROM https://stackoverflow.com/questions/6922829/read-file-backwards-last-line-first
void readfileinreverse(FILE *fp, FILE *out)
{
    int i, size, start, loop, counter;
    char *buffer;
    char line[BUFSIZE];
    start = 0;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    buffer = malloc((size+1) * sizeof(char));
    
    if(buffer==NULL){
            printf("Memory not allocated.\n");
            exit(1);
    }

    for (i=0; i< size; i++)
    {
        fseek(fp, size-1-i, SEEK_SET);
        buffer[i] = fgetc(fp);

        if(buffer[i] == 10)
        {
           if(i != 0)
           {
            counter = 0;
            for(loop = i; loop > start; loop--)
            {
                if((counter == 0) && (buffer[loop] == 10))
                {
                    continue;
                }
                line[counter] = buffer[loop];
                counter++;
            }
            line[counter] = 0;
            start = i;
            printf("%s\n",line);
            fprintf(out, "%s\n", line); 
            }
        }
    }

    if(i > start)
    {
        counter = 0;
        for(loop = i; loop > start; loop--)
        {
            if((counter == 0) && ((buffer[loop] == 10) || (buffer[loop] == 0)))
            {
                continue;
            }
            line[counter] = buffer[loop];
            counter++;
        }
        line[counter] = 0;
        printf("%s\n",line);
        fprintf(out, "%s\n", line);
        
        free(buffer);

        return;
    }
}
