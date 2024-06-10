// Lab 8 - Hangmam
// Vansh Joshi
// 05-07-2024
// This is a 2 player hangman game where the 1st player can pick a word and the 2nd player has to guess the word. If the 2nd cannot guess the word then they lose.
// used copilot to help understand the logic of hangman. I also used it to help me compile all the files together but for some reason it wound't work so it is in one file.
// used old class notes for recursion and vectors

#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

// variables
string dashes;
string word;
int counter;

/* I made a recursive function that asks the user to guess a letter
if the user gets it wrong it will remove one of the limbs, and
if the user gets it right it will replace the corresponding dash with the letter, revealing it.*/

void makeGuess(int tries)
{

    // get user input
    char userInput;
    cout << "Player 2 enter a letter: " << endl;
    cin >> userInput;

    // checks if user has inputed a letter and not a integer
    while (isdigit(userInput))
    {
        cout << "Please enter a letter. " << endl;
        cin >> userInput;
    }

    bool reveal = false;
    for (int i = 0; i < word.length(); i++)
    {

        // replace dash with letter
        if ((word[i] == userInput) && (dashes[i] != userInput))
        {

            // if correct letter put dash instead of letter
            dashes[i] = userInput;
            reveal = true;
            counter++;
        }
    }
    // if false remove one of the limbs
    if (reveal == false)
    {
        tries--;
        cout << "you have " << tries << " limbs remaining" << endl;
    }
    cout << endl;

    // display again dash with letters instead
    for (int i = 0; i < word.size(); i++)
    {
        cout << dashes[i] << " ";
    }
    cout << endl;
    if (tries > 0 && counter < word.size())
        makeGuess(tries);
}

int main()
{
    int winCount1 = 0;
    int winCount2 = 0;

    while (true)
    {

        // quick introduciton to how to play the game
        cout << "|**************************************|" << endl;
        cout << "| How to Play:                         |" << endl;
        cout << "| Player1: enter a Singular word       |" << endl;
        cout << "| Player2: you have to guess the word  |" << endl;
        cout << "| that was entered by player1 you only |" << endl;
        cout << "| get seven tries                      |" << endl;
        cout << "|**************************************|" << endl;

        int underscore = 0;
        char playAgain;

        // gets player 1 input
        cout << "Player 1 enter a word: ";
        cin >> word;

        // puts the dashes in a array that is the same length as the word length
        for (int i = 0; i < word.length(); i++)
        {
            dashes.push_back('_');
        }

        // Lowercases the word
        for (int i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }

        // Prints 45 blank lines so that the player 1 input is hidden from player 2's input
        for (int i = 0; i < 45; i++)
        {
            cout << " " << endl;
        }

        // prints the same amount of dashes as the letters in the word
        for (int i = 0; i < word.size(); i++)
        {
            cout << dashes[i] << " ";
        }

        cout << endl;

        int tries = 7;
        makeGuess(tries);

        // prints wether player 1 or 2 has won
        if (counter == word.size())
        {
            cout << "Player 2, you have won!" << endl;
            winCount2++;
        }
        else
        {
            cout << "Player 1, you have won!" << endl;
            winCount1++;
        }

        cout << endl;
        cout << "Player 1 wins: " << winCount1 << ",  Player 2 wins: " << winCount2 << endl;

        // asks if they want to play again
        cout << endl;
        cout << "would you like to play again? y/n" << endl;
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'n')
        {
            cout << "Please enter "
                 << "y"
                 << " or "
                 << " n" << endl;
            cin >> playAgain;
        }
        if (playAgain == 'n')
        {
            winCount1 = 0;
            winCount2 = 0;
            break;
        }

        counter = 0;
        word = "";
        dashes = "";
    }
}
