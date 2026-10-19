#include <bits/stdc++.h>
using namespace std;


class Player {
    public:
        string name = "robot";
        char symbol;

        Player () {}

        Player (string name) {
            this->name = name;
        }
};


void drawBoard(char inputs[3][3]);
bool isPositionValid (char inputs[3][3], int pos[2]);
void drawMenu(char inputs[3][3], int turn, Player user, Player robot);
char checkResults(char inputs[3][3]);


int main() {
    srand(time(NULL));

    char inputs[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inputs[i][j] = ' ';
        }
    }

    string name;
    char winner_symbol;

    cout << "Enter your name: ";
    cin >> name;

    char tossChoice;

    cout << "\nWelcome to the TIC TAC TOE game, " << name << "!\n";
    cout << "\nChoose H or T for the first turn: ";
    cin >> tossChoice;

    char tossResult = (rand() % 2) ? 'H' : 'T';
    cout << "\nTOSS RESULT: ";
    (tossResult == 'H') ? cout << "Heads\n" : cout << "Tails\n";

    Player user(name);
    Player robot;

    int turn;   // User = 1, Robot = -1
    if (toupper(tossChoice) == tossResult) {
        cout << "\nCongratulations, you won the toss!\n";
        turn = 1;
        user.symbol = 'X';
        robot.symbol = 'O';
    } else {
        cout << "\nYou lost the toss!\n";
        turn = -1;
        user.symbol = 'O';
        robot.symbol = 'X';
    }

    while (1) {
        drawMenu(inputs, turn, user, robot);
        winner_symbol = checkResults(inputs);

        if (winner_symbol == user.symbol) {
            cout << "Congratulations! You won, " << user.name << ".\n";
            break;
        }

        if (winner_symbol == robot.symbol) {
            cout << "Computer wins!\n";
            break;
        }

        if (winner_symbol == 'D') {
            cout << "The game is a draw!\n";
            break;
        }

        turn *= -1;
    }

    return 0;
}


void drawBoard (char inputs[3][3]) {
    cout << "\n~~~~~~~~~~~~~\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << inputs[i][j] << " | ";
        }
        cout << "\n";
    }
    cout << "~~~~~~~~~~~~~\n";
}


bool isPositionValid(char inputs[3][3], int pos[2]) {
    if (pos[0] < 0 || pos[0] >= 3 ||
        pos[1] < 0 || pos[1] >= 3) {
        return false;
    }

    return inputs[pos[0]][pos[1]] == ' ';
}


void drawMenu(char inputs[3][3], int turn, Player user, Player robot) {
    int pos[2];

    cout << "It's " << ((turn < 0) ? "computer's " : "your ") << "turn to play..\n";

    if (turn > 0) {
        do {
            cout << "Choose a valid square from the grid (x y) : ";
            cin >> pos[0] >> pos[1];
            if (isPositionValid(inputs, pos)) {
                break;
            }
        } while (1);
        inputs[pos[0]][pos[1]] = user.symbol;
    } else {
        cout << "Computer is choosing..\n";
        do {
            pos[0] = rand() % 3;
            pos[1] = rand() % 3;
            if (isPositionValid(inputs, pos)) {
                break;
            }
        } while (1);
        inputs[pos[0]][pos[1]] = robot.symbol;
    }

    drawBoard(inputs);
}


char checkResults (char inputs[3][3]) {
    int count = 0;

    for (int i = 0; i < 3; i++) {
        if (inputs[i][0] != ' ' &&
            inputs[i][0] == inputs[i][1] && inputs[i][1] == inputs[i][2]) {
            return inputs[i][0];
        }
    }

    for (int j = 0; j < 3; j++) {
        if (inputs[0][j] != ' ' &&
            inputs[0][j] == inputs[1][j] && inputs[1][j] == inputs[2][j]) {
            return inputs[0][j];
        }
    }

    if (inputs[0][0] != ' ' &&
        inputs[0][0] == inputs[1][1] && inputs[1][1] == inputs[2][2]) {
        return inputs[0][0];
    }

    if (inputs[0][2] != ' ' &&
        inputs[0][2] == inputs[1][1] && inputs[1][1] == inputs[2][0]) {
        return inputs[0][2];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (inputs[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        return 'D';
    }

    return ' ';
}
