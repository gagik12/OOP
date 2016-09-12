#include "stdafx.h"

using namespace std;

static const string FILE_PATH = "../replace/file/";

string GetLineFile(ifstream & inputFile)
{
	string lineFile;
	getline(inputFile, lineFile);
	return lineFile;
}

ifstream OpenInputFile(string const& inputFileName)
{
	ifstream inputFile;
	inputFile.open(FILE_PATH + inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Error opening file!\n";
		exit(1);
	}
	return inputFile;
}

void ReplaceStringInRow(string & rowFile, string const& searchString, string const& replaceString)
{
	int positionReplacedWords = rowFile.find(searchString);
	int startSearchPosition = positionReplacedWords;
	int countMissingChar = 0; 
	while (positionReplacedWords != -1)
	{
		rowFile.replace(positionReplacedWords, searchString.length(), replaceString);
		startSearchPosition += replaceString.length() + countMissingChar;
		positionReplacedWords = rowFile.find(searchString, startSearchPosition);
		countMissingChar = positionReplacedWords - startSearchPosition;
	}
}

bool СheckForEmptyData(string const& rowFile, string const& searchString, string const& replaceString)
{
	return (rowFile.size() != 0) && (searchString.length() != 0) && (replaceString.length() != 0);
}

void ReplaceStringInFile(char *argv[])
{
	string inputFileName = argv[1];
	string outputFileName = argv[2];
	string searchString = argv[3];
	string replaceString = argv[4];

	ifstream inputFile = OpenInputFile(inputFileName);
	ofstream outputFile(FILE_PATH + outputFileName);

	while (!inputFile.eof())
	{
		string rowFile = GetLineFile(inputFile);
		if (СheckForEmptyData(rowFile, searchString, replaceString))
		{
			ReplaceStringInRow(rowFile, searchString, replaceString);
		}
		outputFile << rowFile << '\n';
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

