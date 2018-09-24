// Program performs the power function recursivally


#include <stdio.h>

int power(int base, int exponent);

int main(void){

    printf("%d\n", power(5,8));

}

int power(int base, int exponent){
    if(exponent == 1){
        return base;
    }
    return base * power(base, exponent -1 );
}
