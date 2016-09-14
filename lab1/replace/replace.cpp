#include "stdafx.h"

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


void ReplaceStringInRow(string & rowFile, string const& searchString, string const& replaceString)
{
	size_t positionReplacedWords = rowFile.find(searchString);
	size_t startSearchPosition = positionReplacedWords;
	int countMissingChar = 0;
	while (positionReplacedWords != -1)
	{
		rowFile.replace(positionReplacedWords, searchString.length(), replaceString);
		startSearchPosition += replaceString.length() + countMissingChar;
		positionReplacedWords = rowFile.find(searchString, startSearchPosition);
		countMissingChar = positionReplacedWords - startSearchPosition;
	}
}

bool CheckForEmptyData(string const& rowFile, string const& searchString, string const& replaceString)
{
	return (rowFile.size() != 0) && (searchString.length() != 0) && (replaceString.length() != 0);
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