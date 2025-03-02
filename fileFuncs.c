#include <stdio.h>
#include "./headers/fileFuncs.h"

void replaceWithSpace(FILE* file){
    char out, space = ' ';
    fseek(file, -1, SEEK_CUR);
    while(1){
        fread(&out, sizeof(char), 1, file);
        if (out==' '||out=='\n'){
            break;
        }
        else{
            fseek(file, -1, SEEK_CUR);
            fwrite(&space, sizeof(char), 1, file);
            fflush(file);
        }
    }
    fseek(file, -1, SEEK_CUR);
}

void fileReading(FILE* file, char* filename){
    char out='0';
    printf("\nFile content:\n\n");
    freopen(filename, "r", file);
    while(out!='\n'){
        fread(&out, sizeof(char), 1, file);
        printf("%c", out);
    }
}