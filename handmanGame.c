#include <stdio.h>
#include <string.h>

// Global variables
char secretWord[20];
char playerTries[26];
int tries = 0;

void printHead(){
    printf("*******************************\n");
    printf("* Welcome to the Handman Game *\n");
    printf("*******************************\n\n");
}

void guess(){
    char playerGuess;
    scanf(" %c", &playerGuess);

    playerTries[tries] = playerGuess;
    tries++;

    
}

int guessed(char letter){
    int found = 0;

    for (int j = 0; j < tries; j++) {
        if(playerTries[j] == letter) {
            found = 1;
            break;
        }
    }

    return found;

}

void printGame(){
    for (int i = 0; i < strlen(secretWord); i++) {
            
            int found = guessed(secretWord[i]);
            
            if (found) {
                printf("%c ", secretWord[i]);
            }else {
                printf("_ ");
            }
        }
    printf("\n");
}

void chooseSecretWord(){
    sprintf(secretWord, "MELAO");  
}

int main(){

    int hit = 0;
    int hanged = 0;

    chooseSecretWord();

    printHead();

    do {

        printGame();

        guess();

    } while (!hit && !hanged);
    
}