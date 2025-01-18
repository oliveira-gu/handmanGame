#include <stdio.h>
#include <string.h>

void printHead(){
    printf("*******************************\n");
    printf("* Welcome to the Handman Game *\n");
    printf("*******************************\n\n");
}

void guess(char playerTries[26], int tries){
    char playerGuess;
    scanf(" %c", &playerGuess);

    playerTries[tries] = playerGuess;
    
}

int main(){

    char secretWord[20];

    sprintf(secretWord, "MELAO");  

    int hit = 0;
    int hanged = 0;

    char playerTries[26];
    int tries = 0;

    printHead();

    do {
        for (int i = 0; i < strlen(secretWord); i++) {
            
            int found = 0;

            for (int j = 0; j < tries; j++) {
                if(playerTries[j] == secretWord[i]) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                printf("%c ", secretWord[i]);
            }else {
                printf("_ ");
            }
        }
        printf("\n");

        guess(playerTries, tries);
        tries++;

    } while (!hit && !hanged);
    

}