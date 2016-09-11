#include "stdafx.h"
#include <iostream>
#include <limits.h>

using namespace std;

static const string FILE_PATH = "../replace/file/";

int StringToInt(const string& str, int radix, bool & wasError)
{
	return 1;
}

void TranslationOfRadix(int & source, int & destination, std::string const& value)
{
	bool wasError;
	StringToInt(value, source, wasError);

}

int main(int argc, char *argv[])
{
	std::cout << INT_MAX << std::endl;
	//int a = 2147483647;
	//cout << a << endl;
	/*if (argc != 4)
	{
		cout << "Invalid number of parameters!\n";
		return 1;
	}*/
	/*int source = atoi(argv[1]);
	int destination = atoi(argv[2]);
	std::string value = argv[3];*/

	int source = atoi("16");
	int destination = atoi("10");
	std::string value = "1F";
	TranslationOfRadix(source, destination, value);
	return 0;
}