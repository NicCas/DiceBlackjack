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
    int compValue;
    bool playRound = true;

    Die die1(dieSides);
    Die die2(dieSides);

    while (playRound)
    {

        die1.roll();
        die2.roll();
        compValue = die1.getValue() + die2.getValue();

        while (compValue <= 17)
        {

            die1.roll();
            compValue = compValue + die1.getValue();
        }

        playRound = false;

    }



    //Chapter 14 Programming Challenge #14 Parking Ticket Sim Pg 889


    return 0;
}