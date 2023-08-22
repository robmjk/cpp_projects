// Dice Rolling Simulator

#include <iostream>
#include <cstdlib> // provides functions for performing various general-purpose operations, including memory allocation, random number generation, and other basic utilities
#include <ctime> // provides functions and types for working with time and date information.

using namespace std;

int main()
{
    // introductory messages
    cout << "Welcome to Kribz1k's dice rolling simulator" << endl;
    cout << "===========================================" << endl;
    cout << "You will be bestowed upon a pair of dice, in which you will roll for a random combination of numbers!" << endl;

    // creating variables and assigning default values
    int diceRoll = 0;
    int diceOne = 0;
    int diceTwo = 0;
    int diceCombo = 0;

    // makes sure that the dice rolls are not the same every time - adds unpredictability by starting the random number sequence from a different point based on the current time
    srand(time(0));

    // ask user how many times they want to roll the dice
    cout << "How many times do you want to roll the dice? - " << flush;
    cin >> diceRoll;

    // allows user to roll several times based on the diceRoll input given previously 
    for(int d = 0; d < diceRoll; d++)
    {
        // generating a random number between 6 and 1
        diceOne = rand() % 6 + 1;
        diceTwo = rand() % 6 + 1;
        cout << "Dice one roll: " << diceOne << endl;
        cout << "Dice two roll: " << diceTwo << endl;
        // combining the total value of both dice by addition
        diceCombo = diceOne + diceTwo;
        cout << "You rolled: " << diceCombo << "!" << endl;

        // outputting a thick underline to make dice rolls neat
        if (diceRoll > 1)
        {
            cout << "==============" << endl;
        }
    }

    return 0;
}

