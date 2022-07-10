#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void execArgs(char** parsed)
{
    // Forking a child
    pid_t pid = fork();

    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
}

//Versio 2
//From https://www.geeksforgeeks.org/making-linux-shell-c/
/*void execArgs(char** parsed)
{
    // Forking a child
    pid_t pid = fork();
    char *args[3];
    args[0] = paths;
    args[1]  =  parsed[0];
    args[2] = NULL;

    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execv(paths, args) < 0) {
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL);
        return;
    }
}*/
int string_break(char * line, char * tokens[])
{
  int i = 0;
  const char delimiter = ' ';
  // Remove the trailing '\n', if any
  strtok(line, "\n");
  while(1)
    {
      // Break the user input into tokens using a fixed delimiter
      tokens[i] = strsep(&line, &delimiter);
      if(tokens[i] == NULL)
        break;
      i++;
    }
  return i;
}

//Help from https://github.com/tanishqjasoria/wish/blob/master/wish.c
int main(int argc, char **argv){
        char * line = NULL;
        char* input[10];
        size_t linec = 0;

        if (argc == 1){

                while(1){
                        printf("wish> ");

                        linec = getline(&line, &linec, stdin);

                        int input_len = string_break(line, input);

                        if(strcmp(input[0], "exit") == 0){
                                exit(0);
                        }
                        if(strcmp(input[0], "cd") == 0){
                                printf("cd\n");
                        }if(strcmp(input[0], "path") == 0){
                                printf("path\n");
                        }
                        execArgs(input);

                }
        }
        if (argc == 2){
                printf("Read file\n");
        }
        if (argc > 2){
                printf("Too many arguments\nPromts are './wish' or './wish filename.txt'\n");
        }
        return 0;
}
