#include <stdio.h>
#include "./headers/inputFuncs.h"

char charInput(){
    char inp;
    inp=getchar();
    if ((inp>64&&inp<91)||(inp>96&&inp<123)||inp==32||inp=='\n'){
        return inp;
    }

    else{
        printf("\n\nInput error. Please, try again\n\n");
        return '0';
    }
}

int intInputPos(){
    int res = 0;
    char inp;
    while (1) {
        while (1) {
            inp = getchar();
            if (inp=='\n'&&res==0){
                printf("\nPlease, enter an integer:\n\n");
            }
            if (inp == '\n') {
                break;
            } else if (inp == 45 && res == 0) {
                printf("\nThis number must be grater than zero\n\n");
                res = 0;
                while (getchar() != '\n');
                break;
            } else if (inp < 48 || inp > 57) {
                printf("\nCharacters other than numbers are entered\nPlease enter an integer\n\n");
                res = 0;
                while (getchar() != '\n');
                break;
            } else if (inp == '0' && res == 0) {
                printf("\nThis number cannot be a zero\n\n");
                while (getchar() != '\n');
                break;
            } else {
                res = res * 10 + (inp - '0');
            }
        }
        if (res != 0) break;
    }
    return res;
}