#include <iostream>
#include <vector>
#include <string>

void updateBoard(std::string& move) {
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

bool isPositionAvaiable(std::vector<std::vector<char>>& board, std::string& move) {
	int row;
	int column;

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

	for (int i = 0; i < board.size(); i++) {
		if (row == i) {
			return board[i][column] == ' ';
		}
	}
}

void displayBoard(std::vector<std::vector<char>> board) {
	std::cout << board[0][0];
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

int main()
{
	// Win Variables
	bool playerWin = false;
	bool compWin = false;
	std::string currentMove;

	std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

	std::cout << "Let's play Tic Tac Toe!\n";
	std::cout << "You are X. and the computer is O!\n\n";
	std::cout << "Enter your move in rows and columns (a, b, c)(1, 2, 3). Example: (b3)\n\n";

	displayBoard(board);

	std::cout << "(X) What is your move: ";
	std::cin >> currentMove;

	std::cout << isValidMove(currentMove);

	// Keep calling function till any win variable is true
	do {
		// Keep calling if current move is not valid
		do {
			displayBoard(board);

			std::cout << "(X) What is your move: ";
			std::cin >> currentMove;


		} while (!isValidMove(currentMove));

		updateBoard();
	} while (!playerWin && !compWin);
}
