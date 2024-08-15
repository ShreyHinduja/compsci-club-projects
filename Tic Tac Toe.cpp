/*
IF ANYBODY IS HERE TO COPY, PLEASE GO AWAY. YOU WILL FIND OUT HOW TO DO IT BY YOURSELF AT SOME POINT. IF YOU COPY, YOU WILL GET A Z GRADE, BUT EVEN IF YOU SUBMIT IT UNFINISHED, YOU WILL GET A BETTER GRADE. THANK YOU.
*/

#include <iostream>

using namespace std;

void drawBoard();

//---------left----------//
char topLeft = ' ';
char midLeft = ' ';
char bottomLeft = ' ';
//---------mid-----------//
char topMid = ' ';
char midMid = ' ';
char bottomMid = ' ';
//--------right----------//
char topRight = ' ';
char midRight = ' ';
char bottomRight = ' ';
//------player-turn------//
int playerTurn = 1;
//------player-move------//
int playerMove;
//-------booleans---------//
bool run = 1;
bool noSeenTie;
//----------------------//
void drawBoard() {
  cout << "\n         |          |     \n";
  cout << "         |          |     \n";
  cout << "   " << topLeft << "     |    " << topMid << "     |    " << topRight
       << "   \n";
  cout << "         |          |     \n";
  cout << "         |          |     \n";
  cout << "------------------------------\n";
  cout << "         |          |     \n";
  cout << "         |          |     \n";
  cout << "   " << midLeft << "     |    " << midMid << "     |    " << midRight
       << "   \n";
  cout << "         |          |     \n";
  cout << "         |          |     \n";
  cout << "------------------------------\n";
  cout << "         |          |     \n";
  cout << "         |          |     \n";
  cout << "   " << bottomLeft << "     |    " << bottomMid << "     |    "
       << bottomRight << "   \n";
  cout << "         |          |     \n";
  cout << "         |          |     \n\n";
}

bool playerOnesMoveAssist(int num) {
  if (num % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

void printMoves() {
  cout << "Here are the moves:\n  1) top left\n  2) top middle\n  3) top "
          "right\n  4) middle left\n  5) exact middle\n  6) middle right\n  7) "
          "bottom left\n  8) bottom middle\n  9) bottom right\n\n";
}

bool playerOneDetectedWin() {
  if ((topLeft == 'x' && topMid == 'x' && topRight == 'x') ||
      (midLeft == 'x' && midMid == 'x' && midRight == 'x') ||
      (bottomLeft == 'x' && bottomMid == 'x' && bottomRight == 'x') ||
      (bottomLeft == 'x' && bottomMid == 'x' && bottomRight == 'x') ||
      (topLeft == 'x' && midLeft == 'x' && bottomLeft == 'x') ||
      (topLeft == 'x' && midLeft == 'x' && bottomLeft == 'x') ||
      (topMid == 'x' && midMid == 'x' && bottomMid == 'x') ||
      (topRight == 'x' && midRight == 'x' && bottomRight == 'x') ||
      (topLeft == 'x' && midMid == 'x' && bottomRight == 'x') ||
      (topRight == 'x' && midMid == 'x' && bottomLeft == 'x')) {
    return true;
  } else {
    return false;
  }
}

bool playerTwoDetectedWin() {
  if ((topLeft == 'o' && topMid == 'o' && topRight == 'o') ||
      (midLeft == 'o' && midMid == 'o' && midRight == 'o') ||
      (bottomLeft == 'o' && bottomMid == 'o' && bottomRight == 'o') ||
      (bottomLeft == 'o' && bottomMid == 'o' && bottomRight == 'o') ||
      (topLeft == 'o' && midLeft == 'o' && bottomLeft == 'o') ||
      (topLeft == 'o' && midLeft == 'o' && bottomLeft == 'o') ||
      (topMid == 'o' && midMid == 'o' && bottomMid == 'o') ||
      (topRight == 'o' && midRight == 'o' && bottomRight == 'o') ||
      (topLeft == 'o' && midMid == 'o' && bottomRight == 'o') ||
      (topRight == 'o' && midMid == 'o' && bottomLeft == 'o')) {
    return true;
  } else {
    return false;
  }
}

bool tieDetected() {
  if ((topLeft != ' ' && topMid != ' ' && topRight != ' ' && midLeft != ' ' &&
       midMid != ' ' && midRight != ' ' && bottomLeft != ' ' &&
       bottomMid != ' ' && bottomRight != ' ') &&
      not(playerTwoDetectedWin()) && not(playerOneDetectedWin())) {
    return true;
  } else {
    return false;
  }
}

bool squareOccupied(char position) {
  if (position != ' ') {
    return true;
  } else {
    return false;
  }
}

int main() {
  cout << "Welcome to Shrey Hinduja's tic tac toe!\n";
  drawBoard();
  printMoves();
  while (run) {
    cin >> playerMove;
    switch (playerMove) {
    case 1:
      system("clear");
      if (squareOccupied(topLeft)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          topLeft = 'o';
          playerTurn++;
        } else {
          topLeft = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      if (tieDetected()) {
        cout << "DRAW\n\n";
      }
      printMoves();
      break;
    case 2:
      system("clear");
      if (squareOccupied(topMid)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          topMid = 'o';
          playerTurn++;
        } else {
          topMid = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      if (tieDetected()) {
        cout << "DRAW\n\n";
      }
      printMoves();
      break;
    case 3:
      system("clear");
      if (squareOccupied(topRight)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          topRight = 'o';
          playerTurn++;
        } else {
          topRight = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      if (tieDetected()) {
        cout << "DRAW\n\n";
      }
      printMoves();
      break;
    case 4:
      system("clear");
      if (squareOccupied(midLeft)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          midLeft = 'o';
          playerTurn++;
        } else {
          midLeft = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      if (tieDetected()) {
        cout << "DRAW\n\n";
      }
      printMoves();
      break;
    case 5:
      system("clear");
      if (squareOccupied(midMid)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          midMid = 'o';
          playerTurn++;
        } else {
          midMid = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      if (tieDetected()) {
        cout << "DRAW\n\n";
      }
      printMoves();
      break;
    case 6:
      system("clear");
      if (squareOccupied(midRight)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          midRight = 'o';
          playerTurn++;
        } else {
          midRight = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      if (tieDetected()) {
        cout << "DRAW\n\n";
      }
      printMoves();
      break;
    case 7:
      system("clear");
      if (squareOccupied(bottomLeft)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          bottomLeft = 'o';
          playerTurn++;
        } else {
          bottomLeft = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      if (tieDetected()) {
        cout << "DRAW\n\n";
      }
      printMoves();
      break;
    case 8:
      system("clear");
      if (squareOccupied(bottomMid)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          bottomMid = 'o';
          playerTurn++;
        } else {
          bottomMid = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      printMoves();
      break;
    case 9:
      system("clear");
      if (squareOccupied(bottomRight)) {
        cout << "This spot is occupied, please select another spot.\n";
      } else {
        if (playerOnesMoveAssist(playerTurn)) {
          bottomRight = 'o';
          playerTurn++;
        } else {
          bottomRight = 'x';
          playerTurn++;
        }
      }
      drawBoard();
      if (playerOneDetectedWin()) {
        cout << "P1 ( X ) WINS\n\n";
        run = 0;
      } else if (playerTwoDetectedWin()) {
        cout << "P2 ( O ) WINS\n\n";
        run = 0;
      }
      printMoves();
      break;
    default:
      cout << "Please select a proper move.\n";
      break;
    }
  }
}

/*
Congrats! You have reached the bottom of my code... Hi Mr. Santa Cruz! By
the way, the formatting was done using the button to the right of main.cpp (
right above line 1 ), I did not format it myself.
*/