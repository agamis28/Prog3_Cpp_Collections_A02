#include <iostream>
#include <vector>
#include <string>

void clearCin() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Check if a string contains a certain character, returns false if it does not contain it
bool containsChar(std::string string, char character) {
	// Check if string does not contain the letter return false
	return string.find(character) != std::string::npos;
}

// Check if input string move has 2 characters and one is a valid number and one is a valid character, return false if none apply
bool isValidMove(std::string& move) {
	bool isNum = false;
	bool hasValidLetter = false;

	// If string input has more or less than 2 character return false (Not a valid move)
	if (move.length() != 2) {
		return false;
	}

	// Check if any of the characters is a number
	if (containsChar(move, '1')) {
		isNum = true;
	}
	if (containsChar(move, '2')) {
		isNum = true;
	}
	if (containsChar(move, '3')) {
		isNum = true;
	}
	// If number check doesn't pass, return false (Not a valid move)
	if (!isNum) {
		return false;
	}

	// Check if any of the characters is a valid letter (a, b, or c). 
	if (containsChar(move, 'a')) {
		hasValidLetter = true;
	}
	if (containsChar(move, 'b')) {
		hasValidLetter = true;
	}
	if (containsChar(move, 'c')) {
		hasValidLetter = true;
	}
	// If letter check doesn't pass, return false (Not a valid move)
	if (!hasValidLetter) {
		return false;
	}

	return true;
}

int getRow(std::string& move) {
	int row = NULL;

	// Setting row selected
	if (containsChar(move, 'a')) {
		row = 0;
	}
	else if (containsChar(move, 'b')) {
		row = 1;
	}
	else if (containsChar(move, 'c')) {
		row = 2;
	}

	return row;
}

int getColumn(std::string& move) {
	int column = NULL;

	// Setting column selected
	if (containsChar(move, '1')) {
		column = 0;
	}
	else if (containsChar(move, '2')) {
		column = 1;
	}
	else if (containsChar(move, '3')) {
		column = 2;
	}

	return column;
}

// Check if inputted position is available in vector board, if not available return false
bool isPositionAvaiable(std::vector<std::vector<char>>& board, std::string& move) {
	int row = getRow(move);
	int column = getColumn(move);

	for (int i = 0; i < board.size(); i++) {
		if (row == i) {
			return board[i][column] == ' '; // Returns true if the board position is ' ', else returns false
		}
	}

	return false;
}

// Check if random position is available in vector board, if not available return false
bool compIsPositionAvailable(std::vector<std::vector<char>>& board, std::vector<int>& compMove) {
	for (int i = 0; i < board.size(); i++) {
		if (compMove[0] == i) {
			return board[i][compMove[1]] == ' '; // Returns true if the board position is ' ', else returns false
		}
	}

	return false;
}

// Displays board to user by looping through vector of vectors, and outputting each char in vector as well as lines inbetween each. Also displaying grid position names
void displayBoard(std::vector<std::vector<char>>& board) {
	for (int i = 0; i < board.size(); i++) {
		if (i == 0) {
			std::cout << "  1 2 3\n";
			std::cout << "a  " << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "\n";
			std::cout << "  --+-+--\n";
		}
		if (i == 1) {
			std::cout << "b  " << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "\n";
			std::cout << "  --+-+--\n";
		}
		if (i == 2) {
			std::cout << "c  " << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "\n\n";
		}
	}
}

bool checkIfWon(std::vector<std::vector<char>>& board, char player) {

	// Checking if win state horizontal lines, return true
	if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
		return true;
	}
	if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
		return true;
	}
	if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
		return true;
	}

	// Checking if win state vertical lines, return true
	if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
		return true;
	}
	if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
		return true;
	}
	if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
		return true;
	}

	// Checking if win state diagonal lines, return true
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return true;
	}
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		return true;
	}

	return false;
}

bool checkIfTie(const std::vector<std::vector<char>>& board) {
	for (const auto& row : board) {
		for (char column : row) {
			if (column == ' ') {
				return false; // Return false immediately if a space is found
			}
		}
	}
	return true; // Return true if no spaces were found
}

// Picking a random move for computer
std::vector<int> computerRandomMove() {
	std::vector<int> computerMove;

	return computerMove = { rand() % (2 - 0 + 1),rand() % (2 - 0 + 1) };
}

int main()
{
	// Adding seed for random number
	std::srand(time(0));

	// Win Variables
	bool playerWin = false;
	bool compWin = false;
	bool tie = false;
	std::string currentMove;
	std::vector<int> computerMove;

	std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

	std::cout << "Let's play Tic Tac Toe!\n";
	std::cout << "You are X. and the computer is O!\n\n";
	std::cout << "Enter your move in rows and columns (a, b, c)(1, 2, 3). Example: (b3)\n\n";

	displayBoard(board);

	// Keep calling function till any win variable is true
	do {
		// Keep calling if current move is not valid
		do {
			std::cout << "(X) What is your move: ";
			std::cin >> currentMove;

			if (!isValidMove(currentMove)) {
				std::cout << "\nInvalid move. Try Again.\n\n";
			}
			if (isValidMove(currentMove) && !isPositionAvaiable(board, currentMove)) {
				std::cout << "\nSorry that position was taken. Try Again.\n\n";
			}
			clearCin();
		} while (!isValidMove(currentMove) || !isPositionAvaiable(board, currentMove));

		// Update board
		board[getRow(currentMove)][getColumn(currentMove)] = 'X';

		displayBoard(board);

		// Check if player won
		playerWin = checkIfWon(board, 'X');
		if (playerWin) {
			std::cout << "You Won!";
			break;
		}

		// Check if it is a tie
		tie = checkIfTie(board);
		if (tie) {
			std::cout << "It's a tie!";
			break;
		}

		// Computer Move, keep setting move untill position is available
		do {
			computerMove = computerRandomMove();
		} while (!compIsPositionAvailable(board, computerMove));

		// Update board
		board[computerMove[0]][computerMove[1]] = 'O';

		std::cout << "Computer made its move!\n";

		displayBoard(board);

		// Check if computer won
		compWin = checkIfWon(board, 'O');
		if (compWin) {
			std::cout << "Computer Won!";
			break;
		}

	} while (!playerWin && !compWin && !tie);
}
