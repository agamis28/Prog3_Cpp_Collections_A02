#include <iostream>
#include <map>
#include <string>

#include "bioinformation.hpp"

namespace bioinformation {

	std::string dna1;
	std::string dna2;

	// Takes in a string to validate, if all characters are DNA types return true, otherwise false
	bool validateDnaString(std::string dnaString) {
		for (char letter : dnaString) {
			if (letter != 'A' && letter != 'T' && letter != 'C' && letter != 'G') {
				return false;
			}
		}
		return true;
	}

	// Outputs the base counts of each nucleotides in user inputed DNA, by iterating through a map param and outputting the key and values assosicated.
	void outputNucleotides(std::map<std::string, int>& map) {
		std::cout << "Base count of nucleotides are ";
		for (const auto& [key, value] : map) {
			std::cout << key << ": " << value << " ";
		}
	}

	void outputHammeringDistance() {
		std::cout << "Hamming distance between DNA strings is: " << findStringDifferences(dna1, dna2);
	}

	// Takes in a DNA string, creates a map nucleotides, and iterates through each character in param string to sort nucleotide types
	void getBaseCount(std::string dna)
	{
		std::map<std::string, int> nucleotides{ {"A",0}, {"T",0},{"C",0},{"G",0} };

		// Iterate through each char in string 'DNA' and sort characters to nucleotide types, then add to map key value to denote how many types of each we have in 'DNA'
		for (char letter : dna) {
			if (letter == 'A') {
				nucleotides["A"]++;
			}
			else if (letter == 'T') {
				nucleotides["T"]++;
			}
			else if (letter == 'C') {
				nucleotides["C"]++;
			}
			else if (letter == 'G') {
				nucleotides["G"]++;
			}
		}

		outputNucleotides(nucleotides);
	}

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

	//Getting two DNA strings from input, and storing it in string variables for namespace
	void getDna()
	{
		do {
			std::cout << "Please enter in two DNA strings of nucleotides: ";
			std::cin >> dna1;
			std::cout << "Enter second DNA strings of nucleotides: ";
			std::cin >> dna2;
			if (!validateDnaString(dna1) || !validateDnaString(dna2)) {
				std::cout << "Sorry, please enter the correct format for DNA strings. (Adenine(A), Thymine(T), Cytosine(C), Guanine(G)) Only enter the four letters. \n";
			}
		} while (!validateDnaString(dna1) || !validateDnaString(dna2));
	}
}