/*File Name : Chapter5Exercise20.cpp
 Developer/Programmer: Bryan Hurley
 Date: April 2025
 Requirements:
This program is a basic number guessing game with menu.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <random>
using namespace std;

// Menu
int getMenuChoice() {
    int choice = 0;
    bool ran = false;
    while (choice < 1 || choice > 4) {
        if (ran == true) {
            cout << "Please Enter 1, 2, 3, or 4" << endl;
        }
        cout << "1. Display Sessions\n2. Play Game\n3. Delete Sessions\n4. Exit\nChoice: ";
        cin >> choice;
        ran = true;
    }
    return choice;
}

// Game with guess counter
void playGame() {
    string name;
    int guess = 0;
    int tries = 0;

    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> dist(1, 100);
    int secret = dist(eng);

    cout << "Enter your name: ";
    cin >> name;

    while (guess != secret) {
        cout << "Guess (1 – 100): ";
        cin >> guess;
        tries++;
        if (guess < secret) cout << "Too low.\n";
        else if (guess > secret) cout << "Too high.\n";
    }

    ofstream file("sessions.txt", ios::app);
    file << name << " guessed correctly in " << tries << " tries.\n";
    file.close();
    cout << "Correct in " << tries << " tries!\n";
}

// Sessions
void showSessions() {
    ifstream file("sessions.txt");
    string line;
    cout << "\n-- Sessions --\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
void deleteSessions() {
    ofstream file("sessions.txt", ios::trunc);
    file.close();
    cout << "Sessions cleared.\n";
}

int main() {
    int choice;
    do {
        choice = getMenuChoice();
        if (choice == 1) showSessions();
        else if (choice == 2) playGame();
        else if (choice == 3) deleteSessions();
    } while (choice != 4);

    return 0;
}
