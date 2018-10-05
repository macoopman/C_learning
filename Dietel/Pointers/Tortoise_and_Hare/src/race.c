// Simulates a tortois and hare race


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TRACK_SIZE 70

int moveTortoise(int percentage , int* currentPosition);
int moveHare(int percentage, int* currentPosition);


void printTrack(const char track[], const int size);
void setTrack(char track[], const int size);
void race(char track[], int *tortoisPosition, int *harePosition, int end);



int main(void){
    srand(time(0));
    char track[TRACK_SIZE];
    int tortoisPosition = 1;
    int harePosition = 1;
    setTrack(track, TRACK_SIZE);

    puts("BANG !!!");
    puts("AND THEY'RE OFF !!!");
    race(track,&tortoisPosition, &harePosition, TRACK_SIZE);



}

void race(char track[],int *tortoisCurrent, int *hareCurrent, int end){
    int percentage = rand() % 10 + 1;
    int tortois = moveTortoise(percentage, tortoisCurrent);
    int hare = moveHare(percentage, hareCurrent);
    int roundCounter = 1;

    // loop while there is no winner
    while(tortois < end && hare < end){
        if(tortois == hare){        // if they are on the same space they collide
            track[hare] = '#';
            puts("OUCH!!!");
        } else {
            track[tortois] = 'T';
            track[hare] = 'H';
        }

        // print track update
        printf("%d: ", roundCounter++);
        printTrack(track, end);


        // reset track for next position
        track[tortois] = '_';
        track[hare] = '_';

        // get next move
        percentage = rand() % 10 + 1;
        tortois = moveTortoise(percentage, tortoisCurrent);
        hare = moveHare(percentage, hareCurrent);
    }

    // display the winner
    if(tortois >= end && hare >= end){
        puts("It's a tie.");
    }
    else if(tortois >= end){
        puts("TORTISE WINS!!! YAY!!!");
    }
    else if(hare >= end){
        puts("Hare Wins");
    }



} // end race()




int moveHare(int percentage, int* currentPosition){
    int hareNext;
    switch (percentage) {
        case 3:
        case 4:
            hareNext =  9;
            break;
        case 5:
            hareNext =  12;
            break;
        case 6:
        case 7:
        case 8:
            hareNext =  1;
            break;
        case 9:
        case 10:
            hareNext =  2;
            break;
        default:
            hareNext = 0;
    }

    if(hareNext % 2 != 0){ // move right
        *currentPosition += hareNext;
    } else { //move left
        if(*currentPosition - hareNext < 1){
            *currentPosition = 1;
        } else {
            *currentPosition -= hareNext;
        }
    }
    return *currentPosition;
}


int moveTortoise(int percentage, int* currentPosition){
    int tortoisNext;
    switch (percentage) {
        case 1:
        case 5:
            return 3;
            break;
        case 6:
        case 7:
            return 6;
            break;
        case 8:
        case 9:
        case 10:
            return 1;
            break;
        default:
            return 0;
    }

    if(tortoisNext % 2 != 0){ // move right
        *currentPosition += tortoisNext;
    } else { //move left
        if(*currentPosition - tortoisNext < 1){
            *currentPosition = 1;
        } else {
            *currentPosition -= tortoisNext;
        }
    }
    return *currentPosition;
}

void setTrack(char track[], const int size){
        for(int i = 0; i < size; ++i){
            track[i] = '_';
        }
        puts("");
}

void printTrack(const char track[], int size){
    for(int i = 0; i < size; ++i){
        printf("%c ", track[i]);
    }
    puts("");
}
