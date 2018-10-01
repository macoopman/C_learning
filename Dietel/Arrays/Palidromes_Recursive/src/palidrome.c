// Recursive program to determine palidromes



#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

// man a plan a canal panama
// radar
// ignore space and punctuation
int isPalidrome(char* str, int beg, int end){

    while(!isalpha(str[beg]) || !isalpha(str[end])){

        if(!isalpha(str[beg])){
            beg++;
        }

        if(!isalpha(str[end])){
            end--;
        }
    }

    // base case: if equal then they are the same character
    if(beg == end){
        return 1;
    }

    if(str[beg] == str[end]){
        return isPalidrome(str, beg + 1, end -1);
    }
    else {
        return 0;
    }

}

int main(void){
    char userString[MAX];

    printf("\n\nEnter Word: ");
    fgets(userString, MAX, stdin);
    printf("%s\n", userString);

    printf("%d\n", isPalidrome(userString, 0, strlen(userString) -2));

    // char* chars = "a";
    // printf("a: %d\n", isalpha(chars[0]));
    // printf("period: %d\n", isalpha(chars[1]));
    // printf("#: %d\n", isalpha(chars[2]));

}
