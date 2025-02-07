# Hangman Game

## About the Project
This is a Hangman game developed in C, where the player tries to guess a secret word. The game displays a gallows in the terminal, and as the player makes incorrect guesses, body parts are added. The player has a limit of four mistakes before the game over.

## Demonstration
Example of game execution in the terminal:
```
*******************************
* Welcome to the Hangman Game *
*******************************

  _______
 |/      |
 |      (_)
 |      \|/
 |       |
 |      / \
_|___

_ _ A _ _

Enter a letter: 
```

## How to Run
### Compile the program:
```sh
gcc hangmanGame.c -o hangmanGame
```

### Execute:
```sh
./hangmanGame
```

## Game Rules
- The player must guess the secret word by entering one letter at a time.
- If the letter is in the word, it is revealed in the correct position.
- If the letter is not in the word, the gallows will be updated with a body part.
- The player can make up to 4 mistakes before the game over.
- If all letters are revealed before reaching the mistake limit, the player wins!
- At the end of the game, the player can add a new word to the game.

## Code Architecture
The project is divided into the following files:

### `hangmanGame.c`
- Contains the main game logic.
- Responsible for selecting the secret word, processing guesses, and displaying the game state.
- Manages player input and checks win or loss conditions.

### `hangmanGame.h`
- Defines constants and declares auxiliary functions.
- Helps organize the code.

### `words.txt`
- A file that stores the list of available words for the game.
- The player can add new words at the end of a game session.

## Possible Improvements
- Implement support for accented characters and special symbols.
- Enhance terminal interface by adding colors.
- Create a multiplayer mode where one player sets the word and the other tries to guess it.

## Contribution
Feel free to suggest improvements or modify the game. To contribute:
1. Fork the repository
2. Create a branch for your improvement
3. Submit a Pull Request

Enjoy playing Hangman! 

