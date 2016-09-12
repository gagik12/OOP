#include "stdafx.h"
#include <iostream>
#include <string> 

using namespace std;

static const string FILE_PATH = "../replace/file/";

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
	return digit;
}

bool isOverflow(int const& number, int const& digit)
{
	
	int maxIntDiv = INT_MAX / 10;
	int maxIntMod = INT_MAX % 10;

	int minIntDiv = INT_MIN / 10;
	int minIntMod = INT_MIN % 10;

	return (maxIntDiv > number / 10) || ((maxIntDiv == number / 10) && (maxIntMod >= digit));
}

int StringToInt(string const& str, int const& radix, bool & wasError)
{
	int number = 0;
	int digit = 0;
	int power = str.length() - 1; 
	for (int i = 0; i != str.length(); i++)
	{
		digit = ConvertCharToInt(str[i]);
		if (digit != -1)
		{
			if (isOverflow(number, digit))
			{
				number += digit * pow(radix, power);
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

string IntToString(int n, int radix, bool & wasError)
{
	if (n >= 10)
	{
		//return int(ch) - int('A') + 10;
		cout << char('A' + (n - 10));
	}
	return "";
}

string TranslationOfRadix(int & source, int & destination, std::string const& value)
{
	bool wasError = false;
	int decimalNumber = StringToInt(value, source, wasError);
	string result = "";
	if (!wasError)
	{
		int t = 0;
		while (decimalNumber)
		{
			t = decimalNumber % destination;
			if (destination > 10)
			{
				IntToString(t, destination, wasError);
				//cout << t;
				//convert += IntToString(t, destination, wasError);
			}
			else
			{
				result += to_string(t);
			}
			decimalNumber = decimalNumber / destination;
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