// Program performs the power function recursivally


#include <stdio.h>

int RecursivePower(int base, int exponent);

int main(void){

    int base = 0;
    int power = 0;

    puts("\n\n---- Power Function ----\n");
    puts("Input the base followed by the power. Seperated by space.");
    printf("%s","Enter (base power):  ");
    scanf("%d", &base);
    scanf("%d", &power);
    printf("%d^%d = %d\n\n\n\n", base, power, RecursivePower(base,power));

}

int RecursivePower(int base, int exponent){
    if(exponent == 1){
        return base;
    }
    return base * RecursivePower(base, exponent -1 );
}
