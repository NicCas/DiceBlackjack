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
    char userDesision;
    bool playRound = true;

    compScore = 0;
    playerScore = 0;

    Die die1(dieSides);
    Die die2(dieSides);

    while (playRound)
    {
        die1.roll();
        die2.roll();
        compTotal = die1.getValue() + die2.getValue();

        while (compTotal <= 17)
        {
            die1.roll();
            compTotal = compTotal + die1.getValue();
        }

        die1.roll();
        die2.roll();
        playerTotal = die1.getValue() + die2.getValue();

        cout << "You rolled " << die1.getValue() << " & " << die2.getValue() << endl;
        cout << "Your total is: " << playerTotal << endl;

        userDesision = 'a';

        while (userDesision != 'y' && userDesision != 'n')
        {
            cout << "\nWould you like to roll again? y/n" << endl;
            cin >> userDesision;
        }

        while (userDesision == 'y')
        {
            if (playerTotal <= 21)
            {
                die1.roll();
                die2.roll();
                playerTotal = playerTotal + die1.getValue() + die2.getValue();

                cout << "You rolled " << die1.getValue() << " & " << die2.getValue() << endl;
                cout << "Your total is: " << playerTotal << endl;

                userDesision = 'a';

                while (userDesision != 'y' && userDesision != 'n')
                {
                    cout << "\nWould you like to roll again? y/n" << endl;
                    cin >> userDesision;
                }

            } else {

                userDesision = 'n';
            }

        }

        cout << "The computer's score was " << compTotal << endl;
        cout << endl;

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
            cout << "Error: Something went wrong" << endl;

        }

        cout << "You have won" << playerScore << " games and the computer has won " << compScore << endl;

        userDesision = 'a';

        while (userDesision != 'y' && userDesision != 'n')
        {
            cout << endl;
            cout << "\nWould you like to play another round? y/n" << endl;
            cin >> userDesision;
        }

        if (userDesision == 'n')
        {
            playRound = false;

        }

    }



    //Chapter 14 Programming Challenge #14 Parking Ticket Sim Pg 889


    return 0;
}