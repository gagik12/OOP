#include "Wave_algorithm.h"

using namespace std;

void DisseminationWave(Labirinth &labirinth, bool &wasPathFound)
{
	Wave oldWave, newWave;
	int valueWave = 1;
	oldWave.push_back(labirinth.startPoint.get());
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
				if ((dy == labirinth.finishPoint.get().y) && (dx == labirinth.finishPoint.get().x))
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
	Point route = labirinth.finishPoint.get();
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