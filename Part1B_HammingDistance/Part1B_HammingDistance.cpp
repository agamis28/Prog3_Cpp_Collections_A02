#include <iostream>
#include <string>

// Retreives two strings params, loop through each char in them against eachother, if they don't match up, add to differences. Return the number of differnces
int findStringDifferences(std::string x, std::string y) {
	int differences = 0;
	for (int i = 0; i < x.length(); i++) {
		if (x[i] != y[i]) {
			differences++;
		}
	}
	return differences;
}

int main()
{
	// DNA Strings
	std::string firstDna;
	std::string secondDna;

	std::cout << "Please enter in two DNA strings of nucleotides to find the hamming distance: ";
	std::cin >> firstDna;
	std::cout << "Enter second DNA strings of nucleotides: ";
	std::cin >> secondDna;

	std::cout << "Hamming distance between DNA strings is: " << findStringDifferences(firstDna, secondDna);
}

