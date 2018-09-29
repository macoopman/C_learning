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

    char commandsDisplay();
    void printOptions();
    void printGrid(int grid[][GRID_WIDTH], int height, int width);

    int main(void){

        int grid[GRID_HEIGHT][GRID_WIDTH] = {0};
        int position_X = 0;
        int position_Y = 0;


        //Inital Display
        puts("\n\n--- Turtle Commands ---\n\n");
        printGrid(grid, GRID_HEIGHT, GRID_WIDTH);
        puts("");
        commandsDisplay();

        // todo: functionality of moving and updating values
    }

    char commandsDisplay(){
        int validInput(char array[], int size, char input);
        char userInput;
        char valid[7] = {'1', '2', '3', '4', '5', '6', '9'};

        do{
            printOptions();
            scanf("%c", &userInput);
            while(!validInput(valid, 7, userInput )){
                printf("Invalid - Enter: ");
                scanf(" %c", &userInput);
            }

        } while(0);
    }


    void printGrid(int grid[][GRID_WIDTH], int height, int width){
            for(int i = 0; i < width; ++i){
                for(int j = 0; j < height; ++j){
                    printf("%2d", grid[i][j]);
                }
                puts("");
            }
    }

    void printOptions(){
        printf("%-10s\t%-10s\t%-30s\n", "1) Pen Up", "3) Turn Left", "5,X) Move Forward \"X\" Spaces");
        printf("%-10s\t%-10s\t%--30s\n", "2) Pen Down", "4) Turn Right", "9) Quit");
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
