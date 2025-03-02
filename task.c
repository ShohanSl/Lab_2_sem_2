#include <stdio.h>
#include "./headers/task.h"
#include "./headers/inputFuncs.h"
#include "./headers/fileFuncs.h"

void task(char* filename){
    FILE* file = fopen(filename, "w");
    int isInputed = 0, wordLength, curLength = 0, lengthCount = 0;
    char inp, out, firstLetter;
    printf("\nEnter a string\n(Acceptable characters: A-Z, a-z, ' ')\n\n");
    while(1){
        inp = charInput();
        if (inp=='0'){
            freopen(filename, "w", file);
            while(getchar()!='\n');
        }
        else if (inp == '\n'&&isInputed==1){
            fwrite(&inp, sizeof(char), 1, file);
            break;
        }
        else if (inp == '\n'){
            printf("\n\nInput error. Please, try again\n\n");
            freopen(filename, "w", file);
        }
        else if (inp!=' '){
            fwrite(&inp, sizeof(char), 1, file);
            isInputed = 1;
        }
        else{
            fwrite(&inp, sizeof(char), 1, file);
        }
    }
    fileReading(file, filename);
    printf("\n\nEnter a length of word:\n\n");
    wordLength=intInputPos();
    out = '0';
    fseek(file, 0, SEEK_SET);
    while (out!='\n'){
        fread(&out, sizeof(char), 1, file);
        if ((out==' '||out=='\n')&&curLength==wordLength){
            curLength = 0;
            lengthCount++;
        }
        else if (out==' '){
            curLength = 0;
        }
        else {
            curLength++;
        }
    }
    printf("\nThe number of words with a length of %d characters: %d\n\n\
Enter the character that the word should start with:\n\n", wordLength, lengthCount);
    isInputed = 0;
    while(1) {
        inp=charInput();
        if (inp=='0'){
            while(getchar()!='\n');
        }
        else if (inp=='\n'&&isInputed==0){
            printf("\nInput error. Please, try again\n\n");
        }
        else if (inp==' '&&isInputed==0){
            printf("\nInput error. Please, try again\n\n");
            while(getchar()!='\n');
        }
        else if (inp=='\n'&&isInputed==1){
            break;
        }
        else if (isInputed==1){
            printf("\nInput error. Please, try again\n\n");
            while(getchar()!='\n');
            isInputed = 0;
        }
        else{
            firstLetter = inp;
            isInputed = 1;
        }
    }
    freopen(filename, "r+", file);
    fread(&out, sizeof(char), 1, file);
    if (out==firstLetter){
        replaceWithSpace(file);
    }
    while(out!='\n'){
        fread(&out, sizeof(char), 1, file);
        if (out==' '){
            fread(&out, sizeof(char), 1, file);
            if (out==firstLetter){
                replaceWithSpace(file);
            }
            else{
                fseek(file, -1, SEEK_CUR);
            }
        }
    }
    fileReading(file, filename);

    return;
}