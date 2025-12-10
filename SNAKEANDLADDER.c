#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
=====================================================
 Snake and Ladders Game - C Program
 ----------------------------------------------------
 Author: G.Meghana
 Description:
     A simple Snake and Ladders game implemented in C.
     - The board has 100 squares.
     - Player rolls a dice (1–6).
     - Snakes pull the player down.
     - Ladders take the player up.
     - The first player to reach exactly 100 wins.

 Documentation:
     - Clearly commented code for GitHub submission.
     - Easy to modify / extend.
=====================================================
*/

// Define snake and ladder positions
int snakeBite(int position) {
    switch(position) {
        case 99: return 54;
        case 70: return 55;
        case 52: return 42;
        case 25: return 2;
        case 95: return 72;
        default: return position;
    }
}

int ladderClimb(int position) {
    switch(position) {
        case 4: return 25;
        case 13: return 46;
        case 33: return 49;
        case 42: return 63;
        case 50: return 69;
        case 62: return 81;
        case 74: return 92;
        default: return position;
    }
}

// Roll dice function
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int playerPos = 0; // Player starting position
    int dice;

    srand(time(0));

    printf("\n===== Snake and Ladders Game =====\n");
    printf("Player starts at position 0. Reach 100 to win!\n");

    while (playerPos < 100) {
        printf("\nPress Enter to roll the dice...");
        getchar();

        dice = rollDice();
        printf("You rolled: %d\n", dice);

        // Check if move is valid
        if (playerPos + dice <= 100) {
            playerPos += dice;
            printf("Moved to position %d\n", playerPos);
        } else {
            printf("Roll exceeds 100! Stay at %d\n", playerPos);
        }

        // Check for snake or ladder
        int oldPos = playerPos;
        playerPos = ladderClimb(playerPos);
        if (playerPos != oldPos) {
            printf("Lucky! Climbed a ladder to %d\n", playerPos);
        }

        oldPos = playerPos;
        playerPos = snakeBite(playerPos);
        if (playerPos != oldPos) {
            printf("Oh no! Bitten by a snake. Slid to %d\n", playerPos);
        }

        // Check win
        if (playerPos == 100) {
            printf("\n Congratulations! You reached 100 and won the game! \n");
            break;
        }
    }

    return 0;
}