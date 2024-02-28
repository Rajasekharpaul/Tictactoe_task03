#include <iostream>
using namespace std;
const int SIZE = 3;
char board[SIZE][SIZE];
void initializeBoard() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}
void printBoard() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}
bool isMoveValid(int row, int col) {
  return board[row][col] == ' ';
}
void makeMove(char player, int row, int col) {
  if (isMoveValid(row, col)) {
    board[row][col] = player;
  } else {
    cout << "Invalid move. Please try again." << endl;
  }
}
bool isWinner(char player) {
  for (int i = 0; i < SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }
  for (int i = 0; i < SIZE; i++) {
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

bool isBoardFull() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}
int main() {
  char currentPlayer = 'X';
  initializeBoard();
  while (true) {
    printBoard();
    cout << currentPlayer << "'s turn. Enter row and column (1-3): ";
    int row, col;
    cin >> row >> col;
    row--;
    col--;
    makeMove(currentPlayer, row, col);
    if (isWinner(currentPlayer)) {
      cout << currentPlayer << " wins!" << endl;
      break;
    }
    if (isBoardFull()) {
      cout << "It's a draw!" << endl;
      break;
    }
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }
  return 0;
}
