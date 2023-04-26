#include <iostream>
#include <vector>

void printBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool checkDraw(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '-'));

    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;

    while (true) {
        std::cout << "Current board:" << std::endl;
        printBoard(board);
        std::cout << "It is " << currentPlayer << "'s turn." << std::endl;

        int row, col;
        std::cout << "Enter row and column to place your mark (0-2): ";
        std::cin >> row >> col;

        if (board[row][col] != '-') {
            std::cout << "That spot is already taken. Try again." << std::endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            std::cout << "Congratulations, " << currentPlayer << ", you win!" << std::endl;
            break;
        }

        if (checkDraw(board)) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        if (currentPlayer == player1) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }
    }

    std::cout << "Final board:" << std::endl;
    printBoard(board);

    return 0;
}
