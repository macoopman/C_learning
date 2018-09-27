



#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SALESPERSON 4
#define PRODUCTS 5

void printSales(double a[][SALESPERSON], int size);
void createSlip(double a[][SALESPERSON], int employee_number, int product_number, int value);
void autoDataFill(double a[PRODUCTS][SALESPERSON], int min, int max, int perDay, int days);
double salesTotal(double a[][SALESPERSON], int person);



int main(void){
    srand(time(NULL));

    double sales[PRODUCTS][SALESPERSON] = {0};

    autoDataFill(sales, 1, 100, 5, 30);

    printSales(sales, PRODUCTS);

    puts("\n\n\n");


    printf("%.2f\n", salesTotal(sales, 1));



}


void createSlip(double a[][SALESPERSON], int employee_number, int product_number, int value){
    a[employee_number - 1][product_number - 1] += value;
}

double salesTotal(double a[][SALESPERSON], int person){
    double total = 0;
    for(int i = 0; i < PRODUCTS; ++i){
        total += a[i][person - 1];
    }
    return total;
}


void printSales(double a[][SALESPERSON], int size){
    printf("%21s%9s%9s%9s\n\n", "Person 1", "Person 2","Person 3","Person 4");
    for(int i = 0; i < size ; ++i){
        printf("Product %d:   ", i +1);
        for(int j = 0; j < SALESPERSON; ++j){

            printf("%4.2f  ", a[i][j]);
        }
        puts("");
    }
    puts("");
}

void autoDataFill(double a[PRODUCTS][SALESPERSON], int min, int max, int perDay, int days){

    for(int d = 0; d < days; ++d){
        for(int pDay = 0; pDay < perDay; ++pDay){
            for(int i = 0; i < PRODUCTS ; ++i){
                for(int j = 0; j < SALESPERSON; ++j){
                    a[i][j] += (double)(rand() % max + min);
                }
            }
        }
    }



}
