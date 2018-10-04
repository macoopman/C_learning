// card shuffle program
// base code is from the book. I will be doing exercise to improve upon the base code


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

// Updated to deal a 5 card poker hand
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[]){
    void print(const int face[], const int suit[], const char *wFace[], const char *wSuit[]);
    int hasPair(const int suit[], int numPairs);
    int ofAKind(const int face[], int numOfKind);
    int isFlush(const int suit[]);
    int isStraight(const int face[]);

    int row;
    int column;
    int card;
    int face[5] = {0}; // Would be much better is cards were represented as a stuct
    int suit[5] = {0};

    // Select 5 cards
    for(card = 1; card <= 5; ++card){
        // loop throught rows of wDeck
        for(row = 0; row <= 3; ++row){
            // loop thourght columns of wDeck for current row
            for(column = 0; column <= 12; ++column){
                // if slot contains current card, display card
                if(wDeck[row][column] == card){
                    face[card - 1] = column;
                    suit[card - 1] = row;
                }
            }
        }
    }



    print(face, suit, wFace, wSuit);

    // Something is wrong with the hasPair and ofAKind function
    printf("\n\nHas Pair -> %d\n", hasPair(suit, 2));
    printf("Has 2 of Kind -> %d\n", ofAKind(face, 2));
    printf("Is Flush -> %d\n", isFlush(suit));
    printf("Is Straight -> %d\n", isStraight(face));

}

void print(const int face[], const int suit[], const char *wFace[], const char *wSuit[]){
    for(int i = 0; i < 5; ++i){
        printf("%5s of %-8s\n", wFace[face[i]], wSuit[suit[i]]);
    }
}

// Functions to determine combinations
// Parameter: array of face values and number of pairs to find;
// Return: true(1) if found the pairs
int hasPair(const int suit[], int numPairs){
    int pairs = 0;
    for(int i = 0; i < 5; ++i){
        for(int j = i + 1; j < 5; ++j){
            if(suit[i] == suit[j]){
                ++pairs;
            }
        }
    }
    if(pairs < numPairs){
        return 0;
    } else {
        return 1;
    }
}

// Parameter: array of suits values and number of pairs to kinds;
// Return: true(1) if found the corrent number of kinds
int ofAKind(const int face[], int numOfKind){
    int kind = 0;
    for(int i = 0; i < 5; ++i){
        for(int j = i + 1; j < 5; ++j){
            if(face[i] == face[j]){
                ++kind;
            }
        }
    }
    if(kind < numOfKind){
        return 0;
    } else {
        return 1;
    }
}

int isFlush(const int suit[]){
    int firstCard = suit[0];
    for(int i = 1; i < 5; ++i){
        if(firstCard != suit[i]){
            return 0;
        }
    }
    return 1;
}

int isStraight(const int face[]){
    int firstCard = face[0];
    for(int i = 1; i < 5; ++i){
        if(firstCard != face[i]){
            return 0;
        }
    }
    return 1;
}
