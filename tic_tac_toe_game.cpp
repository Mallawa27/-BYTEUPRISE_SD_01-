#include <iostream>
#include <limits>

using namespace std;

const int BOARD_SIZE = 3;

char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the game board
void initializeBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to display the game board
void displayBoard() {
  cout << endl;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      cout << board[i][j];
      if (j < BOARD_SIZE - 1) {
        cout << " | ";
      }
    }
    cout << endl;
    if (i < BOARD_SIZE - 1) {
      for (int k = 0; k < BOARD_SIZE * 2 + 2; k++) {
        cout << "-";
      }
      cout << endl;
    }
  }
  cout << endl;
}

// Function to get a valid player move
int getPlayerMove(char player) {
  int move;
  while (true) {
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;

    // Input validation
    if (cin.fail() || move < 1 || move > BOARD_SIZE * BOARD_SIZE) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number between 1 and 9." << endl;
    } else {
      move--; // Convert from user input (1-9) to array index (0-8)

      int row = move / BOARD_SIZE;
      int col = move % BOARD_SIZE;

      if (board[row][col] != ' ') {
        cout << "This position is already occupied. Please try again." << endl;
      } else {
        return move;
      }
    }
  }
}

// Function to check if a player has won
bool checkWin(char player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

// Function to check if the game is a draw
bool isDraw() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  char player = 'X';
  int totalMoves = 0;

  initializeBoard();

  while (true) {
    displayBoard();

    int move = getPlayerMove(player);
    board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
    totalMoves++;

    if (checkWin(player)) {
      displayBoard();
      cout << "Player " << player << " wins!" << endl;
      break;
    }

    if (isDraw()) {
      displayBoard();
      cout << "It's a draw!" << endl;
      break;
    }

   player = (player == 'X') ? 'O' : 'X';
}
}
