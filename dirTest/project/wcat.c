#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    //printf("arc: %d\n",argc);

    if(argc <= 1){
        exit(EXIT_SUCCESS);
    }

    FILE *inFile = NULL;
    char buffer[256];
    char *status =  NULL;


    for(int i = 1 ; i < argc; i++){

        inFile = fopen(argv[i],"r");
        if (inFile == NULL){
            printf("wcat: cannot open file");
            printf("\n");
            exit(EXIT_FAILURE);
        }
        do{
            status = fgets(buffer, sizeof(buffer),inFile);
            if(status != NULL){
                printf("%s",buffer);
            }
        }while (status !=NULL);

        fclose(inFile);
    }
    
    exit(EXIT_SUCCESS);
}