#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52
#define MAX_PLAYERS 3
#define STRING_SIZE 100
#define JACK_VALUE = 10
#define QUEEN_VALUE = 10
#define KING_VALUE = 10

int numberOfDecks;
int numberOfPlayers;

char* getRandomCard(char* deck[], int numberOfDecks) {
    int randomIndex = rand() % (DECK_SIZE * numberOfDecks);
    return deck[randomIndex / DECK_SIZE][randomIndex % DECK_SIZE];
}


int main() {
    char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    char* ranks[] = { "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
    char* deck[4][DECK_SIZE];
    int playerScores[4];
    char* playerCards[4][DECK_SIZE];

    

    for (;;) {  // Infinite loop
        // Prompt for the number of players
        printf("How many players are playing? (Enter -1 to exit) ");
        scanf("%d", &numberOfPlayers);

        if (numberOfPlayers == -1) {
            printf("Exiting...\n");
            break;  // Exit the loop
        }

        // Validate the number of players
        if (numberOfPlayers < 1 || numberOfPlayers > MAX_PLAYERS) {
            printf("Invalid number of players. Please enter a number between 1 and %d.\n", MAX_PLAYERS);
            continue;  // Continue to the next iteration
        }

        // This code sets the player scores to 0
        for (int x = 0; x < numberOfPlayers; x++) {
            playerScores[x] = 0;
        }

        // Prompt for the number of decks
        printf("How many decks of cards would you like to use? ");
        scanf("%d", &numberOfDecks);

        // Validate the number of decks
        if (numberOfDecks < 1) {
            printf("Invalid number of decks. Please enter a number greater than 0.\n");
            continue;  // Continue to the next iteration
        }

        // Check if there are enough cards for the given number of players and decks
        if (numberOfPlayers * 2 + 2 > DECK_SIZE * numberOfDecks) {
            printf("Not enough cards for the given number of players and decks. Please enter different values.\n");
            continue;  // Continue to the next iteration
        }

        // If the input is valid, break out of the loop and proceed to dealing cards
        break;
    }

    // THE FOLLOWING CODE SHUFFLES THE DECKS

    for (int deckCount = 0; deckCount < numberOfDecks; deckCount++) {
        int deckPos = 0;
        printf("\nDECK NUMBER %d\n\n", deckCount + 1);
        for (int i = 0; i < 4; i++) {
            char* type = suits[i];
            for (int q = 0; q < 13; q++) {
                char* rank = ranks[q];

                // Allocate memory for the concatenated string
                char concatenatedString[STRING_SIZE];
                strcpy_s(concatenatedString, sizeof(concatenatedString), type);
                strcat_s(concatenatedString, sizeof(concatenatedString), " ");
                strcat_s(concatenatedString, sizeof(concatenatedString), rank);

                // Allocate memory for the deck[deckPos] entry and copy the concatenated string
                deck[deckCount][deckPos] = malloc(strlen(concatenatedString) + 1);
                strcpy_s(deck[deckCount][deckPos], strlen(concatenatedString) + 1, concatenatedString);

                deckPos++;
            }
        }

        // Shuffle the deck using Fisher-Yates algorithm
        int size = sizeof(deck[deckCount]) / sizeof(deck[deckCount][0]);
        for (int i = size - 1; i > 0; i--) {
            int randomIndex = rand() % (i + 1);
            char* temp = deck[deckCount][i];
            deck[deckCount][i] = deck[deckCount][randomIndex];
            deck[deckCount][randomIndex] = temp;
        }


            char* randomCard = getRandomCard(deck, numberOfDecks);
            printf("RANDOM: %s", randomCard);

        // Print the shuffled deck
        for (int i = 0; i < DECK_SIZE; i++) {
            printf("%s\n", deck[deckCount][i]);
            printf("%d\n\n", getCardValue(deck[deckCount][i]));
        }
    }

    // Free allocated memory
    for (int i = 0; i < numberOfDecks; i++) {
        for (int j = 0; j < DECK_SIZE; j++) {
            free(deck[i][j]);
        }
    }


    

    return 0;
}



// The following function basically transforms the value of the card into its actual value
int getCardValue(char* cardName) {
    // Organized cases by suit and then by card value
    if (strncmp(cardName, "Diamonds", 8) == 0) {
        if (strstr(cardName, "1") != NULL) {
            return 1;
        }
        else if (strstr(cardName, "2") != NULL) {
            return 2;
        }
        else if (strstr(cardName, "3") != NULL) {
            return 3;
        }
        else if (strstr(cardName, "4") != NULL) {
            return 4;
        }
        else if (strstr(cardName, "5") != NULL) {
            return 5;
        }
        else if (strstr(cardName, "6") != NULL) {
            return 6;
        }
        else if (strstr(cardName, "7") != NULL) {
            return 7;
        }
        else if (strstr(cardName, "8") != NULL) {
            return 8;
        }
        else if (strstr(cardName, "9") != NULL) {
            return 9;
        }
        else if (strstr(cardName, "10") != NULL) {
            return 10;

        }
        else if (strstr(cardName, "Jack") != NULL) {
            return 10; // Assuming Jack has a value of 11
        }
        else if (strstr(cardName, "Queen") != NULL) {
            return 10; // Assuming Queen has a value of 12
        }
        else if (strstr(cardName, "King") != NULL) {
            return 10; // Assuming King has a value of 13
        }
        else if (strstr(cardName, "Ace") != NULL) {
            return 10; // Assuming Ace has a value of 14
        }
        else {
            return -1; // Unknown card
        }
    }
    else if (strncmp(cardName, "Hearts", 6) == 0) {
        if (strstr(cardName, "1") != NULL) {
            return 1;
        }
        else if (strstr(cardName, "2") != NULL) {
            return 2;
        }
        else if (strstr(cardName, "3") != NULL) {
            return 3;
        }
        else if (strstr(cardName, "4") != NULL) {
            return 4;
        }
        else if (strstr(cardName, "5") != NULL) {
            return 5;
        }
        else if (strstr(cardName, "6") != NULL) {
            return 6;
        }
        else if (strstr(cardName, "7") != NULL) {
            return 7;
        }
        else if (strstr(cardName, "8") != NULL) {
            return 8;
        }
        else if (strstr(cardName, "9") != NULL) {
            return 9;
        }
        else if (strstr(cardName, "10") != NULL) {
            return 10;

        }
        else if (strstr(cardName, "Jack") != NULL) {
            return 10; // Assuming Jack has a value of 11
        }
        else if (strstr(cardName, "Queen") != NULL) {
            return 10; // Assuming Queen has a value of 12
        }
        else if (strstr(cardName, "King") != NULL) {
            return 10; // Assuming King has a value of 13
        }
        else if (strstr(cardName, "Ace") != NULL) {
            return 10; // Assuming Ace has a value of 14
        }
        else {
            return -1; // Unknown card
        }
    }
    else if (strncmp(cardName, "Clubs", 5) == 0) {
        if (strstr(cardName, "1") != NULL) {
            return 1;
        }
        else if (strstr(cardName, "2") != NULL) {
            return 2;
        }
        else if (strstr(cardName, "3") != NULL) {
            return 3;
        }
        else if (strstr(cardName, "4") != NULL) {
            return 4;
        }
        else if (strstr(cardName, "5") != NULL) {
            return 5;
        }
        else if (strstr(cardName, "6") != NULL) {
            return 6;
        }
        else if (strstr(cardName, "7") != NULL) {
            return 7;
        }
        else if (strstr(cardName, "8") != NULL) {
            return 8;
        }
        else if (strstr(cardName, "9") != NULL) {
            return 9;
        }
        else if (strstr(cardName, "10") != NULL) {
            return 10;

        }
        else if (strstr(cardName, "Jack") != NULL) {
            return 10; // Assuming Jack has a value of 11
        }
        else if (strstr(cardName, "Queen") != NULL) {
            return 10; // Assuming Queen has a value of 12
        }
        else if (strstr(cardName, "King") != NULL) {
            return 10; // Assuming King has a value of 13
        }
        else if (strstr(cardName, "Ace") != NULL) {
            return 10; // Assuming Ace has a value of 14
        }
        else {
            return -1; // Unknown card
        }
    }
    else if (strncmp(cardName, "Spades", 6) == 0) {
        if (strstr(cardName, "1") != NULL) {
            return 1;
        }
        else if (strstr(cardName, "2") != NULL) {
            return 2;
        }
        else if (strstr(cardName, "3") != NULL) {
            return 3;
        }
        else if (strstr(cardName, "4") != NULL) {
            return 4;
        }
        else if (strstr(cardName, "5") != NULL) {
            return 5;
        }
        else if (strstr(cardName, "6") != NULL) {
            return 6;
        }
        else if (strstr(cardName, "7") != NULL) {
            return 7;
        }
        else if (strstr(cardName, "8") != NULL) {
            return 8;
        }
        else if (strstr(cardName, "9") != NULL) {
            return 9;
        }
        else if (strstr(cardName, "10") != NULL) {
            return 10;

        }
        else if (strstr(cardName, "Jack") != NULL) {
            return 10; // Assuming Jack has a value of 11
        }
        else if (strstr(cardName, "Queen") != NULL) {
            return 10; // Assuming Queen has a value of 12
        }
        else if (strstr(cardName, "King") != NULL) {
            return 10; // Assuming King has a value of 13
        }
        else if (strstr(cardName, "Ace") != NULL) {
            return 10; // Assuming Ace has a value of 14
        }
        else {
            return -1; // Unknown card
        }
    }
    else {
        return -1; // Unknown suit
    }
}