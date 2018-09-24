//Program takes in a pair of integers and detemines
//if the second integer is a multiple of the first
#include <stdio.h>

int multiple(int a, int b);


int main(void){

    int a;
    int b;
    char userInput;

    puts("\n\n----Multiples----\n\n");
    puts("Determine Multiples:");
    puts("\tEnter integer for a and b: Is B a multiple of A");
    

    do{
        printf("%s", "Enter A: ");
        scanf("%d", &a);

        printf("%s", "Enter B: ");
        scanf("%d", &b);

        printf("%d is%s a multiple of %d\n\n", b, (multiple(a,b)) ? "" : " NOT" , a );

        printf("%s","Calculate Again (y/n): ");
        scanf(" %c", &userInput);

        while(userInput != 'y' && userInput != 'Y' &&
                userInput != 'n' && userInput != 'N'){
                    puts("\nInvalid Selection:");
                    printf("%s","\nCalculate Again (y/n): ");
                    scanf(" %c", &userInput);
                }

    } while(userInput == 'y' || userInput == 'Y');

}


// Determines if b is a multiple of a
// Returns 1 if true, 0 if false
int multiple(int a, int b){
    return (b % a == 0) ? 1 : 0;
}
