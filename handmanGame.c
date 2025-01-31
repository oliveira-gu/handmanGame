#include <stdio.h>
#include <string.h>
#include "handmanGame.h"
#include <time.h>
#include <stdlib.h>

// Functions signature
void printHead();
void guess();
void printGame();
void chooseSecretWord();
int hit();
int hanged();
int guessed(char letter);


// Global variables
char secretWord[20];
char playerTries[26];
int numberOfGuesses = 0;

void printHead(){
    printf("*******************************\n");
    printf("* Welcome to the Handman Game *\n");
    printf("*******************************\n\n");
}

void guess(){
    char playerGuess;
    scanf(" %c", &playerGuess);

    playerTries[numberOfGuesses] = playerGuess;
    numberOfGuesses++;

    
}

int guessed(char letter){
    int found = 0;

    for (int j = 0; j < numberOfGuesses; j++) {
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
    FILE* f;

    f = fopen("words.txt", "r");
    if (f == 0)
    {
        printf("Sorry, no database available\n\n");
        exit(1);
    }
    
    int numberOfWords;
    fscanf(f, "%d", &numberOfWords);

    srand(time(0));
    int randomic = rand() % numberOfWords;
    
    for (int i = 0; i <= randomic; i++){
        fscanf(f, "%s", secretWord);
    }

    fclose(f);  
}

int hit(){
    for (int i = 0; i < strlen(secretWord); i++){
        if(!guessed(secretWord[i])){
            return 0;
        }
    }
    
    return 1;
}

int hanged(){

    int mistakes = 0;
    
    for (int i = 0; i < numberOfGuesses; i++){
        int exists = 0;

        for (int j = 0; j < strlen(secretWord); j++){
            if (playerTries[i] == secretWord[j]){
                exists = 1;
                break;
            }
            
        }
        
        if (!exists) mistakes++;
        
    }

    return mistakes >= 5;
}

int main(){

    chooseSecretWord();

    printHead();

    do {

        printGame();

        guess();

    } while (!hit() && !hanged());
    
}