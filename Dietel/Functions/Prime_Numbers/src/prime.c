//Programs prints all prime numbers in a given range
#include <stdio.h>

int isPrime(int n);
void printPrime(int max);



int main(void){
    
    printPrime(1000);


} // end main

void printPrime(int max ){
    size_t i;
    size_t printCount = 0;
    int isPrint = 1; // adds extra check for the display to insure we only print one line at a time.

    for(i = 1; i <= max; ++i){
        if(isPrime(i)){
            printf("%5d ", i);
            ++printCount;
            isPrint = 1;
        }

        if(printCount % 20 == 0 && isPrint == 1){
            puts("\n");
            isPrint = 0;
        }
    }
    puts("");
}




int isPrime(int n){
        int isPrime = 1;
        // check every number from 2 to n/2 to see if any number goes into it
        // evenly. If so its not prime and the loop breaks
        for(int j = 2; j < n/2; ++j){
            if(n % j == 0){
                isPrime = 0;
                break;
            }
        }
        if(isPrime == 1){
            return 1;
        }
    return 0;

}
