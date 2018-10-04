#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]);

int main(void){

    //initalize suit array
    const char* suit[4] = {"Heart", "Diamonds", "Clubs", "Spades"};

    //initalize face array
    const char* face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    // initalize deck array
    int deck[4][13] = {0};
    srand(time(0));

    shuffle(deck);
    deal(deck, face, suit);

} // end main


void shuffle(int wDeck[][13]){
    int row;
    int column;
    int card;

    // for each of the 52 cards, choos slot of deck randomly
    for(card = 1; card <= 52; ++card){
        // choose new random location until unoccupied slot found
        do{
            row = rand() % 4;
            column = rand() % 13;
        } while(wDeck[row][column] != 0);

        // place card number in chosen slot of deck
        wDeck[row][column] = card;
    } // end for
} // end shuffle()

// deals cards in deck
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]){
    int row;
    int column;
    int card;

    // deal each of the 52 cards
    for(card = 1; card <= 52; ++card){
        // loop throught rows of wDeck
        for(row = 0; row <= 3; ++row){
            // loop thourght columns of wDeck for current row
            for(column = 0; column <= 12; ++column){
                // if slot contains current card, display card
                if(wDeck[row][column] == card){
                    printf("%5s of %-8s%c", wFace[column], wSuit[row],
                        card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}
