// recursive print function


#include <stdio.h>
#define SIZE 10

void print(int a[], int size){
    if(size != 0){
        print(a, size - 1);
        printf("%d ", a[size-1]);
    }
}

int main(void){
    int a[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    print(a,SIZE);
    puts("");

}
