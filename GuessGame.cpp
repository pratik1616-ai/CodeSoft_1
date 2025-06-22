#include <iostream>
#include <random>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    cout << "=== NUMBER GUESSING GAME ===" << endl;
    cout << "Welcome! I'm thinking of a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;
    
    char playAgain;
    
    do {
       
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100);
        
        int secretNumber = dis(gen);
        int guess;
        int attempts = 0;
        bool hasWon = false;
        
        cout << "\nI've picked a new number! Start guessing:" << endl;
        
        while (!hasWon) {
            cout << "Enter your guess (1-100): ";
            
            if (!(cin >> guess)) {
                cout << "Please enter a valid number!" << endl;
                clearInputBuffer();
                continue;
            }
            
            attempts++;
            
            if (guess < 1 || guess > 100) {
                cout << "Please guess a number between 1 and 100!" << endl;
            } else if (guess > secretNumber) {
                cout << "Too high! Try a smaller number." << endl;
            } else if (guess < secretNumber) {
                cout << "Too low! Try a bigger number." << endl;
            } else {
                cout << "\nCongratulations! You got it!" << endl;
                cout << "The number was " << secretNumber << endl;
                cout << "You guessed it in " << attempts << " attempts!" << endl;
                hasWon = true;
            }
        }
        
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing! Goodbye!" << endl;
    
    return 0;
}