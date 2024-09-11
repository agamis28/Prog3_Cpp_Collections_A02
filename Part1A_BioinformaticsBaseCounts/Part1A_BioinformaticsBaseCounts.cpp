#include <iostream>
#include <map>
#include <string>

// Outputs the base counts of each nucleotides in user inputed DNA, by iterating through a map param and outputting the key and values assosicated.
void outputNucleotides(std::map<std::string, int>& map) {
	std::cout << "Base count of nucleotides are ";
	for (const auto& [key, value] : map) {
		std::cout << key << ": " << value << " ";
	}
}

int main()
{
	std::string dna;
	std::map<std::string, int> nucleotides{ {"A",0}, {"T",0},{"C",0},{"G",0} };

	std::cout << "Please enter a DNA string of nucleotides: ";
	std::cin >> dna;

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

