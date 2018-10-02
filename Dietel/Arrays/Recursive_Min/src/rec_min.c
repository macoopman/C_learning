// recursive implementation to find min element in array


#include <stdio.h>
#define SIZE 10

int recursiveMin(int a[], int size){
    if(size == 1){
        return a[size - 1];
    }
    int min = recursiveMin(a, size -1);
    if(a[size - 1] < min){
        return a[size-1];
    } else {
        return min;
    }

}

int main(void){
    int array[SIZE] = {100,4,5,21,50,5,64,34,43,23};

    puts("Array: ");
    for(int i = 0; i < SIZE; ++i){
        printf("%d ", array[i]);
    }
    puts("");

    printf("MIN ELEMENT = %d\n", recursiveMin(array, SIZE));


}
