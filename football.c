// Include the standard input/output header
#include <stdio.h>

// Create a prototype function for find_combinations
void find_combinations(int points);

// Create a main function that is run when football.c is run
int main() {
    // Run a while loop to continually prompt the user for points
    while (1) {
        // Create a variable that will store the integer that the user entered
        int points;
        // Prompt the user to enter the score
        printf("\nEnter the NFL score (Enter 1 to stop): ");
        // Use scanf to get the score the user entered
        scanf("%d", &points);
        // Check to see if the input is equal to 1, which indicates the user wants to stop
        if (points == 1) {
            // break out of the while loop
            break;
        }
        // If points isn't 1, check to see if the entered points is negative
        else if (points < 0) {
            // Tell the user that they entered an invalid amount of points
            printf("\n%d is not a valid amount of points for an NFL score. Please try again.\n", points);
        }
        // If the points are greater than 1, find the number of combinations
        else {
            // Pass the score into the find_combinations function
            find_combinations(points);
        }
    }
    // Exit the main function with a return of 0
    return 0;
}

// Create a function that takes in the number of points that were scored and find all combinations of scoring
void find_combinations(int points) {
    // Run a for loop that will run for each time the number of points can be divided by 8
    for (int eights = 0; eights <= points/8; eights++) {
        // Run a for loop that will run for each time the remaining number of points can be divided by 7
        for (int sevens = 0; sevens <= (points - (8*eights))/7; sevens++) {
            // Run a for loop will run for each time the remaining number of points can be divided by 6
            for (int sixes = 0; sixes <= (points - (8*eights) - (7*sevens))/6; sixes++) {
                // Run a for loop that will run for each time the remaining number of points can be divided by 3
                for (int threes = 0; threes <= (points - (8*eights) - (7*sevens) - (6*sixes))/3; threes++) {
                    // Run a for loop that will run for each time the remaining number of points can be divided by 2
                    for (int twos = 0; twos <= (points - (8*eights) - (7*sevens) - (6*sixes) - (3*threes))/2; twos++) {
                        // Check to see if the combinations of values adds up to the number of points
                        if ((points - (8*eights) - (7*sevens) - (6*sixes) - (3*threes) - (2*twos)) == 0) {
                            // Print the valid combination that has been found
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", eights, sevens, sixes, threes, twos);
                        }
                    }
                }
            }
        }
    }
}