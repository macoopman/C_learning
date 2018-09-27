



#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SALESPERSON 4
#define PRODUCTS 5

void printSales(double a[][PRODUCTS], int size);
void createSlip(double a[][PRODUCTS], int employee_number, int product_number, int value);
void autoDataFill(double a[SALESPERSON][PRODUCTS], int min, int max);


int main(void){
    srand(time(NULL));

    double sales[SALESPERSON][PRODUCTS] = {0};

    autoDataFill(sales, 1, 100);

    printSales(sales, SALESPERSON);

    puts("\n\n\n");

    createSlip(sales, 1, 3,50.25);

    printSales(sales, SALESPERSON);





}


void createSlip(double a[][PRODUCTS], int employee_number, int product_number, int value){
    a[employee_number - 1][product_number - 1] += value;
}


void printSales(double a[][PRODUCTS], int size){
    for(int i = 0; i < size ; ++i){
        for(int j = 0; j < PRODUCTS; ++j){
            printf("%4.2f  ", a[i][j]);
        }
        puts("");
    }
}

void autoDataFill(double a[SALESPERSON][PRODUCTS], int min, int max){
    for(int i = 0; i < SALESPERSON ; ++i){
        for(int j = 0; j < PRODUCTS; ++j){
            a[i][j] = (double)(rand() % max + min);
        }
    }
}
