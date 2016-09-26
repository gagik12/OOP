#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <sstream>

static const int SIZE_MAP = 101;
using namespace std;

typedef int Map[SIZE_MAP][SIZE_MAP];

struct Point
{
	int y, x;
};

typedef vector<Point> Wave;
static const Point step[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

struct Labirinth
{
	Map map;
	Point startPoint;
	Point finishPoint;
};

void ReadMap(ifstream &inputFile, ofstream &outputFile, Labirinth &labirinth, bool &wasError)
{
	string buffer;
	int row = 0;
	bool haveStart = false;
	bool haveFinish = false;
	while (getline(inputFile, buffer) && (row < (SIZE_MAP - 1)))
	{
		for (int colum = 0; colum != buffer.length(); ++colum)
		{
			if (colum == (SIZE_MAP -1))
			{
				break;
			}
			switch (buffer[colum])
			{
			case '#':
				labirinth.map[row][colum] = -1;
				break;
			case 'A':
				labirinth.map[row][colum] = 1;
				labirinth.startPoint = { row, colum };
				if (!haveStart)
				{
					haveStart = true;
				}
				else
				{
					outputFile << "We found more than one starting points!\n";
					wasError = true;
				}
				break;
			case 'B':
				labirinth.map[row][colum] = -2;
				labirinth.finishPoint = { row, colum };
				if (!haveFinish)
				{
					haveFinish = true;
				}
				else
				{
					outputFile << "We found more than one finish points!\n";
					wasError = true;
				}
				break;
			default:
				labirinth.map[row][colum] = 0;
			}
		}
		row++;
	}
	if (!haveStart)
	{
		outputFile << "Not set the starting point!\n";
		wasError = true;
	}
	if (!haveFinish)
	{
		outputFile << "Not set the finish point!\n";
		wasError = true;
	}
}

void PrintMap(ofstream &outputFile, Map &map)
{
	for (int y = 0; y != SIZE_MAP - 1; ++y)
	{
		for (int x = 0; x != SIZE_MAP - 1; ++x)
		{
			if (map[y][x] == -1)
			{
				outputFile << '#';
			}
			else if (map[y][x] == 1)
			{
				outputFile << 'A';
			}
			else if (map[y][x] == -2)
			{
				outputFile << 'B';
			}
			else if(map[y][x] == -3)
			{
				outputFile << '.';
			}
			else
			{
				outputFile << ' ';
			}
		}
		outputFile << endl;
	}

}

void FillTheMapWithZeros(Map &map)
{
	for (int row = 0; row != SIZE_MAP - 1; ++row)
	{
		for (int colum = 0; colum != SIZE_MAP - 1; ++colum)
		{
			map[row][colum] = 0;
		}
	}
}

void DisseminationWave(Labirinth &labirinth, bool &wasPathFound)
{
	Wave oldWave, newWave;
	int valueWave = 1;
	oldWave.push_back(labirinth.startPoint);
	while (oldWave.size() > 0)
	{
		++valueWave;
		newWave.clear();
		for (Wave::iterator i = oldWave.begin(); i != oldWave.end(); ++i)
		{
			for (int d = 0; d != 4; ++d)
			{
				int dx = i->x + step[d].x;
				int dy = i->y + step[d].y;
				if ((dy == labirinth.finishPoint.y) && (dx == labirinth.finishPoint.x))
				{
					wasPathFound = true;
					labirinth.finishPoint = { i->y , i->x };
					return;
				}
				if (labirinth.map[dy][dx] == 0)
				{
					labirinth.map[dy][dx] = valueWave;
					newWave.push_back({ dy, dx });
				}
			}
		}
		oldWave = newWave;
	}
}

void RecoveryPath(Labirinth &labirinth)
{
	Point route = labirinth.finishPoint;
	while (labirinth.map[route.y][route.x] != 1)
	{
		for (int d = 0; d != 4; ++d)
		{
			int dx = route.x + step[d].x;
			int dy = route.y + step[d].y;
			if ((labirinth.map[route.y][route.x] - 1) == labirinth.map[dy][dx])
			{
				labirinth.map[route.y][route.x] = -3;
				route = { dy, dx };
				break;
			}
		}
	}
}

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
			PrintMap(outputFile, labirinth.map);
		}
		else
		{
			outputFile << "No path between points A and B!\n";
		}
	}


}
