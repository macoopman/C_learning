



#include <stdio.h>
#define SALES_PERSON 4
#define PRODUCTS 5

void printSales(double a[][PRODUCTS], int size);


int main(void){

    double sales[SALES_PERSON][PRODUCTS] = {0};

    printSales(sales, SALES_PERSON);
}


void printSales(double a[][PRODUCTS], int size){
    for(int i = 0; i < size ; ++i){
        for(int j = 0; j < PRODUCTS; ++j){
            printf("%4.2f  ", a[i][j]);
        }
        puts("");
    }
}
