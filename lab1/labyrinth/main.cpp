#include "stdafx.h"
#include "Wave_algorithm.h"
#include "Labirinth.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: labyrinth.exe <input file> <output file>\n";
		return 1;
	}

	ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ofstream outputFile(argv[2]);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	Labirinth labirinth;
	FillTheMapWithZeros(labirinth.map);

	bool wasError = false;
	ReadMap(inputFile, outputFile, labirinth, wasError);
	if (!wasError)
	{
		bool wasPathFound = false;
		DisseminationWave(labirinth, wasPathFound);
		if (wasPathFound)
		{
			RecoveryPath(labirinth);
			PrintMap(outputFile, labirinth.map, labirinth.components);
		}
		else
		{
			outputFile << "Maze without path!\n";
		}
	}
}
