#include <stdio.h>
#include <string.h>

void printHead(){
    printf("*******************************\n");
    printf("* Welcome to the Handman Game *\n");
    printf("*******************************\n\n");
}

void guess(char playerTries[26], int* tries){
    char playerGuess;
    scanf(" %c", &playerGuess);

    playerTries[*tries] = playerGuess;
    (*tries)++;

    
}

int guessed(char letter, char playerTries[26], int tries){
    int found = 0;

    for (int j = 0; j < tries; j++) {
        if(playerTries[j] == letter) {
            found = 1;
            break;
        }
    }

    return found;

}

void printGame(char secretWord[20], char playerTries[26], int tries){
    for (int i = 0; i < strlen(secretWord); i++) {
            
            int found = guessed(secretWord[i],playerTries,tries);
            
            if (found) {
                printf("%c ", secretWord[i]);
            }else {
                printf("_ ");
            }
        }
    printf("\n");
}

void chooseSecretWord(char secretWord[20]){
    sprintf(secretWord, "MELAO");  
}

int main(){

    char secretWord[20];

    chooseSecretWord(secretWord);

    int hit = 0;
    int hanged = 0;

    char playerTries[26];
    int tries = 0;

    printHead();

    do {

        printGame(secretWord, playerTries, tries);

        guess(playerTries, &tries);

    } while (!hit && !hanged);
    

}