#include <iostream>
#include <fstream>

using namespace std;

void PackFile(ifstream & inputFile, ofstream & outputFile)
{
	char readChar;
	int countChar = 0;
	while (inputFile.get(readChar) && (readChar != EOF))
	{
		++countChar;
		while (readChar != inputFile.peek())
		{
			outputFile << countChar << ',';
			outputFile << '\'' << readChar << '\'' << ',';
			countChar = 0;
			break;
		}
	}
}

void UnpackFile(ifstream & inputFile, ofstream & outputFile)
{
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: rle.exe unpack <input file> <output file>\n";
		return 1;
	}

	ifstream inputFile(argv[2]);
	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	ofstream outputFile(argv[3]);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[3] << " for writing\n";
		return 1;
	}

	string mode = argv[1];
	if (mode == "pack")
	{
		PackFile(inputFile, outputFile);
	}
	else if (argv[1] == "unpack")
	{
		UnpackFile(inputFile, outputFile);
	}
	else
	{
		cout << "You have not correctly specified the parameter <unpack || pack>\n";
		return 1;
	}
	return 0;
	
}
