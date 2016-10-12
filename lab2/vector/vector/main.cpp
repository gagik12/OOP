#include "stdafx.h"
#include "ProcessVector.h"

int main()
{
	std::cout << "Enter the numbers separated by spaces: ";
	std::string inputString;
	std::getline(std::cin, inputString);

	std::vector<double> numbers = GetNumbers(inputString);
	ProcessVector(numbers);
}