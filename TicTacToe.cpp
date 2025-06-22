#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToeGame {
private:
    vector<vector<char>> gameBoard;
    char currentPlayer;
    
public:
    
    TicTacToeGame() {
        gameBoard = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }
    
   
    void displayBoard() {
        cout << "\n  Current Board:" << endl;
        cout << "     1   2   3" << endl;
        cout << "   +---+---+---+" << endl;
        
        for (int i = 0; i < 3; i++) {
            cout << " " << (i + 1) << " | " << gameBoard[i][0] << " | " 
                 << gameBoard[i][1] << " | " << gameBoard[i][2] << " |" << endl;
            cout << "   +---+---+---+" << endl;
        }
        cout << endl;
    }
    
  
    bool getPlayerMove() {
        int row, col;
        
        cout << "Player " << currentPlayer << "'s turn!" << endl;
        cout << "Enter row (1-3): ";
        
        if (!(cin >> row)) {
            clearInput();
            cout << "Invalid input! Please enter a number." << endl;
            return false;
        }
        
        cout << "Enter column (1-3): ";
        if (!(cin >> col)) {
            clearInput();
            cout << "Invalid input! Please enter a number." << endl;
            return false;
        }
        
        return makeMove(row, col);
    }
    

    bool makeMove(int row, int col) {
        // Check if position is valid
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid position! Please enter numbers between 1 and 3." << endl;
            return false;
        }
        

        row--;
        col--;
        
      
        if (gameBoard[row][col] != ' ') {
            cout << "Position already taken! Choose another spot." << endl;
            return false;
        }
        
     
        gameBoard[row][col] = currentPlayer;
        return true;
    }
 
    bool checkForWin() {
       
        for (int i = 0; i < 3; i++) {
            if (gameBoard[i][0] == currentPlayer && 
                gameBoard[i][1] == currentPlayer && 
                gameBoard[i][2] == currentPlayer) {
                return true;
            }
        }
        
       
        for (int j = 0; j < 3; j++) {
            if (gameBoard[0][j] == currentPlayer && 
                gameBoard[1][j] == currentPlayer && 
                gameBoard[2][j] == currentPlayer) {
                return true;
            }
        }
        
        
        if (gameBoard[0][0] == currentPlayer && 
            gameBoard[1][1] == currentPlayer && 
            gameBoard[2][2] == currentPlayer) {
            return true;
        }
        
       
        if (gameBoard[0][2] == currentPlayer && 
            gameBoard[1][1] == currentPlayer && 
            gameBoard[2][0] == currentPlayer) {
            return true;
        }
        
        return false;
    }
    
  
    bool checkForDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == ' ') {
                    return false; 
                }
            }
        }
        return true; 
    }
    
 
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    void playGame() {
        cout << "=== TIC-TAC-TOE GAME ===" << endl;
        cout << "Two players: X and O" << endl;
        cout << "Players take turns placing their mark on the 3x3 grid." << endl;
        cout << "First to get 3 in a row (horizontal, vertical, or diagonal) wins!" << endl;
        
        bool gameRunning = true;
        
        while (gameRunning) {
            displayBoard();

            if (!getPlayerMove()) {
                continue; 
            }
            
          
            if (checkForWin()) {
                displayBoard();
                cout << "🎉 Congratulations! Player " << currentPlayer << " wins! 🎉" << endl;
                gameRunning = false;
            }
          
            else if (checkForDraw()) {
                displayBoard();
                cout << "It's a draw! Good game both players!" << endl;
                gameRunning = false;
            }
      
            else {
                switchPlayer();
            }
        }
    }
    

    void resetGame() {
        gameBoard = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
    }
};

int main() {
    TicTacToeGame game;
    char playAgain;
    
    do {
        game.playGame();
        
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        
        if (playAgain == 'y' || playAgain == 'Y') {
            game.resetGame();
            cout << "\nStarting a new game!" << endl;
        }
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing Tic-Tac-Toe! Goodbye!" << endl;
    
    return 0;
}