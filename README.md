# Tic Tac Toe ❌⭕ 

A simple terminal-based Tic Tac Toe game built using C++. Play against a computer opponent, compete for three consecutive symbols, and test your luck with a coin toss to decide who goes first.

## ✨ Features

- **Player vs Computer:** Play against a computer that randomly selects available squares.
- **Coin Toss:** Choose Heads or Tails to determine who gets the first turn.
- **Custom Player Name:** Enter your name at the beginning of the game.
- **Dynamic Symbol Assignment:** The first player gets `X`, while the second gets `O`.
- **Input Validation:** Prevents moves outside the board and selecting occupied squares.
- **Win Detection:** Checks all rows, columns, and diagonals for a winning combination.
- **Draw Detection:** Recognizes when the board is full without a winner.
- **Terminal Interface:** Displays the board after every move.

## 🛠️ Tech Stack

- **Language:** C++
- **Libraries:** Standard C++ library (`bits/stdc++.h`)
- **Concepts:** Classes and objects, functions, 2D arrays, loops, conditionals, random number generation, and input validation.

## 🎮 How to Play

1. Enter your name.
2. Choose `H` for Heads or `T` for Tails.
3. The coin toss determines who plays first.
4. Enter the row and column of your desired square when prompted.
5. Get three matching symbols in a row, column, or diagonal to win.
6. If all nine squares are occupied without a winning combination, the game ends in a draw.

## 📋 Board Coordinates

The board uses zero-based indexing, meaning row and column numbers range from `0` to `2`.

```text
~~~~~~~~~~~~~
|   |   |   |
|   |   |   |
|   |   |   |
~~~~~~~~~~~~~
```

For example, entering `1 2` selects the square in the second row and third column.

| Coordinate | Position |
|---|---|
| `0 0` | Top-left |
| `0 2` | Top-right |
| `1 1` | Center |
| `2 0` | Bottom-left |
| `2 2` | Bottom-right |

## 🚀 Getting Started

### Prerequisites

- A C++ compiler such as `g++` or Clang.
- A terminal or command-line environment.

### Installation

**1. Clone the repository**

```bash
git clone https://github.com/E-Boy19/tic-tac-toe
```

**2. Navigate to the project directory**

```bash
cd TicTacToe
```

**3. Compile the program**

Using `g++`:

```bash
g++ main.cpp -o tictactoe
```

**4. Run the game**

macOS / Linux:

```bash
./tictactoe
```

Windows:

```bash
tictactoe.exe
```

> **Note:** The program uses `bits/stdc++.h`, which is supported by GCC and some compatible toolchains but is not part of the standard C++ library. If your compiler doesn't support it, replace it with the required standard headers, such as `iostream`, `string`, `cstdlib`, `ctime`, and `cctype`.

## ⚙️ How It Works

### 1. Player Initialization

The game creates two `Player` objects: one for the user and one for the computer. The user's name is supplied at runtime, while the computer uses the default name `robot`.

### 2. Coin Toss

The program randomly generates Heads or Tails. If the player's choice matches the result, the player starts; otherwise, the computer starts.

### 3. Turn Management

The variable `turn` determines whose turn it is:

- `1` — User's turn.
- `-1` — Computer's turn.

After each move, the turn is switched by multiplying `turn` by `-1`.

### 4. Move Validation

The program checks whether the selected row and column are within the board and whether the chosen square is empty.

### 5. Computer Moves

The computer randomly selects available squares until it finds an unoccupied position. It does not currently use a strategic algorithm to choose its moves.

### 6. Result Detection

The `checkResults()` function checks all rows, columns, and diagonals for three matching non-empty symbols. It also checks whether all nine squares are occupied.

The function returns:

- `X` or `O` if that symbol wins.
- `D` if the game ends in a draw.
- A space character if the game is still in progress.

## 👨‍💻 Author

**Aaditya Garud**

Built with C++ 💻

---

*Tic Tac Toe is a learning project focused on object-oriented programming, functions, arrays, game logic, and basic input validation in C++.*
