#pragma once

#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>

void FindPrimeNumbers(std::set<int> & primeNumbers, std::vector<bool> const& numbers, int upperBound);
std::set<int> GeneratePrimeNumbersSet(int upperBound);
void PrintPrimeNumbersInOutput(std::set<int> const& primeNumbers);