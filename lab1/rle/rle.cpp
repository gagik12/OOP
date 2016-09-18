#include <iostream>
#include <fstream>

using namespace std;

void PackFile(ifstream & inputFile, ofstream & outputFile)
{

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
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ofstream outputFile(argv[3]);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	if (argv[1] == "pack")
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
