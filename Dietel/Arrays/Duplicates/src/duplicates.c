// Program reads in 20 numbers (10 - 100). As each number is read, print it only
// if it is not a duplicateof a number alread read.
// Provide for the "worst case" in which all 20 numbers are different.
// Use the smallest possible array to solve this problem


#include <stdio.h>
#define SIZE 20

int valid(int a[], int size, int input);
void printArray(int a[], int size);

int main(void){

    int inputArray[SIZE] = {0};
    int inputArrayCount = 0;
    int inputCount = 0;
    int userInput = 0;
    char c;

    puts("\n\n");

    do{
        printf("Enter Number (b/t 10 - 100): ");
        scanf("%d", &userInput);



        if(userInput >= 10 && userInput <= 100){
            ++inputCount;
            if(valid(inputArray, SIZE, userInput)){
                inputArray[inputArrayCount] = userInput;
                ++inputArrayCount;
            }
        } else {
            puts("Invalid Entry: Must be b/t in range 10-100");
        }


    } while(inputCount <= SIZE);

    puts("\nUnique Integers: ");
    printArray(inputArray, inputArrayCount);


}

int valid(int a[], int size, int input){
    int isValid = 1;
    for(int i = 0; i < size; ++i){
        if(a[i] == input){
            isValid = 0;
        }
    }
    return isValid;
}

void printArray(int a[], int size){
    for(int i = 0; i < size; ++i){
        printf("%5d", a[i]);
        }
    puts("");
}
