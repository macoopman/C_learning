// Finds and prints all perfect numbers
// number is perfect when its factors (including 1) sum to the number

#include <stdio.h>
#include <math.h>
#define MAX_PRIME_GAP 500

// prints all perfect number within range and prints
void perfectNumbers(int end);

// returns the next prime number following n;
int nextPrime(int n);

// find print the factors of a number
void printFactors(unsigned int n);






int main(void){

    unsigned long userInput;
    puts("\n\n----Perfect Number Generator----\n\n");
    printf("Enter Max Range of Generator: ");
    scanf("%lu", &userInput);


    perfectNumbers(userInput);
    puts("\n\n\n");

}





void perfectNumbers(int end){
    unsigned int prime = nextPrime(1);
    unsigned long long int perfect_numbers = pow(2,prime-1) * (pow(2,prime)-1);
    while(perfect_numbers <= end){
        printf("%llu -> ", perfect_numbers);
        printFactors(perfect_numbers);
        prime = nextPrime(prime);
        perfect_numbers = pow(2,prime-1) * (pow(2,prime)-1);
    }
}

int nextPrime(int n){
    //loop from n+1 to 500. if the number is not found then its to big
    for(int i = n + 1; i < n + MAX_PRIME_GAP; ++i){
        int isPrime = 1;
        // check every number from 2 to n/2 to see if any number goes into it
        // evenly. If so its not prime and the loop breaks
        for(int j = 2; j < n/2; ++j){
            if(i % j == 0){
                isPrime = 0;
                break;
            }
        }
        if(isPrime == 1){
            return i;
        }
    }
    return -1;
}

void printFactors(unsigned int n){
    size_t i;
    printf("%d", 1);
    for(i = 2; i < n; ++i){
        if(n % i == 0){
            printf("+%d", i);
        }
    }
    printf(" = %d \n", n);
}
