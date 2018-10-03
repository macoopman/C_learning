// Recursive program to determine palidromes



#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100


int isPalidrome(char* str, int beg, int end);

int main(void){
    char userString[MAX];

    printf("\n\nEnter String: ");
    fgets(userString, MAX, stdin);

    userString[strcspn(userString, "\n")] = '\0';
    printf("%s -> %s a palidrome\n", userString, (isPalidrome(userString, 0, strlen(userString) - 1)) ? "Is" : "Is NOT");


}




int isPalidrome(char* str, int beg, int end){
    // Performs check for characters that are not alphanumeric
    // if not then increment/decerment until both are alpha
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

    // if equal then proceed to recursive call on the string
    if(str[beg] == str[end]){
        return isPalidrome(str, beg + 1, end -1);
    }
    else {
        return 0;
    }

}
