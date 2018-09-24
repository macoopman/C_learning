// program reverse a give integer
#include <stdio.h>

int reverse(int n);

int main(void){
    int userInput;

    puts("\n\n---- Reverse Integer ----\n\n");
    printf("Enter Integer:");
    scanf("%d", &userInput);

    printf("\n\t%d reversed --> %d\n\n", userInput, reverse(userInput) );



}



int reverse(int n){

    int result = 0;

    while(n > 0){
        result += (n % 10);
        n /= 10;
        if(n != 0){
            result *= 10;
        }

    }

    return result;
}
