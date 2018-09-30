// Program uses a 50x50 grid to draw
// Commands:
    // 1 - Pin up
    // 2 - pen down
    // 3 - turn right
    // 4 - turn left
    // 5,X - move forward X spaces
    // 6 - print screen
    // 9 - end of data (sentinel)


    #include <stdio.h>
    #define GRID_HEIGHT 50
    #define GRID_WIDTH 50

    char commandSelection();
    void printOptions();
    void printGrid(int grid[][GRID_WIDTH], int height, int width);
    void setPin(int grid[GRID_HEIGHT][GRID_WIDTH], int x, int y, int pen);

    int main(void){

        int grid[GRID_HEIGHT][GRID_WIDTH] = {0};
        int position_X = 0;
        int position_Y = 0;
        int pinIsUp = 0;
        char selection;


        //Inital Display
        puts("\n\n--- Turtle Commands ---\n\n");
        printGrid(grid, GRID_HEIGHT, GRID_WIDTH);
        puts("");
        printOptions();
        selection = commandSelection();


        // todo: functionality of moving and updating values
        do{
            switch (selection) {
                case '1':
                    setPin(grid, position_X, position_Y, pinIsUp);
                    printf("%d\n", grid[position_X][position_Y]);
                    break;
                case '2':
                    setPin(grid, position_X, position_Y, pinIsUp);
                    break;

                case '6':
                    printGrid(grid, GRID_HEIGHT, GRID_WIDTH);
                    break;

                default:
                    puts("Unknow command");
            }
            printf("%s", "Enter: ");
            selection = commandSelection();

        } while(selection != '9');



    }

    // todo: figure out rotating and general direction. then moving forward should be easy
    // error check for bounds

    char commandSelection(){
        int validInput(char array[], int size, char input);
        char userInput;
        char valid[7] = {'1', '2', '3', '4', '5', '6', '9'};
        int isValid;


            scanf(" %c", &userInput);
            isValid = validInput(valid, 7, userInput);
            while(isValid != 1) {
                printf("%s","Invalid - Enter: ");
                scanf("%c", &userInput);
                isValid = validInput(valid, 7, userInput);
            }

        return userInput;
    }


    void printGrid(int grid[][GRID_WIDTH], int height, int width){
            for(int i = 0; i < width; ++i){
                for(int j = 0; j < height; ++j){
                    printf("%2d", grid[i][j]);
                }
                puts("");
            }
    }

    void setPin(int grid[GRID_HEIGHT][GRID_WIDTH], int x, int y, int pin){
        if(pin == 1){
            grid[y][x] = 0;
        } else {
            grid[y][x] = 1;
        }
    }



    void printOptions(){
        printf("%-10s\t%-10s\t%-30s%-10s\n", "1) Pen Up", "3) Turn Left", "5,X) Move Forward \"X\" Spaces","9) Quit");
        printf("%-10s\t%-10s\t%--30s\n", "2) Pen Down", "4) Turn Right", "6) Print Screen");
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
