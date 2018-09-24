// math practice program - provides problems for addition, subtraction,
// Multiplication, and Division

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_TERM 10

void playerScreen(int (*operation)(int a, int b), char op[20], int isDivision);
int addition_problem(int a, int b);
int subtraction_problem(int a, int b);
int multiplication_problem(int a, int b);
int division_problem(int a, int b);

//todo: refactor to pass a operations fuction into a generic exersice function
//        this should reduce the size of the program




int main(void){
    srand(time(NULL));

    char menuInput[5];


    do{
        puts("\n--- Math Practice --\n");
        puts("1) Addition");
        puts("2) Subtraction");
        puts("3) Multiplication");
        puts("4) Division");
        puts("5) Exit");

        printf("\n%s: ", "Selection: ");
        scanf("%c", menuInput);

        switch(*menuInput){
            case('1'):
                playerScreen(addition_problem, "Addition", 0);
                break;
            case('2'):
                playerScreen(subtraction_problem, "Subtraction", 0);
                break;
            case('3'):
                playerScreen(multiplication_problem, "Multiplication", 0);
                break;
            case('4'):
                playerScreen(division_problem, "Division", 1);
                break;
            case('5'):
                puts("Thanks for playing...\n\n");
                break;
            default:
                printf("Unknown selection : Try Again \n");

        }

    } while(*menuInput != '5');

}

void playerScreen(int (*operation)(int a, int b), char op[], int isDivision){
    unsigned int numberOfQuestions;
    unsigned int correct;
    unsigned int incorrect;
    unsigned int counter = 0;


    printf("\n%s Practice\n", op);

    // requst number of questions from user
    // give user questions
    do{
        printf("Enter Number of Practice Questions: ");
        scanf("%d", & numberOfQuestions);
        int result;

        while(counter < numberOfQuestions){
            if(isDivision){
                result = (*operation)(rand() % MAX_TERM, rand() % (MAX_TERM - 1) + 1);
            }
            else {
                result = (*operation)(rand() % MAX_TERM,rand() % MAX_TERM);
            }

            result == 1 ? ++correct : ++incorrect;
            ++counter;
        }

    } while(counter < numberOfQuestions);
    puts("\n\nResults:\n");
    printf("\tCorrect:   %d\n",correct);
    printf("\tIncorrect: %d\n",incorrect);


    //todo: pause so user can view results
}




int addition_problem(int a, int b){
    int solution = a + b;
    int userInput;
    int tries = 1;
    printf("%d + %d = ", a, b);
    scanf("%d", &userInput);

    if(solution == userInput){
        return 1;
    }

    while((tries < 3) && (userInput != solution) ){
        ++tries;
        puts("Incorrect: Try Again:");
        if(tries == 3) puts("Final Attempt");
        printf("%d + %d = ", a, b);
        scanf("%d", &userInput);

        if(solution == userInput){
            return 1;
        }
    }
    return 0;
}


int subtraction_problem(int a, int b){
    int solution = a - b;
    int userInput;
    int tries = 1;
    printf("%d - %d = ", a, b);
    scanf("%d", &userInput);

    if(solution == userInput){
        return 1;
    }

    while((tries < 3) && (userInput != solution) ){
        ++tries;
        puts("Incorrect: Try Again:");
        if(tries == 3) puts("Final Attempt");
        printf("%d - %d = ", a, b);
        scanf("%d", &userInput);

        if(solution == userInput){
            return 1;
        }
    }
    return 0;
}

int multiplication_problem(int a, int b){
    int solution = a * b;
    int userInput;
    int tries = 1;
    printf("%d * %d = ", a, b);
    scanf("%d", &userInput);

    if(solution == userInput){
        return 1;
    }

    while((tries < 3) && (userInput != solution) ){
        ++tries;
        puts("Incorrect: Try Again:");
        if(tries == 3) puts("Final Attempt");
        printf("%d * %d = ", a, b);
        scanf("%d", &userInput);

        if(solution == userInput){
            return 1;
        }
    }
    return 0;
}

int division_problem(int a, int b){
    int solution = a / b;
    int userInput;
    int tries = 1;
    printf("%d / %d = ", a, b);
    scanf("%d", &userInput);

    if(solution == userInput){
        return 1;
    }

    while((tries < 3) && (userInput != solution) ){
        ++tries;
        puts("Incorrect: Try Again:");
        if(tries == 3) puts("Final Attempt");
        printf("%d / %d = ", a, b);
        scanf("%d", &userInput);

        if(solution == userInput){
            return 1;
        }
    }
    return 0;
}
