/*File Name : Chapter5Exercise20.cpp
 Developer/Programmer: Bryan Hurley
 Date: April 2025
 Requirements:
This program is a basic number guessing game.
*/

#include <iostream>
#include <random>
using namespace std;

// Generate random number between 1 and 100
int getSecret() {
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> dist(1, 100);
    return dist(eng);
}

// Get a valid guess using only cin
int getGuess() {
    int guess = 0;
    while (guess < 1 || guess > 100) {
        cout << "Enter a number (1–100): ";
        cin >> guess;
    }
    return guess;
}

// Main module
int main() {
    int secret = getSecret();
    int guess;

    cout << "Guess the number I'm thinking of (1–100)...\n";

    do {
        guess = getGuess();
        if (guess > secret) cout << "Too high!\n";
        else if (guess < secret) cout << "Too low!\n";
    } while (guess != secret);

    cout << "Correct!\n";
    return 0;
}