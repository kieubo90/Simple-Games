#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userChoice, computerChoice;
    srand(time(0)); // seed the random number generator
    
    printf("Let's play rock-paper-scissors!\n");
    printf("Enter 1 for rock, 2 for paper, or 3 for scissors: ");
    scanf("%d", &userChoice);
    
    // generate a random choice for the computer
    computerChoice = rand() % 3 + 1; // generate a random number between 1 and 3
    
    printf("You chose ");
    switch (userChoice) {
        case 1:
            printf("rock.\n");
            break;
        case 2:
            printf("paper.\n");
            break;
        case 3:
            printf("scissors.\n");
            break;
        default:
            printf("an invalid choice.\n");
            return 1;
    }
    
    printf("The computer chose ");
    switch (computerChoice) {
        case 1:
            printf("rock.\n");
            break;
        case 2:
            printf("paper.\n");
            break;
        case 3:
            printf("scissors.\n");
            break;
    }
    
    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    }
    else if ((userChoice == 1 && computerChoice == 3) ||
			 (userChoice == 2 && computerChoice == 1) || 
			(userChoice == 3 && computerChoice == 2)) 
        printf("Congratulations, you win!\n");
    else 
        printf("Sorry, you lose.\n");
    return 0;
}
