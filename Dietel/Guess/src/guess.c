#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXGUESS 1000


int main(void){

    srand(time(NULL));

    int guessCount = 1;
    int guess = -1;
    int random = (rand() % MAXGUESS + 1 );


    puts("\n\nI have a number b/t 1 and 1000");
    puts("Can you guess my number?");


    do{
        printf("Enter guess number %d: ", guessCount);
        scanf("%d", &guess);
        if(guess == random){
            puts("Excellent! You guessed the number!");
        }
        else if(guess > random){
            puts("Too High. Try again");
            ++guessCount;
        } else {
            puts("Too Low. Try again");
            ++guessCount;
        }
    } while(guess != random);
    





}
