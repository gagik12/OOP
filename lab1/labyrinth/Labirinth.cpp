#include "Labirinth.h"

using namespace std;

void ReadMap(ifstream &inputFile, ofstream &outputFile, Labirinth &labirinth, bool &wasError)
{
	string buffer;
	int row = 0;
	bool haveStart = false;
	bool haveFinish = false;
	while (getline(inputFile, buffer) && (row < (SIZE_MAP - 1)))
	{
		for (int column = 0; column != buffer.length(); ++column)
		{
			if (column == (SIZE_MAP - 1))
			{
				break;
			}
			switch (buffer[column])
			{
			case '#':
				labirinth.map[row][column] = WALL;
				break;
			case 'A':
				labirinth.map[row][column] = START;
				labirinth.startPoint = { row, column };
				if (!labirinth.startPoint.is_initialized())
				{
					outputFile << "We found more than one starting points!\n";
					wasError = true;
				}
				break;
			case 'B':
				labirinth.map[row][column] = END;
				labirinth.finishPoint = { row, column };
				if (!labirinth.finishPoint.is_initialized())
				{
					outputFile << "We found more than one starting points!\n";
					wasError = true;
				}
				break;
			default:
				labirinth.map[row][column] = 0;
			}
		}
		row++;
	}
	if (!labirinth.startPoint.is_initialized())
	{
		outputFile << "Not set the starting point!\n";
		wasError = true;
	}
	if (!labirinth.finishPoint.is_initialized())
	{
		outputFile << "Not set the finish point!\n";
		wasError = true;
	}
}

void PrintMap(ofstream &outputFile, Map &map, ComponentsMap const& componentsMap)
{
	for (int y = 0; y != SIZE_MAP - 1; ++y)
	{
		for (int x = 0; x != SIZE_MAP - 1; ++x)
		{
			auto componentResult = componentsMap.find(map[y][x]);
			if (componentResult == componentsMap.end())
			{
				outputFile << ' ';
			}
			else
			{
				outputFile << componentResult->second;
			}
		}
		outputFile << endl;
	}

}

void FillTheMapWithZeros(Map &map)
{
	for (int row = 0; row != SIZE_MAP - 1; ++row)
	{
		for (int column = 0; column != SIZE_MAP - 1; ++column)
		{
			map[row][column] = 0;
		}
	}
}