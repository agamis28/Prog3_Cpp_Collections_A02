#pragma once
#include <iostream>
#include <map>
#include <string>

namespace bioinformation {
	bool validateDnaString(std::string);

	void outputNucleotides(std::map<std::string, int>&);

	void getBaseCount(std::string);

	int findStringDifferences(std::string, std::string);

	void getDna();
}