#include <iostream>
#include <string>
#include "bioinformation.hpp"

// Prompts user for two DNA strings and outputting the base count of each and the hamming distance between the two
int main()
{
	std::string dna1;
	std::string dna2;

	// Prompt user for two sets of DNA strings untill they are both valid DNA strings and are the same length
	do {
		std::cout << "Please enter in two DNA strings of nucleotides: ";
		std::cin >> dna1;
		std::cout << "Enter second DNA strings of nucleotides: ";
		std::cin >> dna2;
		if (!bioinformation::validateDnaString(dna1) || !bioinformation::validateDnaString(dna2) || dna1.length() != dna2.length()) {
			std::cout << "Sorry, please enter the correct format for DNA strings. (Adenine(A), Thymine(T), Cytosine(C), Guanine(G)) Only enter the four letters. Also make sure the two DNA strings are the same length. \n";
		}
	} while (!bioinformation::validateDnaString(dna1) || !bioinformation::validateDnaString(dna2) || dna1.length() != dna2.length());

	// Outputting base count and hamming distance
	std::cout << "First DNA:\n";
	bioinformation::getBaseCount(dna1);

	std::cout << "Second DNA:\n";
	bioinformation::getBaseCount(dna2);

	bioinformation::outputHammingDistance(dna1, dna2);
}

