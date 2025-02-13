#include <stdio.h>
#include <string.h>
#include "hangmanGame.h"
#include <time.h>
#include <stdlib.h>

// Global variables
char secretWord[WORDSIZE];
char playerTries[26];
int numberOfGuesses = 0;

void printHead(){
    printf("*******************************\n");
    printf("* Welcome to the Hangman Game *\n");
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

    int mistakes = wrongGuesses();

    printf("  _______        \n");
    printf(" |/      |       \n");
    printf(" |      %c%c%c   \n", (mistakes >=1 ? '(' : ' '),
    (mistakes >=1 ? '_' : ' '), (mistakes >=1 ? ')' : ' '));
    printf(" |      %c%c%c   \n", (mistakes >= 3 ? '\\' : ' '),
     (mistakes >= 2 ? '|': ' '), (mistakes >= 3 ? '/' : ' '));
    printf(" |       %c      \n", (mistakes >= 2 ? '|': ' '));
    printf(" |      %c %c     \n", (mistakes >= 4 ? '/' : ' '),
     (mistakes >= 4 ? '\\' : ' '));
    printf(" |               \n");
    printf("_|___            \n");
    printf("\n\n");

    printf("Enter a letter:\n\n");
    
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

void addNewWord() {
    
    char wantToAdd;

    printf("Do you want to add a new word to the game? (S/N)");
    scanf(" %c", &wantToAdd);

    if (wantToAdd == 'S' || wantToAdd == 's') {
        char newWord[WORDSIZE];
        printf("What is the new word? ");
        scanf("%s", newWord);

        FILE* f;

        f = fopen("words.txt", "r+");
        if (f == 0){
            printf("Sorry, database no available\n\n");
            exit(1);
        }
        
        int quantity;
        fscanf(f, "%d", &quantity);
        quantity++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantity);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", newWord);

        fclose(f);
    }

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

int wrongGuesses(){
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

    return mistakes;
}

int hanged(){

    return wrongGuesses() >= 5;
}

int main(){

    chooseSecretWord();

    printHead();

    do {

        printGame();

        guess();

    } while (!hit() && !hanged());

    if(hit()){
        printf("YOU WON!\n\n");
    }else{
        printf("GAME OVER\n\n");
    }

    addNewWord();
    
}