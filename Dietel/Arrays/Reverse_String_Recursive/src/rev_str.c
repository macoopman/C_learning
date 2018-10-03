// Uses Recursion to print the reverse of a  string


#include <stdio.h>
#include <string.h>

void revStr(char* str){
    // BASE CASE: NULL string just return
    if(*str == '\0'){
        return;
    }
    else{
        // recursivally removes the first character until the NULL is is hit.
        revStr(str++);
    }
    // coming out of the recursion all char's are printed in reverse
    printf("%c", str[0]);

}

int main(void){

    char* string = "Reverse Me";
    printf("Original: %s\n", string);


    revStr(string);
    puts("");

}
