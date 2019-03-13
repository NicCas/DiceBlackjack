#include <iostream>
#include "Die.h"

using namespace std;

int main() {

    /*
     * Chapter 13 Programming Challenge #18  A Game of 21 Pg 809
     *
     * For this assignment, you will write a program that lets the user play against the computer in a variation of
     * the popular blackjack card game. In this variation of the game, two six-sided dice are used instead of cards.
     * The dice are rolled, and the player tries to beat the computer’s hidden total without going over 21. Here are
     * some suggestions for the game’s design:
     *
     *      • Each round of the game is performed as an iteration of a loop that repeats as long as the player agrees
     *        to roll the dice, and the player’s total does not exceed 21.
     *
     *      • At the beginning of each round, the program will ask the users whether they want to roll the dice to
     *        accumulate points.
     *
     *      • During each round, the program simulates the rolling of two six-sided dice. It rolls the dice first for
     *        the computer, and then it asks the user if he or she wants to roll. (Use the Die class that was
     *        demonstrated in this chapter to simulate the dice).
     *
     *      • The loop keeps a running total of both the computer and the user’s points.
     *
     *
     *      • After the loop has finished, the computer’s total is revealed, and the player with the most points
     *        without going over 21 wins.
     *
     */

    const int dieSides = 6;
    int compTotal, playerTotal, compScore, playerScore;
    char userDecision;
    bool playRound = true;

    // Initialise number of games won
    compScore = 0;
    playerScore = 0;

    // Create 2 dice using Die.h and Die.cpp
    // .roll() and .getValue() are from that sample code that are used throughout this program
    Die die1(dieSides);
    Die die2(dieSides);

    // Explains the rules
    cout << "Welcome to Blackjack Dice! The object of the game is to get the highest score by rolling" << endl;
    cout << "6-sided die without going over 21. You are competing against the computer. If the computer" << endl;
    cout << "happens to go over 21 first, you win!" << endl << endl;

    // This while-loop allows the user to play multiple rounds
    while (playRound)
    {
        // Reset round totals
        compTotal = 0;
        playerTotal = 0;

        // This generates the computer's total. To make it more difficult, and possible for the computer to go over 21,
        // it always rolls until it passes 17
        while (compTotal <= 17)
        {
            die1.roll();
            die2.roll();
            compTotal = compTotal + die1.getValue() + die2.getValue();
        }

        // Player's initial roll
        die1.roll();
        die2.roll();
        playerTotal = die1.getValue() + die2.getValue();

        cout << "You rolled " << die1.getValue() << " & " << die2.getValue() << endl;
        cout << "Your total is: " << playerTotal << endl;

        // "Clear" userDecision so the code within while-loop isn't accidentally skipped
        userDecision = 'a';

        // Only accept 'y' or 'n' input
        while (userDecision != 'y' && userDecision != 'n')
        {
            cout << "\nWould you like to roll again? y/n" << endl;
            cin >> userDecision;
        }

        // While the player wants to continue to roll
        while (userDecision == 'y')
        {
            // Roll again
            die1.roll();
            die2.roll();
            playerTotal = playerTotal + die1.getValue() + die2.getValue();

            // Catch if player goes over 21
            if (playerTotal < 21)
            {
                // If the player has a total below 21 continue the round

                cout << "You rolled " << die1.getValue() << " & " << die2.getValue() << endl;
                cout << "Your total is: " << playerTotal << endl;

                // "Clear" userDecision so the code within while-loop isn't accidentally skipped
                userDecision = 'a';

                // Only accept 'y' or 'n' input
                while (userDecision != 'y' && userDecision != 'n')
                {
                    cout << "\nWould you like to roll again? y/n" << endl;
                    cin >> userDecision;
                }

            } else {

                // If the player has a total at or above 21 end the round

                userDecision = 'n';
            }

        }

        // Print totals
        cout << "\nYour final score was " << playerTotal << endl;
        cout << "The computer's score was " << compTotal << endl;
        cout << endl;

        // Calculate Winner
        if (compTotal > 21)
        {
            cout << "You win! The computer went over 21" << endl;
            playerScore ++;

        } else if (playerTotal > 21) {

            cout << "The computer wins! You went over 21" << endl;
            compScore ++;

        } else if (playerTotal > compTotal) {

            cout << "You win! You beat the computer's score" << endl;
            playerScore ++;

        } else if (compTotal > playerTotal) {

            cout << "The computer wins! It beat your score" << endl;
            compScore ++;

        } else if (compTotal == playerTotal) {

            cout << "It's a tie!" << endl;

        } else {

            // This should not be able to trigger
            cout << "Error: Something went wrong" << endl;

        }

        // Display who is winning more games
        cout << "You have won " << playerScore << " game(s) and the computer has won " << compScore << endl;

        // "Clear" userDecision so the code within while-loop isn't accidentally skipped
        userDecision = 'a';

        // Only accept 'y' or 'n' input
        while (userDecision != 'y' && userDecision != 'n')
        {
            // User can play another round or end game

            cout << endl;
            cout << "\nWould you like to play another round? y/n" << endl;
            cin >> userDecision;
        }

        // End game
        if (userDecision == 'n')
        {
            playRound = false;

        }
    }

    return 0;
}