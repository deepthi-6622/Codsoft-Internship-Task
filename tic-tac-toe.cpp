#include <iostream>
using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char currentPlayer = 'X';

void displayBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

void playerMove() {
    int row, col;
    cout << "Player " << currentPlayer << ", enter your move (row and column): ";
    cin >> row >> col;

    // Validate the move
    while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
    }

    // Update the board
    board[row][col] = currentPlayer;
}

bool checkWin() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;  // Check rows
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;  // Check columns
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;  // Check diagonal
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;  // Check reverse diagonal

    return false;
}

bool checkDraw() {
    // Check for a draw
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;  // Empty cell found, game not a draw

    return true;  // All cells filled, game is a draw
}

void switchPlayers() {
    // Switch between players
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    do {
        displayBoard();
        playerMove();

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!" << endl;
        } else {
            switchPlayers();
        }
    } while (!checkWin() && !checkDraw());

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board for a new game
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';

        currentPlayer = 'X';
        main();  // Start a new game
    }

    return 0;
}

