#include "stdafx.h"
#include <boost/algorithm/string/replace.hpp>

using namespace std;

string GetLineFile(ifstream & inputFile)
{
	string lineFile;
	getline(inputFile, lineFile);
	return lineFile;
}

bool CheckFiles(ifstream &inputFile, ofstream &outputFile)
{
	if (!inputFile.is_open())
	{
		cout << "The file is not open for reading." << endl;
		return false;
	}

	if (!outputFile.is_open())
	{
		cout << "File not opened for writing." << endl;
		return false;
	}

	return true;
}

void ReplaceStringInRow(string & src, string const& search, string const& replace)
{
	boost::replace_all(src, search, replace);
	cout << src << endl;
	/*
	size_t positionReplacedWords = src.find(search);
	size_t startSearchPosition = positionReplacedWords;
	int countMissingChar = 0;
	while (positionReplacedWords != -1)
	{
		src.replace(positionReplacedWords, search.length(), replace);
		startSearchPosition += replace.length() + countMissingChar;
		positionReplacedWords = src.find(search, startSearchPosition);
		countMissingChar = positionReplacedWords - startSearchPosition;
	}*/
}

bool CheckForEmptyData(string const& rowString, string const& searchString, string const& replaceString)
{
	return (rowString.size() != 0) && (searchString.length() != 0) && (replaceString.length() != 0);
}

void ReplaceStringInFile(char *argv[])
{
	string inputFileName = argv[1];
	string outputFileName = argv[2];
	string searchString = argv[3];
	string replaceString = argv[4];

	ifstream inputFile(inputFileName);
	ofstream outputFile(outputFileName);
	CheckFiles(inputFile, outputFile);

	while (!inputFile.eof())
	{
		string rowFile = GetLineFile(inputFile);
		if (CheckForEmptyData(rowFile, searchString, replaceString))
		{
			ReplaceStringInRow(rowFile, searchString, replaceString);
		}
		if (inputFile.eof())
		{
			outputFile << rowFile;
		}
		else
		{
			outputFile << rowFile << '\n';
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 5)
	{
		cout << "Invalid number of parameters!\n";
		return 1;
	}
	ReplaceStringInFile(argv);
	return 0;
}
