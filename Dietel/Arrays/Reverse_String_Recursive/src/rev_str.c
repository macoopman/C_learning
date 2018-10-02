// Uses Recursion to print the reverse of a  string


#include <stdio.h>
#include <string.h>

void revStr(char* str){
    if(*str == '\0'){
        return;
    }
    else{
        revStr(str + 1);
    }
    printf("%c", str[0]);

}

int main(void){

    char* string = "Reverse Me";
    printf("Original: %s\n", string);


    revStr(string);

}
