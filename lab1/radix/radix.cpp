#include "stdafx.h"
#include <iostream>

using namespace std;

static const string FILE_PATH = "../replace/file/";

int ConvertCharToInt(char const& ch)
{
	int digit = -1;
	if ((ch >= '0') && (ch <= '9'))
	{
		digit = ch - 0x30; // Преобразование символа в число 
	}
	else if ((ch >= 'A') && (ch <= 'Z'))
	{
		digit = int(ch) - int('A') + 10;
	} 
	return digit;
}

int StringToInt(const string& str, int radix, bool & wasError)
{
	int number = 0;
	int digit = 0;
	int power = str.length() - 1; // Степень

	int maxIntDiv = INT_MAX / 10;
	int maxIntMod = INT_MAX % 10;

	for (int i = 0; i != str.length(); i++)
	{
		digit = ConvertCharToInt(str[i]);
		if (digit != -1)
		{
			number += digit * pow(radix, power);
			power += -1;
		}
	}
	cout << number;
	return number;
}

void TranslationOfRadix(int & source, int & destination, std::string const& value)
{
	bool wasError = false;
	StringToInt(value, source, wasError);

}

bool PresenceOfEmptyData(char *argv[])
{
	return (argv[1] == "") && (argv[2] == "") && (argv[3] == "");
}

int main(int argc, char *argv[])
{
	//std::cout << INT_MAX << std::endl;
	//int a = 2147483647;
	//cout << a << endl;
	/*if (argc != 4)
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
	}*/
	int source = atoi("16");
	int destination = atoi("10");
	std::string value = "1F";
	TranslationOfRadix(source, destination, value);
	return 0;
}