// Program reads in 20 numbers (10 - 100). As each number is read, print it only
// if it is not a duplicateof a number alread read.
// Provide for the "worst case" in which all 20 numbers are different.
// Use the smallest possible array to solve this problem


#include <stdio.h>
#define SIZE 5

int valid(int a[], int size, int input);
void printArray(int a[], int size);

int main(void){

    int inputArray[SIZE] = {0};
    int inputArrayCount = 0;
    int inputCount = 0;
    int userInput = 0;




    do{
        printf("\n\nEnter Number: ");
        scanf("%d", &userInput);
        ++inputCount;

        if(valid(inputArray, SIZE, userInput)){
            inputArray[inputArrayCount] = userInput;
            ++inputArrayCount;
        }
    } while(inputCount <= SIZE);

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
