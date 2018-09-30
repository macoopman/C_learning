// Program uses a 50x50 grid to draw
// Commands:
    // 1 - Pin up
    // 2 - pen down
    // 3 - turn right
    // 4 - turn left
    // 5,X - move forward X spaces
    // 6 - print screen
    // 7 - show commands
    // 9 - end of data (sentinel)


    #include <stdio.h>
    #define GRID_HEIGHT 50
    #define GRID_WIDTH 50

    char commandSelection();
    void printOptions();
    void printGrid(int grid[][GRID_WIDTH], int height, int width);
    void setPin(int grid[GRID_HEIGHT][GRID_WIDTH], int x, int y, int pen);
    void moveForward(int grid[GRID_HEIGHT][GRID_WIDTH], int spaces, int direction, int* x, int* y);
    void turnRight(int *direction);
    void turnLeft(int *direction);

    int main(void){

        int grid[GRID_HEIGHT][GRID_WIDTH] = {0};
        int position_X = 0;
        int position_Y = 0;
        int direction = 3;   //left = 1, up = 2, right = 3, down = 4
        int pinIsUp = 0;
        char selection;



        //Inital Display
        puts("\n\n--- Turtle Commands ---\n\n");
        printGrid(grid, GRID_HEIGHT, GRID_WIDTH);
        puts("");
        printOptions();
        selection = commandSelection();

        // todo: functionality of moving and updating values
        // todo: I would like a unique character to represent the current location. Maybe the character
        //       represents the current direction i.e. "R" -> right
        do{
            int moves = 0;
            switch (selection) {
                case '1':
                    setPin(grid, position_X, position_Y, pinIsUp);
                    printf("%d\n", grid[position_X][position_Y]);
                    break;
                case '2':
                    setPin(grid, position_X, position_Y, pinIsUp);
                    break;

                case '3':
                    turnRight(&direction);
                    break;

                case '4':
                    turnLeft(&direction);
                    break;

                case '5':
                    scanf(" %d", &moves);
                    moveForward(grid, moves, direction, &position_X, &position_Y);
                    break;

                case '6':
                    printGrid(grid, GRID_HEIGHT, GRID_WIDTH);
                    break;

                case '7':
                    printOptions();
                    break;

                default:
                    puts("Unknown command");
                    break;
            }
            printf("%s", "Enter: ");
            selection = commandSelection();
            puts("");
        } while(selection != '9');



    }


    // Display and Input
    char commandSelection(){
        int validInput(char array[], int size, char input);
        char userInput;
        char valid[8] = {'1', '2', '3', '4', '5', '6', '7', '9'};
        int isValid;

            scanf(" %c", &userInput);
            isValid = validInput(valid, 8, userInput);
            while(isValid != 1) {
                printf("%s","Invalid - Enter: ");
                scanf("%c", &userInput);
                isValid = validInput(valid, 7, userInput);
            }
        return userInput;
    }

    void printOptions(){
        printf("%-10s\t%-10s\t%-30s%-15s\n", "1) Pen Up",   "3) Turn Right", "5 X) Move Forward \"X\" Spaces","7) Show Commands");
        printf("%-10s\t%-10s\t%--30s%-10s\n", "2) Pen Down", "4) Turn Left",  "6) Print Screen", "9) Quit");
        printf("%s", "Enter: ");
    }

    int validInput(char array[], int size, char input){
        for(int i = 0; i < size; ++i){
            if(input == array[i]){
                return 1;
            }
        }
        return 0;
    }




    // Drawing Functions

    //todo: boundry check needed
    //todo: add parameter to check if pin is down. if up then we are just moving position
    void moveForward(int grid[GRID_HEIGHT][GRID_WIDTH], int spaces, int direction, int* x, int* y){
        int i;
        switch(direction){
            case 1: // Left
                for(i = 0; i < spaces; ++i){
                    grid[*x][*y - i] = 1;
                }
                (*y) -= i;
                break;
            case 2: // Up
                for(i = 0; i < spaces; ++i){
                    grid[(*x) - i][*y] = 1;
                }
                (*x) += i;
                break;
            case 3: // Right
                for(i = 0; i < spaces; ++i){
                    grid[*x][(*y) + i] = 1;
                }
                (*y) += i;
                break;
            case 4: // Down
                for(i = 0; i < spaces; ++i){
                    grid[(*x) + i][*y] = 1;
                }
                (*x) += i;
                break;
            default:
                puts("ERROR: Invalid Direction");


        }

    }

    void setPin(int grid[GRID_HEIGHT][GRID_WIDTH], int x, int y, int pin){
        if(pin == 1){
            grid[y][x] = 0;
        } else {
            grid[y][x] = 1;
        }
    }

    void printGrid(int grid[][GRID_WIDTH], int height, int width){
            for(int i = 0; i < width; ++i){
                for(int j = 0; j < height; ++j){
                    printf("%2d", grid[i][j]);
                }
                puts("");
            }
    }

    void turnRight(int *direction){
        if(*direction != 4){
            ++(*direction);
        } else {
            *direction = 1;
        }
    }
    void turnLeft(int *direction){
        if(*direction != 1){
            --(*direction);
        } else {
            *(direction) = 4;
        }
    }
