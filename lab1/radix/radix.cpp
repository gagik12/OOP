#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

static const int MAX_RADIX = 35;
static const int MIN_RADIX = 2;
static const int DECIMAL_RADIX = 10;

enum MathErr
{
	ME_OVERFLOW_ADD,
	ME_OVERFLOW_MULTIPLICATION,
	ME_UNDERFLOW_ADD,
	ME_UNDERFLOW_MULTIPLICATION
};

bool CheckIntervalRadix(int const& source, int const& destination)
{
	return (source >= MIN_RADIX) && (source <= MAX_RADIX) && (destination >= MIN_RADIX) && (destination <= MAX_RADIX);
}

int ConvertCharToInt(char const& ch)
{
	int digit = -1;
	if ((ch >= '0') && (ch <= '9'))
	{
		digit = ch - 0x30;
	}
	else if ((ch >= 'A') && (ch <= 'Z'))
	{
		digit = int(ch) - int('A') + DECIMAL_RADIX;
	}
	else if ((ch >= 'a') && (ch <= 'z'))
	{
		digit = int(ch) - int('a') + DECIMAL_RADIX;
	}
	return digit;
}

void ChekDigit(int & digit, int const& radix, bool & wasError)
{
	if (digit > radix)
	{
		cout << "The number can not be greater than radix!!!\n";
		wasError = true;
	}
	if (digit == -1)
	{
		cout << "Incorrect character in value!!!\n";
		wasError = true;
	}
}

string ReverseString(string const& result)
{
	string reverseString = "";
	for (int i = result.length() - 1; i >= 0; --i)
	{
		reverseString += result[i];
	}
	return reverseString;
}

void TransferNumbers(int decimalNumber, int destination, string & result)
{
	int number = decimalNumber % destination;
	if (number >= DECIMAL_RADIX)
	{
		result += char('A' + (number - DECIMAL_RADIX));
	}
	else
	{
		result += to_string(number);
	}
	decimalNumber = decimalNumber / destination;
}

string IntToString(int & decimalNumber, int & destination, bool & isMinus)
{
	string result = "";
	if (decimalNumber == 0)
	{
		result += "0";
	}
	while (decimalNumber)
	{
		TransferNumbers(decimalNumber, destination, result);
	}

	result = ReverseString(result);
	if (isMinus && (result != "0"))
	{
		result = "-" + result;
	}

	return result;
}

void PrintMathErr(MathErr& mathErr)
{
	switch (mathErr)
	{
	case 0:
		std::cout << "ME_OVERFLOW_ADD\n";
		break;
	case 1:
		std::cout << "ME_OVERFLOW_MULTIPLICATION\n";
		break;
	case 2:
		std::cout << "ME_UNDERFLOW_ADD\n";
		break;
	case 3:
		std::cout << "ME_UNDERFLOW_MULTIPLICATION\n";
		break;
	}
}

int Add(int multiplication, int number)
{
	if ((multiplication > 0) && (multiplication > INT_MAX - number))
	{
		throw ME_OVERFLOW_ADD;
	}
	return multiplication + number;
}

int Multiplication(int multiplier1, int multiplier2)
{
	if ((multiplier1 >= 0) && (multiplier2 >= 0) && (multiplier1 > INT_MAX / multiplier2))
	{
		throw ME_OVERFLOW_MULTIPLICATION;
	}
	return multiplier1 * multiplier2;
}

int Power(int radix, int power)
{
	int resulPower = 1;
	for (int i = 1; i <= power; ++i)
	{
		resulPower = Multiplication(resulPower, radix);
	}
	return resulPower;
}

int ConvertToDecimalRadix(string const& str, int const& radix, bool & wasError, bool &isMinus)
{
	int number = 0;
	int digit = 0;
	int multiplication = 0;
	int powerResult = 0;
	int power = str.length() - 1;
	for (int i = 0; i != str.length(); i++)
	{
		if ((i == 0) && (str[i] == '-'))
		{
			power = str.length() - 2;
			isMinus = true;
			continue;
		}
		digit = ConvertCharToInt(str[i]);
		ChekDigit(digit, radix, wasError);
		if (wasError)
		{
			return 1;
		}

		try
		{
			powerResult = Power(radix, power);
			multiplication = Multiplication(powerResult, digit);
			number = Add(multiplication, number);
		}
		catch (MathErr& mathErr)
		{
			PrintMathErr(mathErr);
			return 1;
		}
		power -= 1;
	}
	return number;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: radix.exe <source notation> <destination notation> <value>\n";
		return 1;
	}

	int source, destination;
	string value;
	try
	{
		source = stoi(argv[1]);
		destination = stoi(argv[2]);
		value = argv[3];
	}
	catch (exception const& e)
	{
		cout << "Error: " << e.what() << endl;
		return 1;
	}

	if (!CheckIntervalRadix(source, destination))
	{
		cout << "Interval radix [2, 35]!";
		return 1;
	}
	else
	{
		bool wasError = false, isMinus = false;
		int decimalNumber = ConvertToDecimalRadix(value, source, wasError, isMinus);
		if (!wasError)
		{
			string outputNumber = IntToString(decimalNumber, destination, isMinus);
			cout << outputNumber << "\n";
		}
	}
    return 0;
}

