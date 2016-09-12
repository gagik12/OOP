#include "stdafx.h"
#include <iostream>
#include <string> 

using namespace std;

int ConvertCharToInt(char const& ch)
{
	int digit = -1;
	if ((ch >= '0') && (ch <= '9'))
	{
		digit = ch - 0x30; 
	}
	else if ((ch >= 'A') && (ch <= 'Z'))
	{
		digit = int(ch) - int('A') + 10;
	}
	else if ((ch >= 'a') && (ch <= 'z'))
	{
		digit = int(ch) - int('a') + 10;
	}
	return digit;
}

bool isOverflow(int & number, int const& digit, bool const& isMinus)
{
	int maxIntDiv = INT_MAX / 10;
	int maxIntMod = INT_MAX % 10;
	return (maxIntDiv > number / 10) || ((maxIntDiv == number / 10) && (maxIntMod >= digit));
}

int StringToInt(string const& str, int const& radix, bool & wasError, bool &isMinus)
{
	int number = 0;
	int digit = 0;
	int power = str.length() - 1;
	for (int i = 0; i != str.length(); i++)
	{
		if (str[i] == '-')
		{
			power = str.length() - 2;
			isMinus = true;
			continue;
		}
		digit = ConvertCharToInt(str[i]);
		if (digit != -1)
		{
			if (isOverflow(number, digit, isMinus))
			{
				number += digit * static_cast<int>(pow(radix, power));
				power += -1;
			}
			else
			{
				cout << "Overflow!!!\n" ;
				wasError = true;
			}
		}
		else
		{
			cout << "Invalid character!!!\n";
			wasError = true;
		}
	}
	return number;
}

string ReverseString(string const& result)
{
	string conversely = "";
	for (int i = result.length() - 1; i >= 0; --i)
	{
		conversely += result[i];
	}
	return conversely;
}

string TranslationOfRadix(int & source, int & destination, std::string const& value)
{
	bool wasError = false;
	bool isMinus = false;
	string result = "";
	int decimalNumber = StringToInt(value, source, wasError, isMinus);
	if (decimalNumber == 0)
	{
		result += "0";
	}
	if (!wasError)
	{
		int t = 0;
		while (decimalNumber)
		{
			t = decimalNumber % destination;
			if (t >= 10)
			{
				result += char('A' + (t - 10));
			}
			else
			{
				result += to_string(t);
			}
			decimalNumber = decimalNumber / destination;
		}

		result = ReverseString(result);
		if (isMinus && (result != "0"))
		{
			result = "-" + result;
		}
	}
	return result;
}

bool PresenceOfEmptyData(char *argv[])
{
	return (argv[1] == "") && (argv[2] == "") && (argv[3] == "");
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "Invalid number of parameters!\n";
		return 1;
	}
	int source = atoi(argv[1]);
	int destination = atoi(argv[2]);
	std::string value = argv[3];
	if (PresenceOfEmptyData(argv))
	{
		cout << "There are empty data!!!" ;
		return 1;
	}
	cout << TranslationOfRadix(source, destination, value);
	return 0; 
}