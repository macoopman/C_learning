// Calculates the length of the hypotenuse of a right triangle
// Inputs: Side A and B
#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b){
    return sqrt(pow(a,2) + pow(b,2));
}



int main(void){

    double a;
    double b;
    char n;

    puts("\n-----------------------------------\n");
    puts("\tHypotenuse Calculator\n\n");

    do{

        printf("%s","Enter A leg: ");
        scanf("%lf", &a);

        printf("%s","Enter B leg: ");
        scanf("%lf", &b);
        fflush(stdin);

        printf("Solution:\n\tHypotenuse = %.1f\n", hypotenuse(a,b));


        printf("%s", "Another Calculation (y/n): ");
        scanf(" %c", &n);

        while( (n != 'n') && (n != 'N') && (n != 'y') && (n != 'Y')){
            puts("Whoop I dont know that one.. try again");
            printf("%s", "Another Calculation (y/n): ");
            scanf(" %c", &n);
        }

    }while( n == 'y' || n == 'Y');
    puts("EXIT");
}
