// Airline Reservation System(Basic)


#include <stdio.h>
#define MAX_SEATS 10 // 10 seat used. Not using seat 0

int checkAvailable(int seats[], int size, int request);
void printReservation(char classes[][15], int seat, int class);
char readChar(char validInputs[], int numInputs);

int main(void){

    int seats[MAX_SEATS] = {0};
    char class[3][15] = {"", "First Class", "Economy"};
    int seatCount = 0;
    int userInput;


    puts("\n---- Airline Reservation System ----\n");
    do{
        puts("Choose Class:");
        puts("1) First Class");
        puts("2) Economy");
        puts("3) Exit");
        printf("%s","Enter: " );
        scanf("%d", &userInput);

        // inital seat check
        int seatCheck;
        seatCheck = checkAvailable(seats, MAX_SEATS, userInput);

        // if seat is avaliable - book it and print reservation
        if(seatCheck != 0){
            seats[seatCheck] = 1;
            ++seatCount;
            printReservation(class, seatCheck, userInput);
        }
        else{ //check for other seat or notify of full plane
            // Econ is full
            if(userInput == 2){
                puts("Sorry Flight is full. Next flight leaves in 3 hours.\n");
            }
            // first class is full. check econ. if available offer econ else notify of later flight
            if(userInput == 1){
                int checkEcon = checkAvailable(seats, MAX_SEATS, 2);
                if(checkEcon != 0){
                    puts("First Class is full. Would you like a Economy seat? ");
                    char validCharacter[4] = {'Y','y','n','N'};
                    char c = readChar(validCharacter, 4);
                    if(c == 'y' || c == 'Y'){
                        seats[checkEcon] = 1;
                        ++seatCount;
                        printReservation(class, checkEcon, 2);
                    }
                    else {
                        puts("Next flight leaves in 3 hours.\n");
                    }
                }
                else{
                    puts("Sorry Flight is full. Next flight leaves in 3 hours.\n");
                    userInput = 3;
                }
            }
        }

    } while(userInput != 3);

    if(seatCount == MAX_SEATS){
        puts("Plane is FULL\n");
    }

} // end main


// if available returns valid seat number, else returns 0
int checkAvailable(int seats[], int size, int request){
    // first class = 1 to 5
    if(request == 1){
        for(int i = 1; i <= MAX_SEATS/2; ++i){
            if(seats[i] == 0){
                return i;
            }
        }
    }
    else { // econ = 6 to 10
        for(int i = 6; i <= MAX_SEATS; ++i){
            if(seats[i] == 0){
                return i;
            }
        }
    }
    return 0;
}


// prints reservations
void printReservation(char classes[][15], int seat, int class){
    puts("\n\tReservation Confirmed");
    printf("\tClass: %s\n", classes[class]);
    printf("\tSeat: %d\n", seat);
    puts("");
}



// check user input against an array of valid characters
char readChar(char validInputs[], int numInputs){
    char input;
    scanf(" %c", &input);

    int isValid = 0;
    while(isValid != 1){
        for(int i = 0; i < numInputs; ++i){
            if(input == validInputs[i]){
                return input;
            }
        }
        if(isValid == 0) {
            printf("%s","Invalid Input. Enter: ");
            scanf(" %c", &input);
        }
    }

    return input;
}
