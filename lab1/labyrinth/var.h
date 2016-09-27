#pragma once

#include "stdafx.h"

static const int SIZE_MAP = 101;

typedef int Map[SIZE_MAP][SIZE_MAP];

struct Point
{
	int y, x;
};

typedef std::vector<Point> Wave;
typedef std::map<int, char> ComponentsMap;
static const Point step[4] = { { 0, -1 },{ 1, 0 },{ 0, 1 },{ -1, 0 } };

enum
{
	WALL = -1,
	START = 1,
	END = -2,
	PATH = -3,
};

struct Labirinth
{
	Map map;
	boost::optional<Point> startPoint;
	boost::optional<Point> finishPoint;

	ComponentsMap components = {
		{ WALL, '#' },
		{ START, 'A' },
		{ END, 'B' },
		{ PATH, '.' },
	};
};