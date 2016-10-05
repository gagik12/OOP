#include "stdafx.h"
#include "GeneratorPrimeNumbers.h"

using namespace std;

static const int MIN_PRIME_NUMBER = 2;

void FindPrimeNumbers(set<int> & primeNumbers, vector<bool> const& numbers, int upperBound)
{
	for (int i = MIN_PRIME_NUMBER; i <= upperBound; ++i)
	{
		if (numbers[i])
		{
			primeNumbers.insert(i);
		}
	}
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	vector<bool> numbers(upperBound + 1, true);
	numbers[0] = false;
	numbers[1] = false;
	for (int i = MIN_PRIME_NUMBER; i * i <= upperBound; ++i)
	{
		if (numbers[i])
		{
			for (int j = i*i; j <= upperBound; j += i)
			{
				numbers[j] = false;
			}
		}
	}
	set<int> primeNumbers;
	FindPrimeNumbers(primeNumbers, numbers, upperBound);
	return primeNumbers;
}

void PrintPrimeNumbersInOutput(set<int> const& primeNumbers)
{
	for (auto it = primeNumbers.begin(); it != primeNumbers.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "\n";
}