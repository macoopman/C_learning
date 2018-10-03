// Program simulates the rolling of a pair of dice 36,000 times and displays the
// freq results and the percentage

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_ROLLS 36000
#define ARRAY_SIZE 13

int rollDice();

int main(void){
    srand(time(NULL));
    int freq[13] = {0};

    // Rolls dice 36,000 times and increments the freq array for each roll
    for(int i = 0; i <= MAX_ROLLS; ++i){
        freq[rollDice()]++;
    }

    printf("%10s%10s  %10s\n", "FACE", "FREQ", "PERCENT");
    for(int i = 1 ; i < ARRAY_SIZE; ++i){
        printf("%10d%10d%10.2f %%\n", i, freq[i], ((float)freq[i]/MAX_ROLLS) * 100);
    }
} // end main


int rollDice(){
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}
